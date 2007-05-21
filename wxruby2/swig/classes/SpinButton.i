// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxSpinButton
GC_MANAGE_AS_WINDOW(wxSpinButton);
%{
#include <wx/spinbutt.h>
%}

%ignore wxSpinButton::wxSpinButton();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxSpinButton.h"
