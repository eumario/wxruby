// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxAuiNotebookEvent
GC_MANAGE_AS_EVENT(wxAuiNotebookEvent);

%{
#include <wx/aui/aui.h>
%}

%import "include/wxNotifyEvent.h"
%import "include/wxCommandEvent.h"
%import "include/wxEvent.h"
%import "include/wxObject.h"

%include "include/wxAuiNotebookEvent.h"
