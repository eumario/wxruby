// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxValidator
GC_MANAGE_AS_OBJECT(wxValidator);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxValidator.h"
