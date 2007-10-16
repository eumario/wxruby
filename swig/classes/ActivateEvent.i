// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxActivateEvent
GC_MANAGE_AS_EVENT(wxActivateEvent);


%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxActivateEvent.h"
