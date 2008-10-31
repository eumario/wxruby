// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxScrollBar
GC_MANAGE_AS_WINDOW(wxScrollBar);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxScrollBar);

#define wxSB_HORIZONTAL      wxHORIZONTAL
#define wxSB_VERTICAL        wxVERTICAL

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxScrollBar.h"
