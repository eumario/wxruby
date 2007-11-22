// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license
%include "../common.i"

%module(directors="1") wxMediaEvent
GC_MANAGE_AS_EVENT(wxMediaEvent);

%{
#include <wx/mediactrl.h>
%}

%import "include/wxNotifyEvent.h"
%import "include/wxCommandEvent.h"
%import "include/wxEvent.h"
%import "include/wxObject.h"

%include "include/wxMediaEvent.h"