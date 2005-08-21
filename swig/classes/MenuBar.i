#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxMenuBar

%ignore    wxMenuBar(int  n , wxMenu*  menus[] , const wxString  titles[] ) ;

GC_NEVER(wxMenuBar);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxMenuBar.h"
