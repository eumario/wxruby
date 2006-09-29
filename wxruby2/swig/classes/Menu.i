#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxMenu

GC_NEVER(wxMenu);

// Any MenuItems passed in to wx become owned by C++
%apply SWIGTYPE *DISOWN {wxMenuItem*  item};

%ignore wxMenu::wxMenu(long  style );

%rename(AppendMenu) wxMenu::Append(int itemid, const wxString& text, wxMenu *submenu, const wxString& help = wxEmptyString);
%rename(AppendItem) wxMenu::Append(wxMenuItem *item);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxMenu.h"
