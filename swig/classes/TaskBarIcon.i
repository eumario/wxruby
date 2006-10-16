#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxTaskBarIcon

%{
#include <wx/taskbar.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxTaskBarIcon.h"
