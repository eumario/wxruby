// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxStaticBox
GC_MANAGE_AS_WINDOW(wxStaticBox);

%ignore wxStaticBox::wxStaticBox();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxStaticBox.h"
