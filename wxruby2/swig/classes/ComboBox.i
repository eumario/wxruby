// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxComboBox
GC_MANAGE_AS_WINDOW(wxComboBox);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxComboBox);

// methods for getting and setting the text selection
%rename (SetTextSelectionRange) wxComboBox::SetSelection(long from, long to);
%rename (GetTextSelectionRange) wxComboBox::GetSelection(long *from, long *to) const;
%apply long * OUTPUT { long *from, long *to }

// Avoid compile warning with GCC 4
%feature("nodirector") wxComboBox::GetCount;

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
CLIENT_DATA_FEATURES(wxComboBox);
%markfunc wxComboBox "mark_wxControlWithItems";
							
%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxControlWithItems.h"

%include "include/wxComboBox.h"
