// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxCalendarEvent
GC_MANAGE_AS_EVENT(wxCalendarEvent);

%{
#include <wx/calctrl.h>
%}

%include "../shared/datetime.i"

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"
// if/when we add this class, uncomment it
//%import "include/wxDateEvent.h"

%include "include/wxCalendarEvent.h"
