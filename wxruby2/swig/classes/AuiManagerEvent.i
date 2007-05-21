// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxAuiManagerEvent
GC_MANAGE_AS_EVENT(wxAuiManagerEvent);

%{
#include <wx/aui/aui.h>
%}

%import "include/wxEvent.h"
%import "include/wxObject.h"

%include "include/wxAuiManagerEvent.h"
