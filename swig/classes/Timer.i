#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxTimer;

%{
#include <wx/timer.h>
%}

GC_NEVER(wxTimer);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxTimer.h"
