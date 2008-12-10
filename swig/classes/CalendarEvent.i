// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

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
%import "include/wxDateEvent.h"

%include "include/wxCalendarEvent.h"
