// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTaskBarIcon
GC_NEVER(wxTaskBarIcon); // Shouldn't be deleted from within Ruby

%{
#include <wx/taskbar.h>
%}

// This is used for CreatePopupMenu, a virtual method which is
// overridden in user subclasses of TaskBarIcon to create the menu over
// the icon.  
// 
// The Wx::Menu needs to be protected from GC so the typemap stores the
// object returned by the ruby method in an instance variable so it's
// marked. It also handles the special case where +nil+ is returned, to
// signal to Wx that no menu is to be shown.
%typemap(directorout) wxMenu* {
  rb_iv_set( swig_get_self(), "@__popmenu__", $1);
  if ( NIL_P($1) ) {
    $result = NULL;
  }
  else {
    void* ptr;
    bool swig_res = SWIG_ConvertPtr(result, &ptr, 
                                    $1_descriptor,  
                                    0|SWIG_POINTER_DISOWN);
    if ( ! SWIG_IsOK(swig_res) ) {
      rb_raise(rb_eTypeError, 
               "create_popup_menu must return a Wx::Menu, or nil");
   }
    $result = reinterpret_cast< wxMenu * >(ptr);
  }
}

%extend wxTaskBarIcon {
  // Explicitly dispose of a TaskBarIcon; needed for clean exits on
  // Windows.
  VALUE destroy()
  {
	delete $self;
	return Qnil;
  }
}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxTaskBarIcon.h"
