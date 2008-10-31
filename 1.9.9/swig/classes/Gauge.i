// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGauge
GC_MANAGE_AS_WINDOW(wxGauge);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxGauge);
%{
#include <wx/gauge.h>
%}

%ignore wxGauge::wxGauge();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxGauge.h"
