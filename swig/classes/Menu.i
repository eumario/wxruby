// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxMenu
// NB: wxMenu receives special memory management in fixmodule.rb. A
// wxMenu is automatically deleted by wxWidgets when the associated
// Frame/MenuBar or popup is closed. However, deletion isn't notified by
// the normal WindowDestroyEvent mechanism in App.i, b/c Menu isn't a
// Window. So we have to hack into the director dtor to detach the ruby
// object from the now-destroyed C++ object, else crashes will occur on GC. 
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

// Mark Function
// Need to protect MenuItems which are included in the Menu, including
// their associated sub-menus, recursively.
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
        rb_gc_mark( SWIG_RubyInstanceFor(item) ); 
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
