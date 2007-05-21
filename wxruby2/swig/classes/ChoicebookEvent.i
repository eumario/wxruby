// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxChoicebookEvent
GC_MANAGE_AS_EVENT(wxChoicebookEvent);

%{
#include <wx/choicebk.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxChoicebookEvent.h"
