#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxPreviewFrame

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
