#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGridEvent

%{
#include <wx/grid.h>
%}

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxEvtHandler.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"

%include "include/wxGridEvent.h"