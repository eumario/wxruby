#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxMenu

%ignore GetMenuItems;
%ignore Append(int  id , const wxString&   item , wxMenu * subMenu , const wxString&  helpString = "") ;
%ignore Append(wxMenuItem*  menuItem ) ;


%include "include/wxMenu.h"
