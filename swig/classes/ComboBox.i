#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxComboBox

%ignore wxComboBox::wxComboBox();
%rename (SetSelectionRange) SetSelection(long from, long to);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxComboBox.h"
