#   Copyright 2004-2007 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxAuiManager

%{
#include <wx/aui/aui.h>
%}

%import "include/wxEvtHandler.h"
%import "include/wxObject.h"

%include "include/wxAuiManager.h"
