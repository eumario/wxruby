// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxMenuEvent
GC_MANAGE_AS_EVENT(wxMenuEvent);


%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxMenuEvent.h"
