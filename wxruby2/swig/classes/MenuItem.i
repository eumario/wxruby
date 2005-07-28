#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
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

# the following don't work under Linux/wx2.5.3
%ignore wxMenuItem::SetAsRadioGroupStart();
%ignore wxMenuItem::SetRadioGroupStart(int start);
%ignore wxMenuItem::SetRadioGroupEnd(int end);


%include "include/wxMenuItem.h"
