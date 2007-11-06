// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxChoice
GC_MANAGE_AS_WINDOW(wxChoice);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxChoice);

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
CLIENT_DATA_FEATURES(wxChoice);
%markfunc wxChoice "mark_wxControlWithItems";
// end client_data fixes


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxChoice.h"
