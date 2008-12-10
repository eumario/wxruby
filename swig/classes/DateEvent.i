// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDateEvent
GC_MANAGE_AS_EVENT(wxDateEvent);

%{
#include <wx/dateevt.h>
%}

%include "../shared/datetime.i"

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"

%include "include/wxDateEvent.h"
