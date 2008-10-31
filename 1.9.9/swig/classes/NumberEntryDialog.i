// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxNumberEntryDialog
GC_MANAGE_AS_DIALOG(wxNumberEntryDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxNumberEntryDialog);

%{
#include <wx/numdlg.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxNumberEntryDialog.h"
