// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxCheckListBox
GC_MANAGE_AS_WINDOW(wxCheckListBox);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxCheckListBox);

// item data fixes not required here because fixed by superclass ListBox 

// not needed as fixed by typemap for alternate ArrayString constructor
%ignore Create(wxWindow *parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                int n = 0, const wxString choices[] = NULL,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxListBoxNameStr);
								
%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxListBox.h"

%include "include/wxCheckListBox.h"
