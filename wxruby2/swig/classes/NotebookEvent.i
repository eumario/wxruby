// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxNotebookEvent
GC_MANAGE_AS_EVENT(wxNotebookEvent);

%{
#include <wx/notebook.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"


%include "include/wxNotebookEvent.h"
