// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxUpdateUIEvent
GC_MANAGE_AS_EVENT(wxUpdateUIEvent);

enum wxUpdateUIMode
{
  wxUPDATE_UI_PROCESS_ALL,
  wxUPDATE_UI_PROCESS_SPECIFIED
};

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"

%include "include/wxUpdateUIEvent.h"
