// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGridEvent
GC_MANAGE_AS_EVENT(wxGridEvent);

%{
#include <wx/grid.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxEvtHandler.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"

%include "include/wxGridEvent.h"
