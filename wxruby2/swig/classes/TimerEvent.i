// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTimerEvent
GC_MANAGE_AS_EVENT(wxTimerEvent);

%{
#include <wx/timer.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxTimerEvent.h"
