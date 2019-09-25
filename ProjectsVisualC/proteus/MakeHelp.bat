@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by PROTEUS.HPJ. >"hlp\proteus.hm"
echo. >>"hlp\proteus.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\proteus.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\proteus.hm"
echo. >>"hlp\proteus.hm"
echo // Prompts (IDP_*) >>"hlp\proteus.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\proteus.hm"
echo. >>"hlp\proteus.hm"
echo // Resources (IDR_*) >>"hlp\proteus.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\proteus.hm"
echo. >>"hlp\proteus.hm"
echo // Dialogs (IDD_*) >>"hlp\proteus.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\proteus.hm"
echo. >>"hlp\proteus.hm"
echo // Frame Controls (IDW_*) >>"hlp\proteus.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\proteus.hm"
REM -- Make help for Project PROTEUS


echo Building Win32 Help files
start /wait hcrtf -x "hlp\proteus.hpj"
echo.
if exist Debug\nul copy "hlp\proteus.hlp" Debug
if exist Debug\nul copy "hlp\proteus.cnt" Debug
if exist Release\nul copy "hlp\proteus.hlp" Release
if exist Release\nul copy "hlp\proteus.cnt" Release
echo.


