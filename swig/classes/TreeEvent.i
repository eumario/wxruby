#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxTreeEvent

%{
#include <wx/treectrl.h>
%}

%ignore wxTreeEvent::GetLabel() const;
%ignore wxTreeEvent::GetPoint() const;
%ignore wxTreeEvent::IsEditCancelled() const;

%include "include/wxTreeEvent.h"
