// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxMenuItem
// GC_MANAGE_AS_OBJECT(wxMenuItem);
GC_NEVER(wxMenuItem);

# the following are apparently MSWin-only
%ignore wxMenuItem::GetRealId();
%ignore wxMenuItem::SetAsRadioGroupStart();
%ignore wxMenuItem::SetRadioGroupStart(int start);
%ignore wxMenuItem::SetRadioGroupEnd(int end);


%import "include/wxObject.h"
// TODO: Also OwnerDrawn under MS Windows

%include "include/wxMenuItem.h"
