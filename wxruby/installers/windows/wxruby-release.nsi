; Script generated with the Venis Install Wizard

; Define your application name
!define APPNAME "wxRuby"
!define APPNAMEANDVERSION "wxRuby 0.2"
!define WXRUBY_VERSION 020
!define DATE "Janurary 5, 2004"

; Main Install settings
Name "${APPNAMEANDVERSION}"
InstallDir "$PROGRAMFILES\wxRuby"
InstallDirRegKey HKLM "Software\${APPNAME}" ""
OutFile "wxruby-mswin-0.2_release.exe"

Var "RubyDir"   ; will contain the directory where Ruby is installed

; Modern interface settings
!include "MUI.nsh"

!define MUI_ABORTWARNING

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE "wxruby-rel\LICENSE"
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
	File "wxruby-rel\lib\wxruby.so"

	; Where is Ruby installed?
  ReadRegStr $RubyDir HKLM "software\www.ruby-lang.org" InstallPath
  IfErrors 0 CopyToRubyDir
		ReadRegStr $RubyDir HKLM "software\www.ruby-lang.org\Ruby180-10" ""
		IfErrors 0 CopyToRubyDir
			MessageBox MB_OK "Could not find Ruby installation. You must manually copy 'wxruby.so' to $\n$\n(ruby-dir)\lib\ruby\site_ruby\1.8\i386-msvcrt\."
			Goto SkipCopy
			
  CopyToRubyDir:
		SetOutPath "$RubyDir\lib\ruby\site_ruby\1.8\i386-msvcrt\"
		File "wxruby-rel\lib\wxruby.so"
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
	File /r "wxruby-rel\help"
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
	SetOutPath "$INSTDIR\samples\controls\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\controls.rbw.lnk" "$INSTDIR\samples\controls\controls.rbw"
	SetOutPath "$INSTDIR\samples\dialogs\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\dialogs.rbw.lnk" "$INSTDIR\samples\dialogs\dialogs.rbw"
	SetOutPath "$INSTDIR\samples\etc\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\dragdrop.rbw.lnk" "$INSTDIR\samples\etc\dragdrop.rbw"
	SetOutPath "$INSTDIR\samples\etc\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\dndfile.rbw.lnk" "$INSTDIR\samples\etc\dndfile.rbw"
	SetOutPath "$INSTDIR\samples\etc"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\dndtext.rbw.lnk" "$INSTDIR\samples\etc\dndtext.rbw"
	SetOutPath "$INSTDIR\samples\etc"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\events.rbw.lnk" "$INSTDIR\samples\etc\events.rbw"
	SetOutPath "$INSTDIR\samples\etc"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\font.rbw.lnk" "$INSTDIR\samples\etc\font.rbw"
	SetOutPath "$INSTDIR\samples\images\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\images.rbw.lnk" "$INSTDIR\samples\images\images.rbw"
	SetOutPath "$INSTDIR\samples\layout\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\layout.rbw.lnk" "$INSTDIR\samples\layout\layout.rbw"
	SetOutPath "$INSTDIR\samples\listctrl\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\listtest.rbw.lnk" "$INSTDIR\samples\listctrl\listtest.rbw"
	SetOutPath "$INSTDIR\samples\minimal\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\minimal.rbw.lnk" "$INSTDIR\samples\minimal\minimal.rbw"
	SetOutPath "$INSTDIR\samples\sockets\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\client.rbw.lnk" "$INSTDIR\samples\sockets\client.rbw"
	SetOutPath "$INSTDIR\samples\sockets\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\server.rbw.lnk" "$INSTDIR\samples\sockets\server.rbw"
	SetOutPath "$INSTDIR\samples\toolbar\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\toolbar.rbw.lnk" "$INSTDIR\samples\toolbar\toolbar.rbw"
	SetOutPath "$INSTDIR\samples\treectrl\"
	CreateShortCut "$SMPROGRAMS\wxRuby\Samples\treetest.rbw.lnk" "$INSTDIR\samples\treectrl\treetest.rbw"

SectionEnd

Section "Source Code" Section_Source

	; Set Section properties
	SetOverwrite on

	; Set Section Files and Shortcuts
	SetOutPath "$INSTDIR\"
	File /r "wxruby-rel\src"
	File "wxruby-rel\README.mswin"

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