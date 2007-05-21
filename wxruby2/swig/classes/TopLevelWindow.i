// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxTopLevelWindow
GC_MANAGE_AS_WINDOW(wxTopLevelWindow);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

%include "include/wxTopLevelWindow.h"
