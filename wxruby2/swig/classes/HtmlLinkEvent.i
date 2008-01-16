// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxHtmlLinkEvent
GC_MANAGE_AS_EVENT(wxHtmlLinkEvent);

%{
#include <wx/html/htmlwin.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"

%include "include/wxHtmlLinkEvent.h"
