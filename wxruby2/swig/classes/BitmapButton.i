// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxBitmapButton
GC_MANAGE_AS_WINDOW(wxBitmapButton);

%ignore wxBitmapButton::wxBitmapButton();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxButton.h"

%include "include/wxBitmapButton.h"
