#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxMenuItem

# the following are apparently MSWin-only
%ignore wxMenuItem::wxMenuItem(wxMenu *parentMenu,
             int id,
             const wxString& text,
             const wxString& help,
             bool isCheckable,
             wxMenu *subMenu = (wxMenu *)NULL);
%ignore wxMenuItem::GetRealId();
%ignore wxMenuItem::SetAsRadioGroupStart();
%ignore wxMenuItem::SetRadioGroupStart(int start);
%ignore wxMenuItem::SetRadioGroupEnd(int end);


%include "include/wxMenuItem.h"
