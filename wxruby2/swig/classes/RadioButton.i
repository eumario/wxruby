#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxRadioButton
%{
#include <wx/wx.h>
#include <wx/radiobut.h>
%}

%ignore wxRadioButton::wxRadioButton();

%include "include/wxRadioButton.h"

