#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxListBox

%ignore wxListBox::wxListBox();
%ignore wxListBox::InsertItems(int nItems, const wxString *items, int pos);

%include "include/wxListBox.h"
