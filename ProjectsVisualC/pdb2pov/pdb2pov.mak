# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

!IF "$(CFG)" == ""
CFG=pdb2pov - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to pdb2pov - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "pdb2pov - Win32 Release" && "$(CFG)" !=\
 "pdb2pov - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "pdb2pov.mak" CFG="pdb2pov - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "pdb2pov - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "pdb2pov - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "pdb2pov - Win32 Debug"
RSC=rc.exe
CPP=cl.exe

!IF  "$(CFG)" == "pdb2pov - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\pdb2pov.exe" "$(OUTDIR)\pdb2pov.bsc"

CLEAN : 
	-@erase ".\Release\pdb2pov.bsc"
	-@erase ".\Release\pdb2pov_type.sbr"
	-@erase ".\Release\pdb2pov_bonds.sbr"
	-@erase ".\Release\pdb2pov_mol.sbr"
	-@erase ".\Release\matrix.sbr"
	-@erase ".\Release\util.sbr"
	-@erase ".\Release\pdb2pov_output.sbr"
	-@erase ".\Release\pdb2pov.sbr"
	-@erase ".\Release\pdb2povio.sbr"
	-@erase ".\Release\pdb2pov.exe"
	-@erase ".\Release\pdb2pov_output.obj"
	-@erase ".\Release\pdb2pov.obj"
	-@erase ".\Release\pdb2povio.obj"
	-@erase ".\Release\pdb2pov_type.obj"
	-@erase ".\Release\pdb2pov_bonds.obj"
	-@erase ".\Release\pdb2pov_mol.obj"
	-@erase ".\Release\matrix.obj"
	-@erase ".\Release\util.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /GX /D "NDEBUG" /D "WIN32" /D "_CONSOLE DOS" /FR /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /D "NDEBUG" /D "WIN32" /D "_CONSOLE DOS"\
 /FR"$(INTDIR)/" /Fp"$(INTDIR)/pdb2pov.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\Release/
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/pdb2pov.bsc" 
BSC32_SBRS= \
	"$(INTDIR)/pdb2pov_type.sbr" \
	"$(INTDIR)/pdb2pov_bonds.sbr" \
	"$(INTDIR)/pdb2pov_mol.sbr" \
	"$(INTDIR)/matrix.sbr" \
	"$(INTDIR)/util.sbr" \
	"$(INTDIR)/pdb2pov_output.sbr" \
	"$(INTDIR)/pdb2pov.sbr" \
	"$(INTDIR)/pdb2povio.sbr"

"$(OUTDIR)\pdb2pov.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)/pdb2pov.pdb" /machine:I386 /out:"$(OUTDIR)/pdb2pov.exe" 
LINK32_OBJS= \
	"$(INTDIR)/pdb2pov_output.obj" \
	"$(INTDIR)/pdb2pov.obj" \
	"$(INTDIR)/pdb2povio.obj" \
	"$(INTDIR)/pdb2pov_type.obj" \
	"$(INTDIR)/pdb2pov_bonds.obj" \
	"$(INTDIR)/pdb2pov_mol.obj" \
	"$(INTDIR)/matrix.obj" \
	"$(INTDIR)/util.obj"

"$(OUTDIR)\pdb2pov.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "pdb2pov - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\pdb2pov.exe" "$(OUTDIR)\pdb2pov.bsc"

CLEAN : 
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\Debug\pdb2pov.bsc"
	-@erase ".\Debug\util.sbr"
	-@erase ".\Debug\pdb2pov.sbr"
	-@erase ".\Debug\pdb2povio.sbr"
	-@erase ".\Debug\pdb2pov_type.sbr"
	-@erase ".\Debug\pdb2pov_bonds.sbr"
	-@erase ".\Debug\matrix.sbr"
	-@erase ".\Debug\pdb2pov_output.sbr"
	-@erase ".\Debug\pdb2pov_mol.sbr"
	-@erase ".\Debug\pdb2pov.exe"
	-@erase ".\Debug\pdb2pov_mol.obj"
	-@erase ".\Debug\util.obj"
	-@erase ".\Debug\pdb2pov.obj"
	-@erase ".\Debug\pdb2povio.obj"
	-@erase ".\Debug\pdb2pov_type.obj"
	-@erase ".\Debug\pdb2pov_bonds.obj"
	-@erase ".\Debug\matrix.obj"
	-@erase ".\Debug\pdb2pov_output.obj"
	-@erase ".\Debug\pdb2pov.ilk"
	-@erase ".\Debug\pdb2pov.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_CONSOLE DOS" /FR /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_CONSOLE DOS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/pdb2pov.pch" /YX /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/pdb2pov.bsc" 
BSC32_SBRS= \
	"$(INTDIR)/util.sbr" \
	"$(INTDIR)/pdb2pov.sbr" \
	"$(INTDIR)/pdb2povio.sbr" \
	"$(INTDIR)/pdb2pov_type.sbr" \
	"$(INTDIR)/pdb2pov_bonds.sbr" \
	"$(INTDIR)/matrix.sbr" \
	"$(INTDIR)/pdb2pov_output.sbr" \
	"$(INTDIR)/pdb2pov_mol.sbr"

"$(OUTDIR)\pdb2pov.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/pdb2pov.pdb" /debug /machine:I386 /out:"$(OUTDIR)/pdb2pov.exe" 
LINK32_OBJS= \
	"$(INTDIR)/pdb2pov_mol.obj" \
	"$(INTDIR)/util.obj" \
	"$(INTDIR)/pdb2pov.obj" \
	"$(INTDIR)/pdb2povio.obj" \
	"$(INTDIR)/pdb2pov_type.obj" \
	"$(INTDIR)/pdb2pov_bonds.obj" \
	"$(INTDIR)/matrix.obj" \
	"$(INTDIR)/pdb2pov_output.obj"

"$(OUTDIR)\pdb2pov.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "pdb2pov - Win32 Release"
# Name "pdb2pov - Win32 Debug"

!IF  "$(CFG)" == "pdb2pov - Win32 Release"

!ELSEIF  "$(CFG)" == "pdb2pov - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\util.proto.h

!IF  "$(CFG)" == "pdb2pov - Win32 Release"

!ELSEIF  "$(CFG)" == "pdb2pov - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\pdb2pov.c

!IF  "$(CFG)" == "pdb2pov - Win32 Release"

DEP_CPP_PDB2P=\
	".\pdb2pov.h"\
	".\pdb2pov_errors.h"\
	".\pdb2pov_usage.h"\
	

"$(INTDIR)\pdb2pov.obj" : $(SOURCE) $(DEP_CPP_PDB2P) "$(INTDIR)"

"$(INTDIR)\pdb2pov.sbr" : $(SOURCE) $(DEP_CPP_PDB2P) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "pdb2pov - Win32 Debug"

DEP_CPP_PDB2P=\
	".\pdb2pov.h"\
	".\pdb2pov_errors.h"\
	".\pdb2pov_usage.h"\
	".\util.proto.h"\
	".\pdb2pov.proto.h"\
	
NODEP_CPP_PDB2P=\
	".\asyncio.h"\
	".\asyncio_protos.h"\
	".\pdb2pov_protos.h"\
	

"$(INTDIR)\pdb2pov.obj" : $(SOURCE) $(DEP_CPP_PDB2P) "$(INTDIR)"

"$(INTDIR)\pdb2pov.sbr" : $(SOURCE) $(DEP_CPP_PDB2P) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\pdb2pov.proto.h

!IF  "$(CFG)" == "pdb2pov - Win32 Release"

!ELSEIF  "$(CFG)" == "pdb2pov - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\pdb2pov_errors.h

!IF  "$(CFG)" == "pdb2pov - Win32 Release"

!ELSEIF  "$(CFG)" == "pdb2pov - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\pdb2pov_usage.h

!IF  "$(CFG)" == "pdb2pov - Win32 Release"

!ELSEIF  "$(CFG)" == "pdb2pov - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\util.c
DEP_CPP_UTIL_=\
	".\util.proto.h"\
	

"$(INTDIR)\util.obj" : $(SOURCE) $(DEP_CPP_UTIL_) "$(INTDIR)"

"$(INTDIR)\util.sbr" : $(SOURCE) $(DEP_CPP_UTIL_) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\pdb2pov.h

!IF  "$(CFG)" == "pdb2pov - Win32 Release"

!ELSEIF  "$(CFG)" == "pdb2pov - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\pdb2povio.c
DEP_CPP_PDB2PO=\
	".\pdb2pov.h"\
	".\pdb2pov_errors.h"\
	".\util.proto.h"\
	".\pdb2pov.proto.h"\
	
NODEP_CPP_PDB2PO=\
	".\asyncio.h"\
	".\asyncio_protos.h"\
	".\pdb2pov_protos.h"\
	

"$(INTDIR)\pdb2povio.obj" : $(SOURCE) $(DEP_CPP_PDB2PO) "$(INTDIR)"

"$(INTDIR)\pdb2povio.sbr" : $(SOURCE) $(DEP_CPP_PDB2PO) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\matrix.c
DEP_CPP_MATRI=\
	".\pdb2pov.h"\
	".\util.proto.h"\
	".\pdb2pov.proto.h"\
	".\pdb2pov_errors.h"\
	
NODEP_CPP_MATRI=\
	".\asyncio.h"\
	".\asyncio_protos.h"\
	".\pdb2pov_protos.h"\
	

"$(INTDIR)\matrix.obj" : $(SOURCE) $(DEP_CPP_MATRI) "$(INTDIR)"

"$(INTDIR)\matrix.sbr" : $(SOURCE) $(DEP_CPP_MATRI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\pdb2pov_output.c
DEP_CPP_PDB2POV=\
	".\pdb2pov.h"\
	".\util.proto.h"\
	".\pdb2pov.proto.h"\
	".\pdb2pov_errors.h"\
	
NODEP_CPP_PDB2POV=\
	".\asyncio.h"\
	".\asyncio_protos.h"\
	".\pdb2pov_protos.h"\
	

"$(INTDIR)\pdb2pov_output.obj" : $(SOURCE) $(DEP_CPP_PDB2POV) "$(INTDIR)"

"$(INTDIR)\pdb2pov_output.sbr" : $(SOURCE) $(DEP_CPP_PDB2POV) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\pdb2pov_mol.c
DEP_CPP_PDB2POV_=\
	".\pdb2pov.h"\
	".\util.proto.h"\
	".\pdb2pov.proto.h"\
	".\pdb2pov_errors.h"\
	
NODEP_CPP_PDB2POV_=\
	".\asyncio.h"\
	".\asyncio_protos.h"\
	".\pdb2pov_protos.h"\
	

"$(INTDIR)\pdb2pov_mol.obj" : $(SOURCE) $(DEP_CPP_PDB2POV_) "$(INTDIR)"

"$(INTDIR)\pdb2pov_mol.sbr" : $(SOURCE) $(DEP_CPP_PDB2POV_) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\pdb2pov_type.c
DEP_CPP_PDB2POV_T=\
	".\pdb2pov.h"\
	".\util.proto.h"\
	".\pdb2pov.proto.h"\
	".\pdb2pov_errors.h"\
	
NODEP_CPP_PDB2POV_T=\
	".\asyncio.h"\
	".\asyncio_protos.h"\
	".\pdb2pov_protos.h"\
	

"$(INTDIR)\pdb2pov_type.obj" : $(SOURCE) $(DEP_CPP_PDB2POV_T) "$(INTDIR)"

"$(INTDIR)\pdb2pov_type.sbr" : $(SOURCE) $(DEP_CPP_PDB2POV_T) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\pdb2pov_bonds.c
DEP_CPP_PDB2POV_B=\
	".\pdb2pov.h"\
	".\util.proto.h"\
	".\pdb2pov.proto.h"\
	".\pdb2pov_errors.h"\
	
NODEP_CPP_PDB2POV_B=\
	".\asyncio.h"\
	".\asyncio_protos.h"\
	".\pdb2pov_protos.h"\
	

"$(INTDIR)\pdb2pov_bonds.obj" : $(SOURCE) $(DEP_CPP_PDB2POV_B) "$(INTDIR)"

"$(INTDIR)\pdb2pov_bonds.sbr" : $(SOURCE) $(DEP_CPP_PDB2POV_B) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
