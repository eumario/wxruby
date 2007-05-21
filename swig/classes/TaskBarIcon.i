// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxTaskBarIcon
GC_MANAGE_AS_OBJECT(wxTaskBarIcon);

%{
#include <wx/taskbar.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxTaskBarIcon.h"
