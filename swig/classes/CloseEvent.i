// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxCloseEvent
GC_MANAGE_AS_EVENT(wxCloseEvent);

%ignore wxCloseEvent::GetForce;
%ignore wxCloseEvent::GetSessionEnding;
%ignore wxCloseEvent::SetForce;

%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxCloseEvent.h"
