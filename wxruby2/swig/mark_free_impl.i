// Copyright 2004-2007, WxRuby development team
// released under the MIT-style wxruby2 license

// mark_free_impl.i - this contains the C++ implementation of various
// common GC-related functions, such as shared %mark functions and
// methods for checking and setting whether a wxWidgets window has been
// destroyed. It is compiled into wx.cpp.


%{
static VALUE wx_destroyed_sym = rb_intern("@__wx_destroyed__");

// Code to be run when the ruby object is swept by GC - this only
// unlinks the C++ object from the ruby VALUE but doesn't delete
// it because it is still needed and will be managed by WxWidgets.
void GcNullFreeFunc(void *ptr)
{
  SWIG_RubyRemoveTracking(ptr);
}

// Tests if the window has been signalled as destroyed by a
// WindowDestroyEvent handled by wxRubyApp
bool GC_IsWindowDeleted(void *ptr)
{
  // If objects have been 'unlinked' then DATA_PTR = 0
  if ( ! ptr ) return true;
  VALUE rb_win = SWIG_RubyInstanceFor(ptr);
  if ( rb_ivar_defined(rb_win, wx_destroyed_sym ) )
	return true;
  else
	return false;
}

// Notes that the window has been signalled as destroyed by a
// WindowDestroyEvent handled by wxRubyApp
void GC_SetWindowDeleted(void *ptr)
{
  VALUE rb_win = SWIG_RubyInstanceFor(ptr);
  if ( rb_win != Qnil )
	{
	  rb_ivar_set(rb_win, wx_destroyed_sym, Qtrue);
	  SWIG_RubyUnlinkObjects(ptr);
	  SWIG_RubyRemoveTracking(ptr);
	}
}

// Carries out marking of Sizer objects belonging to a Wx::Window. Note
// that this isn't done as a standard mark routine because ONLY sizers
// that are known to belong to a still-alive window should be marked,
// not those picked up as marked by in-scope variables by
// Ruby. Otherwise, segfaults may result. Because Sizers are SWIG
// directors, they must be preserved from GC.
void GC_mark_SizerBelongingToWindow(wxSizer *wx_sizer, VALUE rb_sizer)
{
  // First, mark this sizer
  rb_gc_mark( rb_sizer );
  
  // Then loop over hte sizer's content and mark each sub-sizer in turn
  wxSizerItemList& children = wx_sizer->GetChildren();
  for ( wxwxSizerItemListNode *node = children.GetFirst(); 
		node;
		node = node->GetNext() )
	{
	  wxSizerItem* item = node->GetData();
	  wxSizer* child_sizer  = item->GetSizer();
	  if ( child_sizer )
		{
		  VALUE rb_child_sizer = SWIG_RubyInstanceFor(child_sizer);
		  if ( rb_child_sizer != Qnil )
			{  GC_mark_SizerBelongingToWindow(child_sizer, rb_child_sizer); }
		}
	}

}
// Similar to Sizers, MenuBar requires a special mark routine. This is
// because Wx::Menu is not a subclass of Window so isn't automatically
// protected in the mark phase by Wx::App. However, the ruby object
// still must not be destroyed while it is still accessible on screen,
// because it may still handle events. Rather than a SWIG %markfunc,
// which can catch destroyed MenuBars linked to an in-scope ruby
// variable and cause segfaults, MenuBars are always marked via the
// containing Frame.
void GC_mark_MenuBarBelongingToFrame(wxMenuBar *menu_bar) 
{
  rb_gc_mark( SWIG_RubyInstanceFor(menu_bar) );
  // Mark each menu in the menubar in turn
  for ( int i = 0; i < menu_bar->GetMenuCount(); i++ )
	{
	  wxMenu* menu  = menu_bar->GetMenu(i);
	  rb_gc_mark( SWIG_RubyInstanceFor(menu) );
	}

}

// Default mark routine for Windows - preserve the main sizer and caret
// belong to this window
void GC_mark_wxWindow(void *ptr)
{
  if ( GC_IsWindowDeleted(ptr) ) return;

  wxWindow* wx_win = (wxWindow*)ptr;
  wxSizer* wx_sizer = wx_win->GetSizer();
  if ( wx_sizer )
	{ 
	  VALUE rb_sizer = SWIG_RubyInstanceFor(wx_sizer);
	  if ( rb_sizer != Qnil )
		GC_mark_SizerBelongingToWindow(wx_sizer, rb_sizer); 
	}

  wxCaret* wx_caret = wx_win->GetCaret();
  if ( wx_caret )
	{
	  VALUE rb_caret = SWIG_RubyInstanceFor(wx_caret);
	  rb_gc_mark(rb_caret);
	}
}  


void GC_mark_wxFrame(void *ptr)
{
  if ( ! ptr ) return;
  if ( GC_IsWindowDeleted(ptr) ) return;

  // Frames are also a subclass of wxWindow, so must do all the marking
  // of sizers and carets associated with that class
  GC_mark_wxWindow(ptr);

  wxFrame* wx_frame = (wxFrame*)ptr;
  // Then mark the MenuBar, if one is associated with this Frame
  
  wxMenuBar* menu_bar = wx_frame->GetMenuBar();
  if ( menu_bar ) 
	{ GC_mark_MenuBarBelongingToFrame(menu_bar); }
}

// Prevents Ruby's GC sweeping up items that are stored as client data
// Checks whether the C++ object is still around first...
void mark_wxControlWithItems(void* ptr) {
  if ( GC_IsWindowDeleted(ptr) )
	return;

  wxControlWithItems* wx_cwi = (wxControlWithItems*) ptr;
  int count = wx_cwi->GetCount();
  if ( count == 0 )
	return; // Empty control
  if ( ! wx_cwi->HasClientObjectData() && ! wx_cwi->HasClientUntypedData() )
	return; // Control containing only strings
  
  for (int i = 0; i < count; ++i)
	{
	  VALUE object = (VALUE) wx_cwi->GetClientData(i);
	  if ( object && object != Qnil ) 
		rb_gc_mark(object);
	}
}
%}
