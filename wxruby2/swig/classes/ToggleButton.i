// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxToggleButton
GC_MANAGE_AS_WINDOW(wxToggleButton);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxToggleButton);

%{
#include <wx/tglbtn.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxToggleButton.h"
