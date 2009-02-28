// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPreviewCanvas
GC_MANAGE_AS_WINDOW(wxPreviewCanvas);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxPreviewCanvas);

%{
#include <wx/print.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"
%import "include/wxScrolledWindow.h"

%include "include/wxPreviewCanvas.h"
