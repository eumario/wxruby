#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxToggleButton

%runtime %{
//@@if defined(__WXMSW__)
%}

%{
#include <wx/tglbtn.h>
%}

%ignore wxToggleButton::wxToggleButton();

%include "include/wxToggleButton.h"
