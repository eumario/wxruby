; Script generated with the Venis Install Wizard

; Define your application name
!define APPNAME "wxRuby-swig"
!define APPNAMEANDVERSION "wxRuby-swig preview_1"

!define WXRUBY_VERSION 050

!define DATE "October 8, 2004"


; Main Install settings
Name "${APPNAMEANDVERSION}"
InstallDir "$PROGRAMFILES\wxRuby-swig-preview"
InstallDirRegKey HKLM "Software\${APPNAME}" ""
OutFile "wxruby-swig-preview_1-mswin.exe"


Var "RubyDir"   ; will contain the directory where Ruby is installed


; Modern interface settings
!include "MUI.nsh"

!define MUI_ABORTWARNING

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE "wxruby-dbg\LICENSE"
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

; Set languages (first is default language)
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_RESERVEFILE_LANGDLL

Section "wxRuby Library" Section_Library
  ; Record our basic installation into in the registry

  WriteRegStr HKLM "software\wxRuby" InstallPath "$INSTDIR"

  WriteRegStr HKLM "software\wxRuby" InstallVersion "${WXRUBY_VERSION}"

  WriteRegStr HKLM "software\wxRuby" InstallDate "${DATE}"



; Set Section properties
  SetOverwrite on


  ; Set Section Files and Shortcuts
  SetOutPath "$INSTDIR\lib\"
  File "wxruby-dbg\lib\vc70.pdb"
  File "wxruby-dbg\lib\wx.so"

  File "wxruby-dbg\lib\msvcr71.dll"
  File "wxruby-dbg\lib\msvcp71.dll"



  IfFileExists "" skipCRTcopy

    SetOutPath "$SYSDIR"
    File "wxruby-dbg\lib\msvcr71.dll"
    File "wxruby-dbg\lib\msvcp71.dll"

  skipCRTcopy:


  ; Where is Ruby installed?


  ReadRegStr $RubyDir HKLM "software\Ruby\RubyInstaller\" DefaultPath
  IfErrors 0 CopyToRubyDir

  ReadRegStr $RubyDir HKLM "software\www.ruby-lang.org" InstallPath
  IfErrors 0 CopyToRubyDir
  ReadRegStr $RubyDir HKLM "software\www.ruby-lang.org\Ruby181-12" ""
  IfErrors 0 CopyToRubyDir
  ReadRegStr $RubyDir HKLM "software\www.ruby-lang.org\Ruby181-11" ""
  IfErrors 0 CopyToRubyDir
  ReadRegStr $RubyDir HKLM "software\www.ruby-lang.org\Ruby180-10" ""
  IfErrors 0 CopyToRubyDir
  MessageBox MB_OK "Could not find Ruby installation. You must manually copy 'wx.so' to $\n$\n(ruby-dir)\lib\ruby\site_ruby\1.8\i386-msvcrt\."
  Goto SkipCopy

  CopyToRubyDir:

    SetOutPath "$RubyDir\lib\ruby\site_ruby\1.8\i386-msvcrt\"
    File "wxruby-dbg\lib\wx.so"

  SkipCopy:


  ; Create Shortcuts

  CreateDirectory "$SMPROGRAMS\wxRuby-swig Preview"
  CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\Uninstall.lnk" "$INSTDIR\uninstall.exe"
  

SectionEnd

;Section "Help Files" Section_Help
;
;  ; Set Section properties
;  SetOverwrite on
;
;  ; Set Section Files and Shortcuts
;  SetOutPath "$INSTDIR\"
;  File /r "wxruby-dbg\help"
;  CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\wxRuby Help.lnk" "$INSTDIR\help\wxrubydoc.html"
;
;SectionEnd

Section "Sample wxRuby Programs" Section_Samples

  ; Set Section properties
  SetOverwrite on

  ; Set Section Files and Shortcuts
  SetOutPath "$INSTDIR\"
  File /r "wxruby-dbg\samples"
  CreateDirectory "$SMPROGRAMS\wxRuby-swig Preview\Samples"

  SetOutPath "$INSTDIR\samples\calendar\"
  CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\Samples\calendar.lnk" "$INSTDIR\samples\calendar\calendar.rbw"
  SetOutPath "$INSTDIR\samples\caret\"
  CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\Samples\caret.lnk" "$INSTDIR\samples\caret\caret.rbw"

  CreateDirectory "$SMPROGRAMS\wxRuby-swig Preview\Samples\Controls"
    SetOutPath "$INSTDIR\samples\controls\"
    CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\Samples\Controls\controls.rbw.lnk" "$INSTDIR\samples\controls\controls.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\Samples\Controls\get_item_sample.rbw.lnk" "$INSTDIR\samples\controls\get_item_sample.rbw"

  SetOutPath "$INSTDIR\samples\dialogs\"
  CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\Samples\dialogs.rbw.lnk" "$INSTDIR\samples\dialogs\dialogs.rbw"

  CreateDirectory "$SMPROGRAMS\wxRuby-swig Preview\Samples\Etc"
    SetOutPath "$INSTDIR\samples\etc\"
    CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\Samples\Etc\choice.rbw.lnk" "$INSTDIR\samples\etc\choice.rbw"

  SetOutPath "$INSTDIR\samples\images\"
  CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\Samples\images.rbw.lnk" "$INSTDIR\samples\images\images.rbw"
  SetOutPath "$INSTDIR\samples\mdi\"
  CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\Samples\mdi.rbw.lnk" "$INSTDIR\samples\mdi\mdi.rbw"

  CreateDirectory "$SMPROGRAMS\wxRuby-swig Preview\Samples\Minimal"
    SetOutPath "$INSTDIR\samples\minimal\"
    CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\Samples\Minimal\minimal.rbw.lnk" "$INSTDIR\samples\minimal\minimal.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby-swig Preview\Samples\Minimal\nothing.rbw.lnk" "$INSTDIR\samples\minimal\nothing.rbw"

SectionEnd

Section "Source Code" Section_Source

  ; Set Section properties
  SetOverwrite on

  ; Set Section Files and Shortcuts
  SetOutPath "$INSTDIR\"
  File /r "wxruby-dbg\src"

  File "wxruby-dbg\LICENSE"
  File "wxruby-dbg\README"
  File "wxruby-dbg\TODO"

SectionEnd

Section -FinishSection

  WriteRegStr HKLM "Software\${APPNAME}" "" "$INSTDIR"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "DisplayName" "${APPNAME}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "UninstallString" "$INSTDIR\uninstall.exe"
  WriteUninstaller "$INSTDIR\uninstall.exe"

SectionEnd

; Modern install component descriptions
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
  !insertmacro MUI_DESCRIPTION_TEXT ${Section_Library} "This installs the wxRuby binary library files."
  !insertmacro MUI_DESCRIPTION_TEXT ${Section_Help} "This installs documentation for the wxRuby API."
  !insertmacro MUI_DESCRIPTION_TEXT ${Section_Samples} "This installs sample wxRuby programs."
  !insertmacro MUI_DESCRIPTION_TEXT ${Section_Source} "This installs the source code for the wxRuby library."
!insertmacro MUI_FUNCTION_DESCRIPTION_END

;Uninstall section
Section Uninstall

  ;Remove from registry...
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}"
  DeleteRegKey HKLM "SOFTWARE\${APPNAME}"

  ; Remove remaining directories
  RMDir /r "$SMPROGRAMS\wxRuby"
  RMDir /r "$INSTDIR\"

SectionEnd

BrandingText "wxRuby"

; eof
