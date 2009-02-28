// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxControl
GC_MANAGE_AS_WINDOW(wxControl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxControl);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

%include "include/wxControl.h"
