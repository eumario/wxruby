// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module wxUpdateUIEvent
GC_MANAGE_AS_EVENT(wxUpdateUIEvent);

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"

%include "include/wxUpdateUIEvent.h"
