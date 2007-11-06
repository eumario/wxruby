// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxProgressDialog
GC_MANAGE_AS_DIALOG(wxProgressDialog);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxProgressDialog);

%{
#include <wx/progdlg.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxProgressDialog.h"
