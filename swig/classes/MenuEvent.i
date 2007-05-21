// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxMenuEvent
GC_MANAGE_AS_EVENT(wxMenuEvent);


%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxMenuEvent.h"
