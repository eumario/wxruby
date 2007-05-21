// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxEvent
GC_MANAGE_AS_EVENT(wxEvent);


%import "include/wxObject.h"

%include "include/wxEvent.h"
