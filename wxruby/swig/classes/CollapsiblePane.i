// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxCollapsiblePane
GC_MANAGE_AS_WINDOW(wxCollapsiblePane);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxCollapsiblePane);

%{
#include <wx/collpane.h>
%}

#define wxCP_DEFAULT_STYLE (wxTAB_TRAVERSAL | wxNO_BORDER)
#define wxCP_NO_TLW_RESIZE (0x0002)

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxCollapsiblePane.h"
