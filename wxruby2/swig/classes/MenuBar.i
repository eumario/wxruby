#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxMenuBar

%ignore    wxMenuBar(int  n , wxMenu*  menus[] , const wxString  titles[] ) ;

GC_NEVER(wxMenuBar);

%include "include/wxMenuBar.h"
