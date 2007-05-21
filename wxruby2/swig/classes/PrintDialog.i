// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxPrintDialog
GC_MANAGE_AS_DIALOG(wxPrintDialog);
%feature("nodirector") wxPrintDialog;

%{
#include <wx/printdlg.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"
%import "include/wxDialog.h"

%include "include/wxPrintDialog.h"
