#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxMenu

GC_NEVER(wxMenu);

%ignore wxMenu::wxMenu(long  style );

%rename(AppendMenu) wxMenu::Append(int itemid, const wxString& text, wxMenu *submenu, const wxString& help = wxEmptyString);
%rename(AppendItem) wxMenu::Append(wxMenuItem *item);

%include "include/wxMenu.h"
