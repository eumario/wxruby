// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxSpinCtrl
GC_MANAGE_AS_WINDOW(wxSpinCtrl);

%{
#include <wx/spinctrl.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxSpinCtrl.h"
