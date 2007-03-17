#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxChoice

%ignore wxChoice::DoAppend(const wxString& item);
%feature("nodirector") wxChoice::DoAppend;
%ignore wxChoice::DoInsert(const wxString& item, int pos);
%feature("nodirector") wxChoice::DoInsert;

// redundant with good typemaps
%ignore wxChoice(wxWindow *parent,
           wxWindowID id,
           const wxPoint& pos = wxDefaultPosition,
           const wxSize& size = wxDefaultSize,
           int n = 0, const wxString choices[] = NULL,
           long style = 0,
           const wxValidator& validator = wxDefaultValidator,
           const wxString& name = wxChoiceNameStr);
%ignore Create(wxWindow *parent,
              wxWindowID id,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              int n = 0, const wxString choices[] = NULL,
              long style = 0,
              const wxValidator& validator = wxDefaultValidator,
              const wxString& name = wxChoiceNameStr);

// start client_data fixes
%include "../shared/control_with_items.i"
%markfunc wxChoice "mark_wxControlWithItems";

%extend wxChoice {
  VALUE get_client_data(int n) { return wxControlWithItems_get_client_data(self, n); }
}
// end client_data fixes


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxChoice.h"
