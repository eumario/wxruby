#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxListBox

%ignore wxListBox::wxListBox();
%ignore wxListBox::InsertItems(int nItems, const wxString *items, int pos);

// redundant with good type maps
%ignore Set(int  n , const wxString*  choices , void **clientData = NULL) ;

// start client_data fixes
%include "../shared/control_with_items.i"
%markfunc wxListBox "mark_wxControlWithItems";

%extend wxListBox {
  VALUE get_client_data(int n) { return wxControlWithItems_get_client_data(self, n); }
}
// end client_data fixes


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxListBox.h"
