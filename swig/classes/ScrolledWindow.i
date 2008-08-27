// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%{
#include <wx/scrolwin.h>
%}

%module(directors="1") wxScrolledWindow
GC_MANAGE_AS_WINDOW(wxScrolledWindow);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxScrolledWindow);

%apply int * OUTPUT { int * }

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"

%include "include/wxScrolledWindow.h"
