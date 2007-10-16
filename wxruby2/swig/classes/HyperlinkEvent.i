// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxHyperlinkEvent
GC_MANAGE_AS_EVENT(wxHyperlinkEvent);

%{
#include <wx/hyperlink.h>
%}

%ignore wxCommandEvent::Checked;

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"

%include "include/wxHyperlinkEvent.h"
