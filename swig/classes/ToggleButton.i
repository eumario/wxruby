#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
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


