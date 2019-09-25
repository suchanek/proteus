/* ASyncIO.c - Execute me to compile with SAS/C 5.10b
lc -cfist -v -j73 asyncio.c
quit
*/

/*
(c)  Copyright 1992 Commodore-Amiga, Inc.   All rights reserved.
The information contained herein is subject to change without notice,
and is provided "as is" without warranty of any kind, either expressed
or implied.  The entire risk as to the use of this information is
assumed by the user.
*/

#include <proto/all.h>
#include <exec/types.h>
#include <exec/exec.h>
#include <dos/dos.h>
#include <dos/dosextens.h>
#include <stdio.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>

#include "asyncio.h"

#define D_S(type,name) char a_##name[sizeof(type)+3]; \
                       type *name = (type *)((LONG)(a_##name+3) & ~3);

static char rcsid[] = "$Id: asyncio.c 1.1 1994/12/14 02:22:02 eric Exp $";

/*****************************************************************************/
/* send out an async packet to the file system. */

static VOID SendPacket(struct AsyncFile *file, APTR arg2)
{

    file->af_Packet.sp_Pkt.dp_Port = &file->af_PacketPort;
    file->af_Packet.sp_Pkt.dp_Arg2 = (LONG)arg2;
    PutMsg(file->af_Handler, &file->af_Packet.sp_Msg);
    file->af_PacketPending = TRUE;
}

/*****************************************************************************/


static LONG WaitPacket(struct AsyncFile *file)
{
  LONG bytes;

  if (file->af_PacketPending)
    {
      file->af_PacketPending = FALSE;
      while (TRUE)
	{
	  file->af_PacketPort.mp_Flags = PA_SIGNAL;
	  Remove((struct Node *)WaitPort(&file->af_PacketPort));
	  file->af_PacketPort.mp_Flags = PA_IGNORE;

	  bytes = file->af_Packet.sp_Pkt.dp_Res1;
	  if (bytes >= 0)
	    {
	      return(bytes);
	    }
	  
	  if (ErrorReport(file->af_Packet.sp_Pkt.dp_Res2, REPORT_STREAM,
			  file->af_File, NULL))
	    return(-1);

	  SendPacket(file, file->af_Buffers[file->af_CurrentBuf]);
	}
    }

  SetIoErr(file->af_Packet.sp_Pkt.dp_Res2);

  return(file->af_Packet.sp_Pkt.dp_Res1);
	  
}

VOID RequeuePacket(struct AsyncFile *file)
{
  AddHead(&file->af_PacketPort.mp_MsgList, &file->af_Packet.sp_Msg.mn_Node);
}

VOID RecordSyncFailure(struct AsyncFile *file)
{
  file->af_Packet.sp_Pkt.dp_Res1 = -1;
  file->af_Packet.sp_Pkt.dp_Res2 = IoErr();
}


/*****************************************************************************/

struct AsyncFile *OpenAsync(const STRPTR fileName, UBYTE accessMode, 
			    LONG bufferSize)
{
  struct AsyncFile  *file;
  struct FileHandle *fh;

  BPTR handle;
  BPTR lock;
  LONG blockSize;
  
  D_S(struct InfoData, infoData);

  handle = NULL;
  file = NULL;
  lock = NULL;

  if (accessMode == MODE_READ)
    {
      if (handle = Open(fileName, MODE_OLDFILE))
	lock = DupLockFromFH(handle);
    }
  else
    {
      if (accessMode == MODE_WRITE)
	{
	  handle = Open(fileName, MODE_NEWFILE);
	}
      else if (accessMode == MODE_APPEND)
	{
	  if (handle = Open(fileName, MODE_READWRITE))
	    {
	      if (Seek(handle, 0, OFFSET_END) < 0)
		{
		  Close(handle);
		  handle = NULL;
		}
	    }
	}

      if (handle)
	lock = ParentOfFH(handle);
    }

  if (handle)
    {
      blockSize = 512;
      if (lock)
	{
	  if (Info(lock, infoData))
	    {
	      blockSize = infoData->id_BytesPerBlock;
	      bufferSize = 
		(((bufferSize + blockSize - 1) / blockSize) * blockSize) * 2;
	    }
	  UnLock(lock);
	}

      if (file = AllocVec(sizeof(struct AsyncFile) + bufferSize + 15, MEMF_ANY))
	{
	  file->af_File = handle;
	  file->af_ReadMode = (accessMode == MODE_READ);
	  file->af_BlockSize = blockSize;

	  /* initialize the ASyncFile structure. We do as much as we can here,
	   * in order to avoid doing it in more critical sections
	   *
	   * Note how the two buffers used are quad-longword aligned. This helps
	   * performance on 68040 systems with copyback cache. Aligning the data
	   * avoids a nasty side-effect of the 040 caches on DMA. Not aligning
	   * the data causes the device driver to have to do some magic to avoid
	   * the cache problem. This magic will generally involve flushing the
	   * CPU caches. This is very costly on an 040. Aligning things avoids
	   * the need for magic, at the cost of at most 15 bytes of ram.
	   */
	  
	  fh                  = BADDR(file->af_File);
	  file->af_Handler    = fh->fh_Type;
	  file->af_BufferSize = bufferSize / 2;
	  file->af_Buffers[0] =
	    (APTR)(((ULONG)file + sizeof(struct AsyncFile) + 15) & 0xfffffff0);
	  file->af_Buffers[1] =
	    (APTR)((ULONG)file->af_Buffers[0] + file->af_BufferSize);
	  file->af_Offset     = file->af_Buffers[0];
	  file->af_CurrentBuf = 0;
	  file->af_SeekOffset = 0;
	  file->af_PacketPending = FALSE;

	  /* this is the port used to get the packets we send out back.
	   * It is initialized to PA_IGNORE, which means that no signal is
	   * generated when a message comes in to the port. The signal bit number
	   * is initialized to SIGB_SINGLE, which is the special bit that can
	   * be used for one-shot signalling. The signal will never be set,
	   * since the port is of type PA_IGNORE. We'll change the type of the
	   * port later on to PA_SIGNAL whenever we need to wait for a message
	   * to come in.
	   *
	   * The trick used here avoids the need to allocate an extra signal bit
	   * for the port. It is quite efficient.
	   */
	  
	  file->af_PacketPort.mp_MsgList.lh_Head     =
	    (struct Node *)&file->af_PacketPort.mp_MsgList.lh_Tail;
	  file->af_PacketPort.mp_MsgList.lh_Tail     = NULL;
	  file->af_PacketPort.mp_MsgList.lh_TailPred =
	    (struct Node *)&file->af_PacketPort.mp_MsgList.lh_Head;
	  file->af_PacketPort.mp_Node.ln_Type        = NT_MSGPORT;
	  file->af_PacketPort.mp_Flags               = PA_IGNORE;
	  file->af_PacketPort.mp_SigBit              = SIGB_SINGLE;
	  file->af_PacketPort.mp_SigTask             = FindTask(NULL);
	  
	  file->af_Packet.sp_Pkt.dp_Link          = &file->af_Packet.sp_Msg;
	  file->af_Packet.sp_Pkt.dp_Arg1          = fh->fh_Arg1;
	  file->af_Packet.sp_Pkt.dp_Arg3          = file->af_BufferSize;
	  file->af_Packet.sp_Pkt.dp_Res1          = 0;
	  file->af_Packet.sp_Pkt.dp_Res2          = 0;
	  file->af_Packet.sp_Msg.mn_Node.ln_Name  = (STRPTR)&file->af_Packet.sp_Pkt;
	  file->af_Packet.sp_Msg.mn_Node.ln_Type  = NT_MESSAGE;
	  file->af_Packet.sp_Msg.mn_Length        = sizeof(struct StandardPacket);
	  
	  if (accessMode == MODE_READ)
	    {
	      /* if we are in read mode, send out the first read packet to the
	       * file system. While the application is getting ready to read
	       * data, the file system will happily fill in this buffer with
	       * DMA transfer, so that by the time the application needs the data,
	       * it will be in the buffer waiting
	       */
	      
	      file->af_Packet.sp_Pkt.dp_Type = ACTION_READ;
	      file->af_BytesLeft             = 0;
	      if (file->af_Handler)
                SendPacket(file,file->af_Buffers[0]);
	    }
	  else
	    {
	      file->af_Packet.sp_Pkt.dp_Type = ACTION_WRITE;
	      file->af_BytesLeft             = file->af_BufferSize;
	    }
	}
      else
	{
	  Close(handle);
	}
    }
      
  return(file);
}
  
  /*****************************************************************************/
  
LONG CloseAsync(struct AsyncFile *file)
{
  LONG result;
      
  if (file)
    {
      result = WaitPacket(file);
      
      if (result >= 0)
	{
	  if (!file->af_ReadMode)
	    {
	      /* this will flush out any pending data in the write buffer */
	      result  = Write(file->af_File,
			      file->af_Buffers[file->af_CurrentBuf],
			      file->af_BufferSize - file->af_BytesLeft);
	    }
	}
	  
      Close(file->af_File);
      FreeVec(file);
    }
  else
    {
      SetIoErr(ERROR_INVALID_LOCK);
      result = -1;
    }
  
  return(result);
}
  
/*****************************************************************************/
  
LONG ReadAsync(struct AsyncFile *file, APTR buffer, LONG numBytes)
{
  LONG totalBytes;
  LONG bytesArrived;
  
  totalBytes = 0;
  
  /* if we need more bytes than there are in the current buffer, enter the
   * read loop
   */
  
  while (numBytes > file->af_BytesLeft)
    {
      /* drain buffer */
      CopyMem(file->af_Offset, buffer, file->af_BytesLeft);

      numBytes           -= file->af_BytesLeft;
      buffer              = (APTR)((ULONG)buffer + file->af_BytesLeft);
      totalBytes         += file->af_BytesLeft;
      file->af_BytesLeft  = 0;

      bytesArrived = WaitPacket(file);
      
      if (bytesArrived <= 0)
	{
	  if (bytesArrived == 0)
	    return(totalBytes);

	  return(-1);
	}

      /* ask that the buffer be filled */

      SendPacket(file, file->af_Buffers[1-file->af_CurrentBuf]);

      if (file->af_SeekOffset > bytesArrived)
	file->af_SeekOffset = bytesArrived;

      file->af_Offset = (APTR)((ULONG)file->af_Buffers[file->af_CurrentBuf] +
			       file->af_SeekOffset);
      file->af_CurrentBuf = 1 - file->af_CurrentBuf;
      file->af_BytesLeft = bytesArrived - file->af_SeekOffset;
    }
      
      CopyMem(file->af_Offset,buffer,numBytes);
      file->af_BytesLeft -= numBytes;
      file->af_Offset     = (APTR)((ULONG)file->af_Offset + numBytes);
  
  return (totalBytes + numBytes);
}

/*****************************************************************************/

LONG ReadCharAsync(struct AsyncFile *file)
{
  unsigned char ch;
  
  if (file->af_BytesLeft)
    {
      /* if there is at least a byte left in the current buffer, get it
       * directly. Also update all counters
       */
      
      ch = *(char *)file->af_Offset;
      file->af_BytesLeft--;
      file->af_Offset = (APTR)((ULONG)file->af_Offset + 1);
      
      return((LONG)ch);
    }
  
  /* there were no characters in the current buffer, so call the main read
   * routine. This has the effect of sending a request to the file system to
   * have the current buffer refilled. After that request is done, the
   * character is extracted for the alternate buffer, which at that point
   * becomes the "current" buffer
   */
  
  if (ReadAsync(file,&ch,1) > 0)
    return((LONG)ch);
  
  /* We couldn't read above, so fail */
  
  return(-1);
}

/*****************************************************************************/

LONG WriteAsync(struct AsyncFile *file, APTR buffer, LONG numBytes)
{
  LONG totalBytes;
  
  totalBytes = 0;
  
  while (numBytes > file->af_BytesLeft)
    {
      /* this takes care of NIL: */
      if (!file->af_Handler)
	{
	  file->af_Offset    = file->af_Buffers[0];
	  file->af_BytesLeft = file->af_BufferSize;
	  return(numBytes);
	}
      
      if (file->af_BytesLeft)
	{
	  CopyMem(buffer,file->af_Offset, file->af_BytesLeft);
	  
	  numBytes   -= file->af_BytesLeft;
	  buffer         = (APTR)((ULONG)buffer + file->af_BytesLeft);
	  totalBytes += file->af_BytesLeft;
	}
      
      if (WaitPacket(file) < 0)
	return(-1);
      
      /* send the current buffer out to disk */
      SendPacket(file,file->af_Buffers[file->af_CurrentBuf]);
      
      file->af_CurrentBuf   = 1 - file->af_CurrentBuf;
      file->af_Offset       = file->af_Buffers[file->af_CurrentBuf];
      file->af_BytesLeft    = file->af_BufferSize;
    }
  
  CopyMem(buffer,file->af_Offset,numBytes);
  file->af_BytesLeft -= numBytes;
  file->af_Offset     = (APTR)((ULONG)file->af_Offset + numBytes);
  
  return (totalBytes + numBytes);
}

/*****************************************************************************/

LONG WriteCharAsync(struct AsyncFile *file, UBYTE ch)
{
  if (file->af_BytesLeft)
    {
      /* if there's any room left in the current buffer, directly write
       * the byte into it, updating counters and stuff.
       */
      
      *(UBYTE *)file->af_Offset = ch;
      file->af_BytesLeft--;
      file->af_Offset = (APTR)((ULONG)file->af_Offset + 1);
      
      /* one byte written */
      return(1);
    }
  
  /* there was no room in the current buffer, so call the main write
   * routine. This will effectively send the current buffer out to disk,
   * wait for the other buffer to come back, and then put the byte into
   * it.
   */
  
  return(WriteAsync(file,&ch,1));
}
  

LONG SeekAsync(struct AsyncFile *file, LONG position, BYTE mode)
{
  LONG current, target;
  LONG minBuf, maxBuf;
  LONG bytesArrived;
  LONG diff;
  LONG filePos;
  LONG roundTarget;

  D_S(struct FileInfoBlock, fib);
  
  bytesArrived = WaitPacket(file);

  if (bytesArrived < 0)
    return(-1);

  if (file->af_ReadMode)
    {
      filePos = Seek(file->af_File, OFFSET_CURRENT, 0);
      if (filePos < 0)
	{
	  RecordSyncFailure(file);
	  return(-1);
	}

      current = filePos - (file->af_BytesLeft+bytesArrived);

      if (mode == MODE_CURRENT)
	{
	  target = current + position;
	}
      else if (mode == MODE_START)
	{
	  target = position;
	}
      else
	{
	  if (!ExamineFH(file->af_File, fib))
	    {
	      RecordSyncFailure(file);
	      return(-1);
	    }
	  target = fib->fib_Size + position;
	}

      minBuf = current - (LONG)((ULONG)file->af_Offset - 
				(ULONG)file->af_Buffers[1 - file->af_CurrentBuf]);
      maxBuf = current + file->af_BytesLeft + bytesArrived; /* WARNING: this is one too big */

      diff = target - current;

      if ((target < minBuf) || (target >= maxBuf))
	{
	  roundTarget = (target / file->af_BlockSize) * file->af_BlockSize;

	  if (Seek(file->af_File, roundTarget - filePos, OFFSET_CURRENT) < 0)
	    {
	      RecordSyncFailure(file);
	      return(-1);
	    }

	  SendPacket(file, file->af_Buffers[0]);

	  file->af_SeekOffset = target-roundTarget;
	  file->af_BytesLeft = 0;
	  file->af_CurrentBuf = 0;
	}
      else if ((target < current) || (diff <= file->af_BytesLeft))
	{
	  RequeuePacket(file);

	  file->af_BytesLeft -= diff;
	  file->af_Offset = (APTR)((ULONG)file->af_Offset + diff);
	}
      else
	{
	  diff -= file->af_BytesLeft;

	  SendPacket(file, file->af_Buffers[1-file->af_CurrentBuf]);

	  file->af_Offset = 
	    (APTR)((ULONG)file->af_Buffers[file->af_CurrentBuf] + diff);
	  file->af_CurrentBuf = 1 - file->af_CurrentBuf;
	  file->af_BytesLeft = bytesArrived - diff;
	}
    }
  else
    {
      if (Write(file->af_File,
		file->af_Buffers[file->af_CurrentBuf],
		file->af_BufferSize - file->af_BytesLeft) < 0)
	{
	  RecordSyncFailure(file);
	  return(-1);
	}

      current = Seek(file->af_File, position, mode);

      if (current < 0)
	{
	  RecordSyncFailure(file);
	  return(-1);
	}
      
      file->af_BytesLeft = file->af_BufferSize;
      file->af_CurrentBuf = 0;
    }

  return(current);

}


