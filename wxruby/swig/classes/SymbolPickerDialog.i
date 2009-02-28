// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxSymbolPickerDialog
GC_MANAGE_AS_DIALOG(wxSymbolPickerDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxSymbolPickerDialog);

%{
// This macro redefinition is needed to work around the way the
// caption/title default parameter value to the constructor is declared
// - it uses the _() macro, but this is disabled by default in wxRuby
// b/c it conflicts with SWIG. So here we have to temporarily restore it
// to the wxWidgets value to avoid compile errors with gcc 4.0
#undef _
#define _(s) wxGetTranslation(_T(s))
#include <wx/richtext/richtextsymboldlg.h>
%}

%include "../shared/richtext.i"

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"
%import "include/wxDialog.h"

%include "include/wxSymbolPickerDialog.h"
