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

%ignore wxMenu::wxMenu(long  style);

%rename(AppendMenu) wxMenu::Append(int itemid, 
                                   const wxString& text, 
                                   wxMenu *submenu, 
                                   const wxString& help = wxEmptyString);
%rename(AppendItem) wxMenu::Append(wxMenuItem *item);

// Fix for GetMenuItems - converts list of MenuItems to Array
%typemap(out) wxMenuItemList& {
  $result = rb_ary_new();
  wxMenuItemList::iterator iter;
  for (iter = $1->begin(); iter != $1->end(); ++iter)
    {
        wxMenuItem *wx_menu_item = *iter;
        VALUE rb_menu_item = SWIG_NewPointerObj(SWIG_as_voidptr(wx_menu_item), 
                                                SWIGTYPE_p_wxMenuItem, 0);
        rb_ary_push($result, rb_menu_item);
    }
}

// Need to protect sub-menus associated with particular items in the menu
%{
  static void mark_wxMenu(void *ptr) 
  {
    if ( GC_IsWindowDeleted(ptr) )
      return;

    wxMenu* menu = (wxMenu*)ptr;
    wxMenuItemList menu_items = menu->GetMenuItems();
    wxMenuItemList::iterator iter;
    for (iter = menu_items.begin(); iter != menu_items.end(); ++iter)
      {
        wxMenuItem *item = *iter;
        wxMenu* sub_menu = item->GetSubMenu();
        if ( sub_menu)
          rb_gc_mark( SWIG_RubyInstanceFor(sub_menu) );
      }
    return;
  }
%}

%markfunc wxMenu "mark_wxMenu";

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxMenu.h"
