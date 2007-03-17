#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%{
#include <wx/calctrl.h>
%}

%module(directors="1") wxCalendarEvent

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"
// if/when we add this class, uncomment it
//%import "include/wxDateEvent.h"

%include "include/wxCalendarEvent.h"
