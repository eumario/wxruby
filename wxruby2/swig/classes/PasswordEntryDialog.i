// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPasswordEntryDialog
GC_MANAGE_AS_DIALOG(wxPasswordEntryDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxPasswordEntryDialog);

%{
#include <wx/textdlg.h>
%}

%import "include/wxObject.h"
%import "include/wxWindow.h"
%import "include/wxEvtHandler.h"
%import "include/wxDialog.h"
%import "include/wxTextEntryDialog.h"

%include "include/wxPasswordEntryDialog.h"
