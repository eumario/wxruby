#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxComboBox

%ignore wxComboBox::wxComboBox();
%rename (SetSelectionRange) SetSelection(long from, long to);


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
							
							
%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxComboBox.h"
