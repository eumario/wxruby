// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxControlWithItems
GC_MANAGE_AS_WINDOW(wxControlWithItems);

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
