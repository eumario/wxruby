// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTopLevelWindow
GC_MANAGE_AS_WINDOW(wxTopLevelWindow);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxTopLevelWindow);

%feature("nodirector") IsFullScreen;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

%include "include/wxTopLevelWindow.h"
