// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxMoveEvent
GC_MANAGE_AS_EVENT(wxMoveEvent);

%ignore wxMoveEvent::wxMoveEvent();

%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxMoveEvent.h"
