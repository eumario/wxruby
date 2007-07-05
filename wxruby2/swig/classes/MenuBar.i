// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxMenuBar;
// Memory management is handled via the containing Frame
GC_NEVER(wxMenuBar);

%ignore wxMenuBar(int  n , wxMenu*  menus[] , const wxString  titles[] ) ;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

%include "include/wxMenuBar.h"
