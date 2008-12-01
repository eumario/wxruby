// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxListBox
GC_MANAGE_AS_WINDOW(wxListBox);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxListBox);

%ignore wxListBox::InsertItems(int nItems, const wxString *items, int pos);

// redundant with good type maps
%ignore Set(int  n , const wxString*  choices , void **clientData = NULL) ;

// start client_data fixes
%include "../shared/control_with_items.i"
CLIENT_DATA_FEATURES(wxListBox);
%markfunc wxListBox "mark_wxControlWithItems";
// end client_data fixes

%include "../shared/arrayint_selections.i"


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxListBox.h"
