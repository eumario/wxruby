#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxControlWithItems

%ignore wxControlWithItems::Append(const wxString&   item);
%ignore wxControlWithItems::Append(const wxString&   item , wxClientData * clientData );
%ignore wxControlWithItems::Append(const wxArrayString&  strings );
%ignore wxControlWithItems::Number;
%ignore wxControlWithItems::Clear;
%ignore wxControlWithItems::Insert;
%ignore wxControlWithItems::IsEmpty;
%ignore wxControlWithItems::SetSelection;
%ignore wxControlWithItems::SetStringSelection;

%include "include/wxControlWithItems.h"
