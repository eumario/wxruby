// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxCollapsiblePane
GC_MANAGE_AS_WINDOW(wxCollapsiblePane);

%{
#include <wx/collpane.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxCollapsiblePane.h"
