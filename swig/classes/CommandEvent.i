// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxCommandEvent
GC_MANAGE_AS_EVENT(wxCommandEvent);

%ignore wxCommandEvent::Checked;

%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxCommandEvent.h"
