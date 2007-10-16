// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTimer;
GC_MANAGE_AS_OBJECT(wxTimer);

%{
#include <wx/timer.h>
%}


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxTimer.h"
