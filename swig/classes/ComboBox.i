// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxComboBox
GC_MANAGE_AS_WINDOW(wxComboBox);

%ignore wxComboBox::wxComboBox();

// methods for getting and setting the text selection
%rename (SetTextSelectionRange) wxComboBox::SetSelection(long from, long to);
%rename (GetTextSelectionRange) wxComboBox::GetSelection(long *from, long *to) const;
%apply long * OUTPUT { long *from, long *to }


// redundant with good typemaps
%ignore Create(wxWindow *parent,
              wxWindowID id,
              const wxString& value = wxEmptyString,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              int n = 0,
              const wxString choices[] = NULL,
              long style = 0,
              const wxValidator& validator = wxDefaultValidator,
              const wxString& name = wxComboBoxNameStr);

// start client_data fixes
%include "../shared/control_with_items.i"
%markfunc wxComboBox "mark_wxControlWithItems";

%extend wxComboBox {
  // ComboBox doesn't convert to ControlWithItems, 
  // so copied here from control_with_items.i
  VALUE get_client_data(int n) 
  {
	VALUE returnVal = (VALUE) self->GetClientData(n);
	if ( returnVal == NULL )
	  return Qnil;
	return returnVal;
  }
}
// end client_data fixes							
							
%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxComboBox.h"
