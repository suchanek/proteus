# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

!IF "$(CFG)" == ""
CFG=dmgen - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to dmgen - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "dmgen - Win32 Release" && "$(CFG)" != "dmgen - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "dmgen.mak" CFG="dmgen - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dmgen - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "dmgen - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "dmgen - Win32 Release"

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

ALL : "$(OUTDIR)\dmgen.exe"

CLEAN : 
	-@erase ".\Release\dmgen.exe"
	-@erase ".\Release\dmgen.obj"
	-@erase ".\Release\turtle2.obj"
	-@erase ".\Release\distmat.obj"
	-@erase ".\Release\disulfide.obj"
	-@erase ".\Release\geometry.obj"
	-@erase ".\Release\keypop.obj"
	-@erase ".\Release\phipsi.obj"
	-@erase ".\Release\protutil.obj"
	-@erase ".\Release\residue.obj"
	-@erase ".\Release\atom.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /GX /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /D "WIN32" /D "NDEBUG" /D "_CONSOLE"\
 /Fp"$(INTDIR)/dmgen.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/dmgen.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)/dmgen.pdb" /machine:I386 /out:"$(OUTDIR)/dmgen.exe" 
LINK32_OBJS= \
	"$(INTDIR)/dmgen.obj" \
	"$(INTDIR)/turtle2.obj" \
	"$(INTDIR)/distmat.obj" \
	"$(INTDIR)/disulfide.obj" \
	"$(INTDIR)/geometry.obj" \
	"$(INTDIR)/keypop.obj" \
	"$(INTDIR)/phipsi.obj" \
	"$(INTDIR)/protutil.obj" \
	"$(INTDIR)/residue.obj" \
	"$(INTDIR)/atom.obj"

"$(OUTDIR)\dmgen.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"

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

ALL : "$(OUTDIR)\dmgen.exe" "$(OUTDIR)\dmgen.bsc"

CLEAN : 
	-@erase ".\Debug\dmgen.exe"
	-@erase ".\Debug\dmgen.obj"
	-@erase ".\Debug\turtle2.obj"
	-@erase ".\Debug\distmat.obj"
	-@erase ".\Debug\disulfide.obj"
	-@erase ".\Debug\geometry.obj"
	-@erase ".\Debug\keypop.obj"
	-@erase ".\Debug\phipsi.obj"
	-@erase ".\Debug\protutil.obj"
	-@erase ".\Debug\residue.obj"
	-@erase ".\Debug\atom.obj"
	-@erase ".\Debug\dmgen.ilk"
	-@erase ".\Debug\dmgen.pdb"
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\Debug\dmgen.bsc"
	-@erase ".\Debug\dmgen.sbr"
	-@erase ".\Debug\turtle2.sbr"
	-@erase ".\Debug\distmat.sbr"
	-@erase ".\Debug\disulfide.sbr"
	-@erase ".\Debug\geometry.sbr"
	-@erase ".\Debug\keypop.sbr"
	-@erase ".\Debug\phipsi.sbr"
	-@erase ".\Debug\protutil.sbr"
	-@erase ".\Debug\residue.sbr"
	-@erase ".\Debug\atom.sbr"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /FR /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE"\
 /FR"$(INTDIR)/" /Fp"$(INTDIR)/dmgen.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c\
 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/dmgen.bsc" 
BSC32_SBRS= \
	"$(INTDIR)/dmgen.sbr" \
	"$(INTDIR)/turtle2.sbr" \
	"$(INTDIR)/distmat.sbr" \
	"$(INTDIR)/disulfide.sbr" \
	"$(INTDIR)/geometry.sbr" \
	"$(INTDIR)/keypop.sbr" \
	"$(INTDIR)/phipsi.sbr" \
	"$(INTDIR)/protutil.sbr" \
	"$(INTDIR)/residue.sbr" \
	"$(INTDIR)/atom.sbr"

"$(OUTDIR)\dmgen.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/dmgen.pdb" /debug /machine:I386 /out:"$(OUTDIR)/dmgen.exe" 
LINK32_OBJS= \
	"$(INTDIR)/dmgen.obj" \
	"$(INTDIR)/turtle2.obj" \
	"$(INTDIR)/distmat.obj" \
	"$(INTDIR)/disulfide.obj" \
	"$(INTDIR)/geometry.obj" \
	"$(INTDIR)/keypop.obj" \
	"$(INTDIR)/phipsi.obj" \
	"$(INTDIR)/protutil.obj" \
	"$(INTDIR)/residue.obj" \
	"$(INTDIR)/atom.obj"

"$(OUTDIR)\dmgen.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "dmgen - Win32 Release"
# Name "dmgen - Win32 Debug"

!IF  "$(CFG)" == "dmgen - Win32 Release"

!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\dmgen.c
DEP_CPP_DMGEN=\
	".\geometry.h"\
	".\atom.h"\
	".\turtle.h"\
	".\residue.h"\
	".\distmat.h"\
	".\phipsi.h"\
	".\keypop.h"\
	".\protutil.h"\
	

!IF  "$(CFG)" == "dmgen - Win32 Release"


"$(INTDIR)\dmgen.obj" : $(SOURCE) $(DEP_CPP_DMGEN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"


"$(INTDIR)\dmgen.obj" : $(SOURCE) $(DEP_CPP_DMGEN) "$(INTDIR)"

"$(INTDIR)\dmgen.sbr" : $(SOURCE) $(DEP_CPP_DMGEN) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\turtle2.c
DEP_CPP_TURTL=\
	".\protutil.h"\
	".\turtle.h"\
	".\geometry.h"\
	

!IF  "$(CFG)" == "dmgen - Win32 Release"


"$(INTDIR)\turtle2.obj" : $(SOURCE) $(DEP_CPP_TURTL) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"


"$(INTDIR)\turtle2.obj" : $(SOURCE) $(DEP_CPP_TURTL) "$(INTDIR)"

"$(INTDIR)\turtle2.sbr" : $(SOURCE) $(DEP_CPP_TURTL) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\distmat.c
DEP_CPP_DISTM=\
	".\protutil.h"\
	".\distmat.h"\
	".\atom.h"\
	".\geometry.h"\
	".\residue.h"\
	".\turtle.h"\
	".\phipsi.h"\
	

!IF  "$(CFG)" == "dmgen - Win32 Release"


"$(INTDIR)\distmat.obj" : $(SOURCE) $(DEP_CPP_DISTM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"


"$(INTDIR)\distmat.obj" : $(SOURCE) $(DEP_CPP_DISTM) "$(INTDIR)"

"$(INTDIR)\distmat.sbr" : $(SOURCE) $(DEP_CPP_DISTM) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\disulfide.c
DEP_CPP_DISUL=\
	".\protutil.h"\
	".\disulfide.h"\
	".\geometry.h"\
	".\turtle.h"\
	".\residue.h"\
	".\atom.h"\
	".\phipsi.h"\
	

!IF  "$(CFG)" == "dmgen - Win32 Release"


"$(INTDIR)\disulfide.obj" : $(SOURCE) $(DEP_CPP_DISUL) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"


"$(INTDIR)\disulfide.obj" : $(SOURCE) $(DEP_CPP_DISUL) "$(INTDIR)"

"$(INTDIR)\disulfide.sbr" : $(SOURCE) $(DEP_CPP_DISUL) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\geometry.c
DEP_CPP_GEOME=\
	".\protutil.h"\
	".\geometry.h"\
	

!IF  "$(CFG)" == "dmgen - Win32 Release"


"$(INTDIR)\geometry.obj" : $(SOURCE) $(DEP_CPP_GEOME) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"


"$(INTDIR)\geometry.obj" : $(SOURCE) $(DEP_CPP_GEOME) "$(INTDIR)"

"$(INTDIR)\geometry.sbr" : $(SOURCE) $(DEP_CPP_GEOME) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\keypop.c
DEP_CPP_KEYPO=\
	".\keypop.h"\
	

!IF  "$(CFG)" == "dmgen - Win32 Release"


"$(INTDIR)\keypop.obj" : $(SOURCE) $(DEP_CPP_KEYPO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"


"$(INTDIR)\keypop.obj" : $(SOURCE) $(DEP_CPP_KEYPO) "$(INTDIR)"

"$(INTDIR)\keypop.sbr" : $(SOURCE) $(DEP_CPP_KEYPO) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\phipsi.c
DEP_CPP_PHIPS=\
	".\protutil.h"\
	".\phipsi.h"\
	".\geometry.h"\
	
NODEP_CPP_PHIPS=\
	".\phipsi_all.h"\
	

!IF  "$(CFG)" == "dmgen - Win32 Release"


"$(INTDIR)\phipsi.obj" : $(SOURCE) $(DEP_CPP_PHIPS) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"


"$(INTDIR)\phipsi.obj" : $(SOURCE) $(DEP_CPP_PHIPS) "$(INTDIR)"

"$(INTDIR)\phipsi.sbr" : $(SOURCE) $(DEP_CPP_PHIPS) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\protutil.c
DEP_CPP_PROTU=\
	".\protutil.h"\
	

!IF  "$(CFG)" == "dmgen - Win32 Release"


"$(INTDIR)\protutil.obj" : $(SOURCE) $(DEP_CPP_PROTU) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"


"$(INTDIR)\protutil.obj" : $(SOURCE) $(DEP_CPP_PROTU) "$(INTDIR)"

"$(INTDIR)\protutil.sbr" : $(SOURCE) $(DEP_CPP_PROTU) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\residue.c
DEP_CPP_RESID=\
	".\protutil.h"\
	".\residue.h"\
	".\geometry.h"\
	".\turtle.h"\
	".\atom.h"\
	".\phipsi.h"\
	

!IF  "$(CFG)" == "dmgen - Win32 Release"


"$(INTDIR)\residue.obj" : $(SOURCE) $(DEP_CPP_RESID) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"


"$(INTDIR)\residue.obj" : $(SOURCE) $(DEP_CPP_RESID) "$(INTDIR)"

"$(INTDIR)\residue.sbr" : $(SOURCE) $(DEP_CPP_RESID) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\atom.c
DEP_CPP_ATOM_=\
	".\protutil.h"\
	".\atom.h"\
	".\geometry.h"\
	

!IF  "$(CFG)" == "dmgen - Win32 Release"


"$(INTDIR)\atom.obj" : $(SOURCE) $(DEP_CPP_ATOM_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "dmgen - Win32 Debug"


"$(INTDIR)\atom.obj" : $(SOURCE) $(DEP_CPP_ATOM_) "$(INTDIR)"

"$(INTDIR)\atom.sbr" : $(SOURCE) $(DEP_CPP_ATOM_) "$(INTDIR)"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
