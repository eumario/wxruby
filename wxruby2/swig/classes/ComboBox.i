#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxComboBox

%ignore wxComboBox::wxComboBox();
%rename (SetSelectionRange) SetSelection(long from, long to);
%include "include/wxComboBox.h"
