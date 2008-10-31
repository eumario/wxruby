// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxSearchCtrl
GC_MANAGE_AS_WINDOW(wxSearchCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxSearchCtrl);

%{
#include <wx/srchctrl.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxTextCtrl.h"

%include "include/wxSearchCtrl.h"
