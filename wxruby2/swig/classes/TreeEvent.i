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

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"

%include "include/wxTreeEvent.h"
