// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxBookCtrlBaseEvent
GC_MANAGE_AS_EVENT(wxBookCtrlBaseEvent);

%{
#include <wx/bookctrl.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"

%include "include/wxBookCtrlBaseEvent.h"
