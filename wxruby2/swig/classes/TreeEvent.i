#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxTreeEvent

%{
#include <wx/treectrl.h>
%}

%ignore wxTreeEvent::GetLabel() const;
%ignore wxTreeEvent::GetPoint() const;
%ignore wxTreeEvent::IsEditCancelled() const;

%include "include/wxTreeEvent.h"