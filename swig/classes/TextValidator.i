// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxTextValidator
GC_MANAGE_AS_OBJECT(wxTextValidator);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxValidator.h"

%include "include/wxTextValidator.h"
