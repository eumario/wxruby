// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxBitmapButton
GC_MANAGE_AS_WINDOW(wxBitmapButton);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxBitmapButton);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxButton.h"

%include "include/wxBitmapButton.h"
