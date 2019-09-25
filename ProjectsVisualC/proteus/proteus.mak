# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=proteus - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to proteus - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "proteus - Win32 Release" && "$(CFG)" !=\
 "proteus - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "proteus.mak" CFG="proteus - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "proteus - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "proteus - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "proteus - Win32 Release"

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

ALL : "$(OUTDIR)\proteus.exe" "$(OUTDIR)\proteus.hlp"

CLEAN : 
	-@erase ".\Release\proteus.exe"
	-@erase ".\Release\proteus.obj"
	-@erase ".\Release\proteus.pch"
	-@erase ".\Release\StdAfx.obj"
	-@erase ".\Release\MainFrm.obj"
	-@erase ".\Release\ChildFrm.obj"
	-@erase ".\Release\proteusDoc.obj"
	-@erase ".\Release\proteusView.obj"
	-@erase ".\Release\proteus.res"
	-@erase ".\Release\point3d.obj"
	-@erase ".\Release\proteus.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL"\
 /D "_MBCS" /Fp"$(INTDIR)/proteus.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/proteus.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/proteus.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/proteus.pdb" /machine:I386 /out:"$(OUTDIR)/proteus.exe" 
LINK32_OBJS= \
	"$(INTDIR)/proteus.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/ChildFrm.obj" \
	"$(INTDIR)/proteusDoc.obj" \
	"$(INTDIR)/proteusView.obj" \
	"$(INTDIR)/point3d.obj" \
	"$(INTDIR)/proteus.res"

"$(OUTDIR)\proteus.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "proteus - Win32 Debug"

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

ALL : "$(OUTDIR)\proteus.exe" "$(OUTDIR)\proteus.hlp" "$(OUTDIR)\proteus.bsc"

CLEAN : 
	-@erase ".\Debug\proteus.exe"
	-@erase ".\Debug\proteus.obj"
	-@erase ".\Debug\proteus.pch"
	-@erase ".\Debug\StdAfx.obj"
	-@erase ".\Debug\MainFrm.obj"
	-@erase ".\Debug\ChildFrm.obj"
	-@erase ".\Debug\proteusDoc.obj"
	-@erase ".\Debug\proteusView.obj"
	-@erase ".\Debug\proteus.res"
	-@erase ".\Debug\point3d.obj"
	-@erase ".\Debug\proteus.ilk"
	-@erase ".\Debug\proteus.pdb"
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\Debug\proteus.hlp"
	-@erase ".\Debug\proteus.bsc"
	-@erase ".\Debug\proteus.sbr"
	-@erase ".\Debug\StdAfx.sbr"
	-@erase ".\Debug\MainFrm.sbr"
	-@erase ".\Debug\ChildFrm.sbr"
	-@erase ".\Debug\proteusDoc.sbr"
	-@erase ".\Debug\proteusView.sbr"
	-@erase ".\Debug\point3d.sbr"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/proteus.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/proteus.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/proteus.bsc" 
BSC32_SBRS= \
	"$(INTDIR)/proteus.sbr" \
	"$(INTDIR)/StdAfx.sbr" \
	"$(INTDIR)/MainFrm.sbr" \
	"$(INTDIR)/ChildFrm.sbr" \
	"$(INTDIR)/proteusDoc.sbr" \
	"$(INTDIR)/proteusView.sbr" \
	"$(INTDIR)/point3d.sbr"

"$(OUTDIR)\proteus.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/proteus.pdb" /debug /machine:I386 /out:"$(OUTDIR)/proteus.exe" 
LINK32_OBJS= \
	"$(INTDIR)/proteus.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/ChildFrm.obj" \
	"$(INTDIR)/proteusDoc.obj" \
	"$(INTDIR)/proteusView.obj" \
	"$(INTDIR)/point3d.obj" \
	"$(INTDIR)/proteus.res"

"$(OUTDIR)\proteus.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "proteus - Win32 Release"
# Name "proteus - Win32 Debug"

!IF  "$(CFG)" == "proteus - Win32 Release"

!ELSEIF  "$(CFG)" == "proteus - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "proteus - Win32 Release"

!ELSEIF  "$(CFG)" == "proteus - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\proteus.cpp
DEP_CPP_PROTE=\
	".\StdAfx.h"\
	".\proteus.h"\
	".\MainFrm.h"\
	".\ChildFrm.h"\
	".\proteusDoc.h"\
	".\proteusView.h"\
	

!IF  "$(CFG)" == "proteus - Win32 Release"


"$(INTDIR)\proteus.obj" : $(SOURCE) $(DEP_CPP_PROTE) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ELSEIF  "$(CFG)" == "proteus - Win32 Debug"


"$(INTDIR)\proteus.obj" : $(SOURCE) $(DEP_CPP_PROTE) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"

"$(INTDIR)\proteus.sbr" : $(SOURCE) $(DEP_CPP_PROTE) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "proteus - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL"\
 /D "_MBCS" /Fp"$(INTDIR)/proteus.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c\
 $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\proteus.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "proteus - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/proteus.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\StdAfx.sbr" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\proteus.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\StdAfx.h"\
	".\proteus.h"\
	".\MainFrm.h"\
	

!IF  "$(CFG)" == "proteus - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ELSEIF  "$(CFG)" == "proteus - Win32 Debug"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"

"$(INTDIR)\MainFrm.sbr" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	".\StdAfx.h"\
	".\proteus.h"\
	".\ChildFrm.h"\
	

!IF  "$(CFG)" == "proteus - Win32 Release"


"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ELSEIF  "$(CFG)" == "proteus - Win32 Debug"


"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"

"$(INTDIR)\ChildFrm.sbr" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\proteusDoc.cpp
DEP_CPP_PROTEU=\
	".\StdAfx.h"\
	".\proteus.h"\
	".\proteusDoc.h"\
	

!IF  "$(CFG)" == "proteus - Win32 Release"


"$(INTDIR)\proteusDoc.obj" : $(SOURCE) $(DEP_CPP_PROTEU) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ELSEIF  "$(CFG)" == "proteus - Win32 Debug"


"$(INTDIR)\proteusDoc.obj" : $(SOURCE) $(DEP_CPP_PROTEU) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"

"$(INTDIR)\proteusDoc.sbr" : $(SOURCE) $(DEP_CPP_PROTEU) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\proteusView.cpp
DEP_CPP_PROTEUS=\
	".\StdAfx.h"\
	".\proteus.h"\
	".\proteusDoc.h"\
	".\proteusView.h"\
	

!IF  "$(CFG)" == "proteus - Win32 Release"


"$(INTDIR)\proteusView.obj" : $(SOURCE) $(DEP_CPP_PROTEUS) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ELSEIF  "$(CFG)" == "proteus - Win32 Debug"


"$(INTDIR)\proteusView.obj" : $(SOURCE) $(DEP_CPP_PROTEUS) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"

"$(INTDIR)\proteusView.sbr" : $(SOURCE) $(DEP_CPP_PROTEUS) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\proteus.rc
DEP_RSC_PROTEUS_=\
	".\res\proteus.ico"\
	".\res\proteusDoc.ico"\
	".\res\Toolbar.bmp"\
	".\res\proteus.rc2"\
	

"$(INTDIR)\proteus.res" : $(SOURCE) $(DEP_RSC_PROTEUS_) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\hlp\proteus.hpj

!IF  "$(CFG)" == "proteus - Win32 Release"

# Begin Custom Build - Making help file...
OutDir=.\Release
ProjDir=.
TargetName=proteus
InputPath=.\hlp\proteus.hpj

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   "$(ProjDir)\makehelp.bat"

# End Custom Build

!ELSEIF  "$(CFG)" == "proteus - Win32 Debug"

# Begin Custom Build - Making help file...
OutDir=.\Debug
ProjDir=.
TargetName=proteus
InputPath=.\hlp\proteus.hpj

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   "$(ProjDir)\makehelp.bat"

# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\point3d.cpp
DEP_CPP_POINT=\
	".\StdAfx.h"\
	".\proteus.h"\
	".\point3d.h"\
	

!IF  "$(CFG)" == "proteus - Win32 Release"


"$(INTDIR)\point3d.obj" : $(SOURCE) $(DEP_CPP_POINT) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ELSEIF  "$(CFG)" == "proteus - Win32 Debug"


"$(INTDIR)\point3d.obj" : $(SOURCE) $(DEP_CPP_POINT) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"

"$(INTDIR)\point3d.sbr" : $(SOURCE) $(DEP_CPP_POINT) "$(INTDIR)"\
 "$(INTDIR)\proteus.pch"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
