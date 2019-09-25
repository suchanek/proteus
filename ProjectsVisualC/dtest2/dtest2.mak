# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=dtest2 - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to dtest2 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "dtest2 - Win32 Release" && "$(CFG)" != "dtest2 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "dtest2.mak" CFG="dtest2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dtest2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "dtest2 - Win32 Debug" (based on "Win32 (x86) Application")
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
RSC=rc.exe
CPP=cl.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "dtest2 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\dtest2.exe"

CLEAN : 
	-@erase ".\Release\dtest2.exe"
	-@erase ".\Release\dtest2.obj"
	-@erase ".\Release\dtest2.pch"
	-@erase ".\Release\StdAfx.obj"
	-@erase ".\Release\MainFrm.obj"
	-@erase ".\Release\dtest2Doc.obj"
	-@erase ".\Release\dtest2View.obj"
	-@erase ".\Release\dtest2.res"
	-@erase ".\Release\DlgSettings.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL"\
 /D "_MBCS" /Fp"$(INTDIR)/dtest2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/dtest2.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/dtest2.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/dtest2.pdb" /machine:I386 /out:"$(OUTDIR)/dtest2.exe" 
LINK32_OBJS= \
	".\Release\dtest2.obj" \
	".\Release\StdAfx.obj" \
	".\Release\MainFrm.obj" \
	".\Release\dtest2Doc.obj" \
	".\Release\dtest2View.obj" \
	".\Release\DlgSettings.obj" \
	".\Release\dtest2.res"

"$(OUTDIR)\dtest2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "dtest2 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\dtest2.exe"

CLEAN : 
	-@erase ".\Debug\dtest2.exe"
	-@erase ".\Debug\dtest2.obj"
	-@erase ".\Debug\dtest2.pch"
	-@erase ".\Debug\StdAfx.obj"
	-@erase ".\Debug\MainFrm.obj"
	-@erase ".\Debug\dtest2Doc.obj"
	-@erase ".\Debug\dtest2View.obj"
	-@erase ".\Debug\dtest2.res"
	-@erase ".\Debug\DlgSettings.obj"
	-@erase ".\Debug\dtest2.ilk"
	-@erase ".\Debug\dtest2.pdb"
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\vc40.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/dtest2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/dtest2.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/dtest2.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/dtest2.pdb" /debug /machine:I386 /out:"$(OUTDIR)/dtest2.exe" 
LINK32_OBJS= \
	".\Debug\dtest2.obj" \
	".\Debug\StdAfx.obj" \
	".\Debug\MainFrm.obj" \
	".\Debug\dtest2Doc.obj" \
	".\Debug\dtest2View.obj" \
	".\Debug\DlgSettings.obj" \
	".\Debug\dtest2.res"

"$(OUTDIR)\dtest2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "dtest2 - Win32 Release"
# Name "dtest2 - Win32 Debug"

!IF  "$(CFG)" == "dtest2 - Win32 Release"

!ELSEIF  "$(CFG)" == "dtest2 - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "dtest2 - Win32 Release"

!ELSEIF  "$(CFG)" == "dtest2 - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\dtest2.cpp
DEP_CPP_DTEST=\
	".\StdAfx.h"\
	".\dtest2.h"\
	".\MainFrm.h"\
	".\dtest2Doc.h"\
	".\dtest2View.h"\
	

"$(INTDIR)\dtest2.obj" : $(SOURCE) $(DEP_CPP_DTEST) "$(INTDIR)"\
 "$(INTDIR)\dtest2.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "dtest2 - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL"\
 /D "_MBCS" /Fp"$(INTDIR)/dtest2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\dtest2.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "dtest2 - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/dtest2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\dtest2.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\StdAfx.h"\
	".\dtest2.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\dtest2.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\dtest2Doc.cpp
DEP_CPP_DTEST2=\
	".\StdAfx.h"\
	".\dtest2.h"\
	".\dtest2Doc.h"\
	

"$(INTDIR)\dtest2Doc.obj" : $(SOURCE) $(DEP_CPP_DTEST2) "$(INTDIR)"\
 "$(INTDIR)\dtest2.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\dtest2View.cpp
DEP_CPP_DTEST2V=\
	".\StdAfx.h"\
	".\dtest2.h"\
	".\dtest2Doc.h"\
	".\dtest2View.h"\
	

"$(INTDIR)\dtest2View.obj" : $(SOURCE) $(DEP_CPP_DTEST2V) "$(INTDIR)"\
 "$(INTDIR)\dtest2.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\dtest2.rc
DEP_RSC_DTEST2_=\
	".\res\dtest2.ico"\
	".\res\dtest2Doc.ico"\
	".\res\Toolbar.bmp"\
	".\res\dtest2.rc2"\
	

"$(INTDIR)\dtest2.res" : $(SOURCE) $(DEP_RSC_DTEST2_) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DlgSettings.cpp
DEP_CPP_DLGSE=\
	".\StdAfx.h"\
	".\dtest2.h"\
	".\DlgSettings.h"\
	

"$(INTDIR)\DlgSettings.obj" : $(SOURCE) $(DEP_CPP_DLGSE) "$(INTDIR)"\
 "$(INTDIR)\dtest2.pch"


# End Source File
# End Target
# End Project
################################################################################
