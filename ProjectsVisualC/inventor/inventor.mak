# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=inventor - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to inventor - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "inventor - Win32 Release" && "$(CFG)" !=\
 "inventor - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "inventor.mak" CFG="inventor - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "inventor - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "inventor - Win32 Debug" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "inventor - Win32 Debug"
RSC=rc.exe
CPP=cl.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "inventor - Win32 Release"

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

ALL : "$(OUTDIR)\inventor.exe"

CLEAN : 
	-@erase ".\Release\inventor.exe"
	-@erase ".\Release\MainFrm.obj"
	-@erase ".\Release\inventor.pch"
	-@erase ".\Release\inventorView.obj"
	-@erase ".\Release\inventor.obj"
	-@erase ".\Release\inventorDoc.obj"
	-@erase ".\Release\StdAfx.obj"
	-@erase ".\Release\ChildFrm.obj"
	-@erase ".\Release\inventor.res"
	-@erase ".\Release\myclass.obj"
	-@erase ".\Release\v3space1.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL"\
 /D "_MBCS" /Fp"$(INTDIR)/inventor.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/inventor.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/inventor.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/inventor.pdb" /machine:I386 /out:"$(OUTDIR)/inventor.exe" 
LINK32_OBJS= \
	".\Release\MainFrm.obj" \
	".\Release\inventorView.obj" \
	".\Release\inventor.obj" \
	".\Release\inventorDoc.obj" \
	".\Release\StdAfx.obj" \
	".\Release\ChildFrm.obj" \
	".\Release\myclass.obj" \
	".\Release\v3space1.obj" \
	".\Release\inventor.res"

"$(OUTDIR)\inventor.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "inventor - Win32 Debug"

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

ALL : "$(OUTDIR)\inventor.exe"

CLEAN : 
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\inventor.pch"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\Debug\inventor.exe"
	-@erase ".\Debug\MainFrm.obj"
	-@erase ".\Debug\inventor.obj"
	-@erase ".\Debug\ChildFrm.obj"
	-@erase ".\Debug\inventorView.obj"
	-@erase ".\Debug\StdAfx.obj"
	-@erase ".\Debug\inventorDoc.obj"
	-@erase ".\Debug\inventor.res"
	-@erase ".\Debug\myclass.obj"
	-@erase ".\Debug\v3space1.obj"
	-@erase ".\Debug\inventor.ilk"
	-@erase ".\Debug\inventor.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/inventor.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/inventor.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/inventor.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/inventor.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/inventor.exe" 
LINK32_OBJS= \
	".\Debug\MainFrm.obj" \
	".\Debug\inventor.obj" \
	".\Debug\ChildFrm.obj" \
	".\Debug\inventorView.obj" \
	".\Debug\StdAfx.obj" \
	".\Debug\inventorDoc.obj" \
	".\Debug\myclass.obj" \
	".\Debug\v3space1.obj" \
	".\Debug\inventor.res"

"$(OUTDIR)\inventor.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "inventor - Win32 Release"
# Name "inventor - Win32 Debug"

!IF  "$(CFG)" == "inventor - Win32 Release"

!ELSEIF  "$(CFG)" == "inventor - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "inventor - Win32 Release"

!ELSEIF  "$(CFG)" == "inventor - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\inventor.cpp
DEP_CPP_INVEN=\
	".\StdAfx.h"\
	".\inventor.h"\
	".\MainFrm.h"\
	".\ChildFrm.h"\
	".\inventorDoc.h"\
	".\inventorView.h"\
	

"$(INTDIR)\inventor.obj" : $(SOURCE) $(DEP_CPP_INVEN) "$(INTDIR)"\
 "$(INTDIR)\inventor.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "inventor - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL"\
 /D "_MBCS" /Fp"$(INTDIR)/inventor.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c\
 $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\inventor.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "inventor - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/inventor.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\inventor.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\StdAfx.h"\
	".\inventor.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\inventor.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	".\StdAfx.h"\
	".\inventor.h"\
	".\ChildFrm.h"\
	

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\inventor.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\inventorDoc.cpp
DEP_CPP_INVENT=\
	".\StdAfx.h"\
	".\inventor.h"\
	".\inventorDoc.h"\
	

"$(INTDIR)\inventorDoc.obj" : $(SOURCE) $(DEP_CPP_INVENT) "$(INTDIR)"\
 "$(INTDIR)\inventor.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\inventorView.cpp
DEP_CPP_INVENTO=\
	".\StdAfx.h"\
	".\inventor.h"\
	".\inventorDoc.h"\
	".\inventorView.h"\
	

"$(INTDIR)\inventorView.obj" : $(SOURCE) $(DEP_CPP_INVENTO) "$(INTDIR)"\
 "$(INTDIR)\inventor.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\inventor.rc
DEP_RSC_INVENTOR=\
	".\res\inventor.ico"\
	".\res\inventorDoc.ico"\
	".\res\Toolbar.bmp"\
	".\res\inventor.rc2"\
	

"$(INTDIR)\inventor.res" : $(SOURCE) $(DEP_RSC_INVENTOR) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\myclass.cpp
DEP_CPP_MYCLA=\
	".\StdAfx.h"\
	".\inventor.h"\
	".\myclass.h"\
	

"$(INTDIR)\myclass.obj" : $(SOURCE) $(DEP_CPP_MYCLA) "$(INTDIR)"\
 "$(INTDIR)\inventor.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\v3space1.cpp
DEP_CPP_V3SPA=\
	".\StdAfx.h"\
	".\v3space1.h"\
	

"$(INTDIR)\v3space1.obj" : $(SOURCE) $(DEP_CPP_V3SPA) "$(INTDIR)"\
 "$(INTDIR)\inventor.pch"


# End Source File
# End Target
# End Project
################################################################################
################################################################################
# Section inventor : {232AB9B5-B045-11CE-8822-004005154124}
# 	0:11:V3Space.cpp:D:\Msdevstd\Projects\inventor\V3Space1.cpp
# 	0:9:V3Space.h:D:\Msdevstd\Projects\inventor\V3Space1.h
# 	2:21:DefaultSinkHeaderFile:v3space1.h
# 	2:16:DefaultSinkClass:CV3Space
# End Section
################################################################################
################################################################################
# Section OLE Controls
# 	{232AB9B5-B045-11CE-8822-004005154124}
# End Section
################################################################################
################################################################################
# Section inventor : {232AB9B6-B045-11CE-8822-004005154124}
# 	2:5:Class:CV3Space
# 	2:10:HeaderFile:v3space1.h
# 	2:8:ImplFile:v3space1.cpp
# End Section
################################################################################
