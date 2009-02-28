// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDialog
GC_MANAGE_AS_DIALOG(wxDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxDialog);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"

%include "include/wxDialog.h"
