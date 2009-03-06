// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDirDialog
GC_MANAGE_AS_DIALOG(wxDirDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxDirDialog);

%constant const int wxDD_CHANGE_DIR;
%constant const int wxDD_DIR_MUST_EXIST;
// deprecated, on by default now, use wxDD_DIR_MUST_EXIST to disable it
%constant const int wxDD_NEW_DIR_BUTTON;
%constant const int wxDD_DEFAULT_STYLE;



%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxDirDialog.h"
