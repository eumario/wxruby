// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxMenuBar
GC_MANAGE_AS_WINDOW(wxMenuBar);

%ignore wxMenuBar(int  n , wxMenu*  menus[] , const wxString  titles[] ) ;

// MenuBar requires a special mark routine. This is because Wx::Menu is
// not a subclass of Window so isn't automatically protected in the mark
// phase by Wx::App. However, the ruby object still must not be
// destroyed while the Menu is still accessible on screen, because it
// may be required to handle events.
%{
void mark_wxMenuBar(void *ptr) 
{
  VALUE rb_win = SWIG_RubyInstanceFor(ptr);
  if ( rb_iv_get(rb_win, "@__wx_destroyed__") == Qtrue )
	  return;

  wxMenuBar* menu_bar = (wxMenuBar*)ptr;
  // Mark each menu in the menubar in turn
  for ( int i = 0; i < menu_bar->GetMenuCount(); i++ )
	{
	  wxMenu* menu  = menu_bar->GetMenu(i);
	  VALUE rb_menu = SWIG_RubyInstanceFor(menu);
	  rb_gc_mark(rb_menu);
	}
}  
%}

%markfunc wxMenuBar "mark_wxMenuBar";

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

%include "include/wxMenuBar.h"
