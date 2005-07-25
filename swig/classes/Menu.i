#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxMenu

GC_NEVER(wxMenu);

%ignore wxMenu::wxMenu(long  style );

%rename(AppendMenu) wxMenu::Append(int itemid, const wxString& text, wxMenu *submenu, const wxString& help = wxEmptyString);
%rename(AppendItem) wxMenu::Append(wxMenuItem *item);

%include "include/wxMenu.h"
