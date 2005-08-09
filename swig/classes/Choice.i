#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxChoice

%ignore wxChoice::wxChoice();
%ignore wxChoice::wxChoice(wxWindow *parent,
           wxWindowID id,
           const wxPoint& pos = wxDefaultPosition,
           const wxSize& size = wxDefaultSize,
           int n = 0, const wxString choices[] = NULL,
           long style = 0,
           const wxValidator& validator = wxDefaultValidator,
           const wxString& name = wxChoiceNameStr);
%ignore wxChoice::DoAppend(const wxString& item);
%ignore wxChoice::DoInsert(const wxString& item, int pos);


%include "include/wxChoice.h"
