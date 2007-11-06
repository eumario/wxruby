// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPanel
GC_MANAGE_AS_WINDOW(wxPanel);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxPanel);



%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

%include "include/wxPanel.h"
