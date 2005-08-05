#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%{
#include <wx/calctrl.h>
%}

%module(directors="1") wxCalendarEvent

%include "include/wxCalendarEvent.h"
