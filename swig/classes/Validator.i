// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxValidator
GC_MANAGE_AS_OBJECT(wxValidator);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxValidator.h"
