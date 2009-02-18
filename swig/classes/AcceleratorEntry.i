// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxAcceleratorEntry
GC_MANAGE(wxAcceleratorEntry);

%{
#include <wx/accel.h>
%}

// wxAcceleratorEntry flags
enum
{
    wxACCEL_NORMAL  = 0x0000,   // no modifiers
    wxACCEL_ALT     = 0x0001,   // hold Alt key down
    wxACCEL_CTRL    = 0x0002,   // hold Ctrl key down
    wxACCEL_SHIFT   = 0x0004    // hold Shift key down
};

// Allow integer keycodes to be specified with a single-ASCII-character
// Ruby string. Slightly different approaches are needed for Ruby 1.8 and
// Ruby 1.9. 
%typemap("in") int keyCode {
  if ( TYPE($input) == T_FIXNUM ) {
    $1 = NUM2INT($input);
  }
  else if ( TYPE($input) == T_STRING ) {
#ifdef HAVE_RUBY_ENCODING_H
    $1 = NUM2INT( rb_funcall($input, rb_intern("ord"), 0) );
#else
    $1 = NUM2INT( rb_funcall($input, rb_intern("[]"), 1, INT2NUM(0)) );
#endif
  }
}

%typemap("typecheck") int keyCode {
  $1 = ( ( TYPE($input) == T_FIXNUM ) || 
         ( TYPE($input) == T_STRING && RSTRING_LEN($input) == 1) );
}

%include "include/wxAcceleratorEntry.h"
