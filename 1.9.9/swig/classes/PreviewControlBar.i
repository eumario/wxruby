// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPreviewControlBar
GC_MANAGE_AS_WINDOW(wxPreviewControlBar);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxPreviewControlBar);

%{
#include <wx/print.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"

%include "include/wxPreviewControlBar.h"
