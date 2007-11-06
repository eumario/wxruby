// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxSpinCtrl
GC_MANAGE_AS_WINDOW(wxSpinCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxSpinCtrl);

%{
#include <wx/spinctrl.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxSpinCtrl.h"
