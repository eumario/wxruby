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

// Default mark routine for Windows - preserve sizers
void GC_mark_wxWindow(void *ptr)
{
  // can occasionally be NULL if called in an evt_create handler
  if ( ! ptr ) return; 
  if ( GC_IsWindowDeleted(ptr) ) return;

  wxWindow* wx_win = (wxWindow*)ptr;
  wxSizer* wx_sizer = wx_win->GetSizer();
  if ( wx_sizer )
	{
	  VALUE rb_sizer = SWIG_RubyInstanceFor(wx_sizer);
	  rb_gc_mark(rb_sizer);
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
