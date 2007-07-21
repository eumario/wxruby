// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxTaskBarIcon
GC_NEVER(wxTaskBarIcon); // Shouldn't be deleted from within Ruby

%{
#include <wx/taskbar.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxTaskBarIcon.h"
