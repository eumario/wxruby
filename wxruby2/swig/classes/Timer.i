// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxTimer;
GC_MANAGE_AS_OBJECT(wxTimer);

%{
#include <wx/timer.h>
%}


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxTimer.h"
