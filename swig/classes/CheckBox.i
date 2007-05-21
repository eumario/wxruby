// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxCheckBox
GC_MANAGE_AS_WINDOW(wxCheckBox);

%ignore wxCheckBox::wxCheckBox();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxCheckBox.h"
