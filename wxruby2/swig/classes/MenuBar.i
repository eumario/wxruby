// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxMenuBar
GC_MANAGE_AS_OBJECT(wxMenuBar);

%ignore    wxMenuBar(int  n , wxMenu*  menus[] , const wxString  titles[] ) ;


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxMenuBar.h"
