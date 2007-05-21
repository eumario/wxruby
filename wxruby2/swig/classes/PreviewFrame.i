// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxPreviewFrame
GC_MANAGE_AS_FRAME(wxPreviewFrame);

%{
#include <wx/print.h>
%}

%rename(init) Initialize;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"
%import "include/wxFrame.h"

%include "include/wxPreviewFrame.h"
