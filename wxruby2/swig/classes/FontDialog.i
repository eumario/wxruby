// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxFontDialog
GC_MANAGE_AS_DIALOG(wxFontDialog);

%{
#include <wx/wx.h>
#include <wx/fontdlg.h>
%}



%ignore wxFontDialog::wxFontDialog(wxWindow *);
%typemap(default) wxFontData & {
	$1 = new wxFontData();
}

#
# Workaround for SWIG 1.3.22
#
%ignore wxFontDialog::Create();
%ignore wxFontDialog::wxFontDialog();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxFontDialog.h"
