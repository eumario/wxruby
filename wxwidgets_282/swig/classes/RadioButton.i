#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxRadioButton
%{
#include <wx/wx.h>
#include <wx/radiobut.h>
%}

%ignore wxRadioButton::wxRadioButton();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxRadioButton.h"
