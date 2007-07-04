#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%module(directors="1") wxruby2

%include "common.i"

%{

#include <wx/gdicmn.h>
#include <wx/image.h>

#include <wx/filesys.h>
#include <wx/fs_zip.h>

// Code to be run when the ruby object is swept by GC - this only
// unlinks the C++ object from the ruby VALUE but doesn't delete
// it because it is still needed and will be managed by WxWidgets.
void GcNullFreeFunc(void *ptr)
{
  SWIG_RubyRemoveTracking(ptr);
}

static VALUE wx_destroyed_sym = rb_intern("@__wx_destroyed__");
bool GC_IsWindowDeleted(void *ptr)
{
  VALUE rb_win = SWIG_RubyInstanceFor(ptr);
  return ( rb_ivar_defined(rb_win, wx_destroyed_sym ) == Qtrue );
}


// Carries out marking of Sizer objects belonging to a Wx::Window. Note
// that this isn't done as a standard mark routine because ONLY sizers
// that are known to belong to a still-alive window should be marked,
// not those picked up as marked by in-scope variables by
// Ruby. Otherwise, segfaults may result. Because Sizers are SWIG
// directors, they must be preserved from GC.
void GC_mark_SizerBelongingToWindow(wxSizer *wx_sizer)
{
  // First, mark this sizer
  rb_gc_mark( SWIG_RubyInstanceFor(wx_sizer) );

  // Then loop over hte sizer's content and mark each sub-sizer in turn
  wxSizerItemList& children = wx_sizer->GetChildren();
  for ( wxwxSizerItemListNode *node = children.GetFirst(); 
		node;
		node = node->GetNext() )
	{
	  wxSizerItem* item = node->GetData();
	  wxSizer* child_sizer  = item->GetSizer();
	  if ( child_sizer )
		{  GC_mark_SizerBelongingToWindow(child_sizer); }
	}

}

// Default mark routine for Windows - preserve the main sizer and caret
// belong to this window
void GC_mark_wxWindow(void *ptr)
{
  // can occasionally be NULL if called in an evt_create handler
  if ( ! ptr ) return; 
  if ( GC_IsWindowDeleted(ptr) ) return;

  wxWindow* wx_win = (wxWindow*)ptr;
  wxSizer* wx_sizer = wx_win->GetSizer();
  if ( wx_sizer )
	{ 
	  GC_mark_SizerBelongingToWindow(wx_sizer); 
	}

  wxCaret* wx_caret = wx_win->GetCaret();
  if ( wx_caret )
	{
	  VALUE rb_caret = SWIG_RubyInstanceFor(wx_caret);
	  rb_gc_mark(rb_caret);
	}
}  

%} 

%init %{

    extern void InitializeOtherModules();
    InitializeOtherModules();
    wxInitAllImageHandlers();

	// This is needed so HtmlHelp can load docs from a zip file
	wxFileSystem::AddHandler(new wxArchiveFSHandler);
%}

#define VERSION_STRING "wxRuby2"

int wxMessageBox(const wxString& message, const wxString& caption = wxT("Message"), int style = wxOK, wxWindow *parent = NULL, int x = -1, int y = -1);
