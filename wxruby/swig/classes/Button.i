// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxButton
GC_MANAGE_AS_WINDOW(wxButton);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxButton);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxButton.h"
