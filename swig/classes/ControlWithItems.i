#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxControlWithItems
%feature("nodirector") wxControlWithItems;   // abstract base class

%{
//NO_DIRECTOR
%}

%ignore wxControlWithItems::SetSelection;
%ignore wxControlWithItems::SetStringSelection;

// TODO: Not sure how this class fits into the inheritance chain,
// since it seems to be via multiple inheritance.
// Do we need it at all?
%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxControlWithItems.h"
