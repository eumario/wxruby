// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxFontDialog
GC_MANAGE_AS_DIALOG(wxFontDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxFontDialog);

%{
#include <wx/fontdlg.h>
%}

%apply SWIGTYPE *DISOWN { wxFontData* data };

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxFontDialog.h"
