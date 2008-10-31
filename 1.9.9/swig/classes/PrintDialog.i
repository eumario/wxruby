// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPrintDialog
GC_MANAGE_AS_DIALOG(wxPrintDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxPrintDialog);

%{
#include <wx/printdlg.h>
%}

%feature("nodirector") wxPrintDialog;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"
%import "include/wxDialog.h"

%include "include/wxPrintDialog.h"
