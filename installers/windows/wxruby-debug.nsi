; Script generated with the Venis Install Wizard

; Define your application name
!define APPNAME "wxRuby"
!define APPNAMEANDVERSION "wxRuby 0.5.0"

!define WXRUBY_VERSION 050

!define DATE "August 25, 2004"


; Main Install settings
Name "${APPNAMEANDVERSION}"
InstallDir "$PROGRAMFILES\wxRuby"
InstallDirRegKey HKLM "Software\${APPNAME}" ""
OutFile "wxruby-mswin-0.5.0_debug.exe"


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
  File "wxruby-dbg\lib\vc60.pdb"
  File "wxruby-dbg\lib\wxruby.so"

  File "wxruby-dbg\lib\msvcrtd.dll"



  IfFileExists "" skipCRTcopy

    SetOutPath "$SYSDIR"
    File "wxruby-dbg\lib\msvcrtd.dll"

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
  MessageBox MB_OK "Could not find Ruby installation. You must manually copy 'wxruby.so' to $\n$\n(ruby-dir)\lib\ruby\site_ruby\1.8\i386-msvcrt\."
  Goto SkipCopy

  CopyToRubyDir:

    SetOutPath "$RubyDir\lib\ruby\site_ruby\1.8\i386-msvcrt\"
    File "wxruby-dbg\lib\wxruby.so"

  SkipCopy:


  ; Create Shortcuts

  CreateDirectory "$SMPROGRAMS\wxRuby"
  CreateShortCut "$SMPROGRAMS\wxRuby\Uninstall.lnk" "$INSTDIR\uninstall.exe"
  

SectionEnd

Section "Help Files" Section_Help

  ; Set Section properties
  SetOverwrite on

  ; Set Section Files and Shortcuts
  SetOutPath "$INSTDIR\"
  File /r "wxruby-dbg\help"
  CreateShortCut "$SMPROGRAMS\wxRuby\wxRuby Help.lnk" "$INSTDIR\help\wxrubydoc.html"

SectionEnd

Section "Sample wxRuby Programs" Section_Samples

  ; Set Section properties
  SetOverwrite on

  ; Set Section Files and Shortcuts
  SetOutPath "$INSTDIR\"
  File /r "wxruby-rel\samples"
  CreateDirectory "$SMPROGRAMS\wxRuby\Samples"

  SetOutPath "$INSTDIR\samples\artprov\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\artprov.lnk" "$INSTDIR\samples\artprov\artprov.rbw"
  SetOutPath "$INSTDIR\samples\calendar\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\calendar.lnk" "$INSTDIR\samples\calendar\calendar.rbw"
  SetOutPath "$INSTDIR\samples\caret\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\caret.lnk" "$INSTDIR\samples\caret\caret.rbw"
  SetOutPath "$INSTDIR\samples\checklst\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\checklst.lnk" "$INSTDIR\samples\checklst\checklst.rbw"
  SetOutPath "$INSTDIR\samples\config\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\conftest.rbw.lnk" "$INSTDIR\samples\config\conftest.rbw"

  CreateDirectory "$SMPROGRAMS\wxRuby\Samples\Controls"
    SetOutPath "$INSTDIR\samples\controls\"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Controls\controls.rbw.lnk" "$INSTDIR\samples\controls\controls.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Controls\get_item_sample.rbw.lnk" "$INSTDIR\samples\controls\get_item_sample.rbw"

  SetOutPath "$INSTDIR\samples\dialogs\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\dialogs.rbw.lnk" "$INSTDIR\samples\dialogs\dialogs.rbw"

  CreateDirectory "$SMPROGRAMS\wxRuby\Samples\Etc"
    SetOutPath "$INSTDIR\samples\etc\"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\b1.rbw -- Basic Steps - Step 1 - A Simple Application.lnk" "$INSTDIR\samples\etc\b1.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\dragdrop.rbw.lnk" "$INSTDIR\samples\etc\dragdrop.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\dndfile.rbw.lnk" "$INSTDIR\samples\etc\dndfile.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\dndtext.rbw.lnk" "$INSTDIR\samples\etc\dndtext.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\events.rbw.lnk" "$INSTDIR\samples\etc\events.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\font.rbw.lnk" "$INSTDIR\samples\etc\font.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\minimal.rbw.lnk" "$INSTDIR\samples\etc\minimal.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test.rbw -- Simple Text Editor.lnk" "$INSTDIR\samples\etc\test.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test2.rbw -- Simple Text Editor.lnk" "$INSTDIR\samples\etc\test2.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test3.rbw -- Simple Text Editor.lnk" "$INSTDIR\samples\etc\test3.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test4.rbw -- Button Dialog.lnk" "$INSTDIR\samples\etc\test4.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test5.rbw -- Calendar Dialog.lnk" "$INSTDIR\samples\etc\test5.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test6.rbw -- Check Box Dialog.lnk" "$INSTDIR\samples\etc\test6.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test7.rbw -- Check Box List Dialog.lnk" "$INSTDIR\samples\etc\test7.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test8.rbw -- Choice Dialog.lnk" "$INSTDIR\samples\etc\test8.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test9.rbw -- Combo Box Dialog.rbw.lnk" "$INSTDIR\samples\etc\test9.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test10.rbw -- Gauge Dialog.lnk" "$INSTDIR\samples\etc\test10.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test11.rbw -- List Box Dialoglnk" "$INSTDIR\samples\etc\test11.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test12.rbw -- Radio Box Dialog.lnk" "$INSTDIR\samples\etc\test12.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test13.rbw -- Radio Button Dialog.lnk" "$INSTDIR\samples\etc\test13.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test14.rbw -- Slider Dialog.lnk" "$INSTDIR\samples\etc\test14.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test15.rbw -- Spin Dialog.lnk" "$INSTDIR\samples\etc\test15.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test16.rbw -- Static Bitmap Dialog.lnk" "$INSTDIR\samples\etc\test16.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test17.rbw -- Static Box Dialog.lnk" "$INSTDIR\samples\etc\test17.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test18.rbw -- Static Line Dialog.lnk" "$INSTDIR\samples\etc\test18.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test19.rbw -- Static Text Dialog.lnk" "$INSTDIR\samples\etc\test19.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test20.rbw -- Text Dialog.lnk" "$INSTDIR\samples\etc\test20.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Etc\test21.rbw -- Simple Text Editor.lnk" "$INSTDIR\samples\etc\test21.rbw"

  SetOutPath "$INSTDIR\samples\grid\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\grid.rbw.lnk" "$INSTDIR\samples\grid\grid.rbw"

  CreateDirectory "$SMPROGRAMS\wxRuby\Samples\Html"
    SetOutPath "$INSTDIR\samples\html\about\" ; for working directory
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\html\about.rbw.lnk" "$INSTDIR\samples\html\about\about.rbw"
    SetOutPath "$INSTDIR\samples\html\printing\" ; for working directory
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\html\printing.rbw.lnk" "$INSTDIR\samples\html\printing\printing.rbw"
    SetOutPath "$INSTDIR\samples\html\test\" ; for working directory
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\html\test.rbw.lnk" "$INSTDIR\samples\html\test\test.rbw"

  SetOutPath "$INSTDIR\samples\images\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\images.rbw.lnk" "$INSTDIR\samples\images\images.rbw"
  SetOutPath "$INSTDIR\samples\layout\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\layout.rbw.lnk" "$INSTDIR\samples\layout\layout.rbw"
  SetOutPath "$INSTDIR\samples\listctrl\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\listtest.rbw.lnk" "$INSTDIR\samples\listctrl\listtest.rbw"
  SetOutPath "$INSTDIR\samples\mdi\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\mdi.rbw.lnk" "$INSTDIR\samples\mdi\mdi.rbw"

  CreateDirectory "$SMPROGRAMS\wxRuby\Samples\Minimal"
    SetOutPath "$INSTDIR\samples\minimal\"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Minimal\minimal.rbw.lnk" "$INSTDIR\samples\minimal\minimal.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Minimal\nothing.rbw.lnk" "$INSTDIR\samples\minimal\nothing.rbw"

  CreateDirectory "$SMPROGRAMS\wxRuby\Samples\Sockets"
    SetOutPath "$INSTDIR\samples\sockets\"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Sockets\client.rbw.lnk" "$INSTDIR\samples\sockets\client.rbw"
    CreateShortCut "$SMPROGRAMS\wxRuby\Samples\Sockets\server.rbw.lnk" "$INSTDIR\samples\sockets\server.rbw"

  SetOutPath "$INSTDIR\samples\splitter\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\splitter.rbw.lnk" "$INSTDIR\samples\splitter\splitter.rbw"
  SetOutPath "$INSTDIR\samples\toolbar\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\toolbar.rbw.lnk" "$INSTDIR\samples\toolbar\toolbar.rbw"
  SetOutPath "$INSTDIR\samples\treectrl\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\treetest.rbw.lnk" "$INSTDIR\samples\treectrl\treetest.rbw"
  SetOutPath "$INSTDIR\samples\xrc\"
  CreateShortCut "$SMPROGRAMS\wxRuby\Samples\xrc.rbw.lnk" "$INSTDIR\samples\xrc\xrc_sample.rbw"

SectionEnd

Section "Source Code" Section_Source

  ; Set Section properties
  SetOverwrite on

  ; Set Section Files and Shortcuts
  SetOutPath "$INSTDIR\"
  File /r "wxruby-dbg\src"

  File "wxruby-dbg\README.mswin"

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
