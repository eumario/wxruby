// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxSingleChoiceDialog
GC_MANAGE_AS_DIALOG(wxSingleChoiceDialog);


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxSingleChoiceDialog.h"
