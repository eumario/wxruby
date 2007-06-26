// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxIconizeEvent
GC_MANAGE_AS_EVENT(wxIconizeEvent);


%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxIconizeEvent.h"
