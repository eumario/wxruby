// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTreebookEvent
GC_MANAGE_AS_EVENT(wxTreebookEvent);

%{
#include <wx/treebook.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"
%import "include/wxBookCtrlBaseEvent.h"

%include "include/wxTreebookEvent.h"
