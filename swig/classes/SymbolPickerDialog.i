// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxSymbolPickerDialog
GC_MANAGE_AS_DIALOG(wxSymbolPickerDialog);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxSymbolPickerDialog);

%{
#include <wx/richtext/richtextsymboldlg.h>
%}

%include "../shared/richtext.i"

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"
%import "include/wxDialog.h"

%include "include/wxSymbolPickerDialog.h"
