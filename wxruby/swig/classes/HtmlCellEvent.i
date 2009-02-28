// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxHtmlCellEvent
GC_MANAGE_AS_EVENT(wxHtmlCellEvent);

%{
#include <wx/html/htmlwin.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"

%include "include/wxHtmlCellEvent.h"
