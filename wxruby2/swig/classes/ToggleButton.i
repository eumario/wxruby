#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxToggleButton

%{
#include <wx/tglbtn.h>
%}

%ignore wxToggleButton::wxToggleButton();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxToggleButton.h"
