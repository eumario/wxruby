#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxBitmapButton
%feature(nodirector) wxBitmapButton;

%{
//NO_DIRECTOR
%}

%ignore wxBitmapButton::wxBitmapButton();

%include "include/wxBitmapButton.h"
