#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxChoice

%ignore wxChoice::DoAppend(const wxString& item);
%feature("nodirector") wxChoice::DoAppend;
%ignore wxChoice::DoInsert(const wxString& item, int pos);
%feature("nodirector") wxChoice::DoInsert;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxChoice.h"
