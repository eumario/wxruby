#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxSpinButton
%{
#include <wx/spinbutt.h>
%}

%ignore wxSpinButton::wxSpinButton();

%include "include/wxSpinButton.h"

