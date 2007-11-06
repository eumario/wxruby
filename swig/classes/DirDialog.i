// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDirDialog
GC_MANAGE_AS_DIALOG(wxDirDialog);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxDirDialog);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxDirDialog.h"
