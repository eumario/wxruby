// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridEditorCreatedEvent
GC_MANAGE_AS_EVENT(wxGridEditorCreatedEvent);

%{
#include <wx/grid.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxEvtHandler.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"

%include "include/wxGridEditorCreatedEvent.h"
