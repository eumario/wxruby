// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxFindDialogEvent
GC_MANAGE_AS_EVENT(wxFindDialogEvent);

%{
#include <wx/fdrepdlg.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"

%include "include/wxFindDialogEvent.h"
