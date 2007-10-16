// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxMenu
// FIXME - deletion of pop-up menus
// MEnus associated with a MenuBar and Frame are deleted automatically
// on the C++ side when the MenuBar is destroyed.
// However, popup menus may not be being collected
GC_NEVER(wxMenu);

// Any MenuItems passed in to wx become owned by C++
%apply SWIGTYPE *DISOWN {wxMenuItem*  item};

%ignore wxMenu::wxMenu(long  style );

%rename(AppendMenu) wxMenu::Append(int itemid, const wxString& text, wxMenu *submenu, const wxString& help = wxEmptyString);
%rename(AppendItem) wxMenu::Append(wxMenuItem *item);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxMenu.h"
