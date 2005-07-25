#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxListBox

%ignore wxListBox::wxListBox();
%ignore wxListBox::InsertItems(int nItems, const wxString *items, int pos);

%include "include/wxListBox.h"
