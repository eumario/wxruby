// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxCommandEvent
GC_MANAGE_AS_EVENT(wxCommandEvent);

// deprecated
%ignore wxCommandEvent::Checked;
// Should use get_client_data
%ignore wxCommandEvent::GetClientObject;
%ignore wxCommandEvent::SetClientObject;
// This doesn't do anything that can't be done using better-named equivalents
%ignore wxCommandEvent::GetExtraLong;

%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxCommandEvent.h"
