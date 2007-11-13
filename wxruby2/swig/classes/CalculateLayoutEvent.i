// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxCalculateLayoutEvent
GC_MANAGE_AS_EVENT(wxCalculateLayoutEvent);

%{
#include <wx/laywin.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"
%include "include/wxCalculateLayoutEvent.h"
