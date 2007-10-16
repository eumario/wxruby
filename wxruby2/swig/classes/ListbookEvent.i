// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxListbookEvent
GC_MANAGE_AS_EVENT(wxListbookEvent);

%{
#include <wx/listbook.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxListbookEvent.h"
