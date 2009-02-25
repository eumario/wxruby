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
%{
  int wxRuby_RubyStringOrIntToKeyCode(VALUE rb_key) {
    if ( TYPE(rb_key) == T_FIXNUM ) {
      return NUM2INT(rb_key);
    }
    else if ( TYPE(rb_key) == T_STRING ) {
#ifdef HAVE_RUBY_ENCODING_H
      return NUM2INT( rb_funcall(rb_key, rb_intern("ord"), 0) );
#else
      return NUM2INT( rb_funcall(rb_key, rb_intern("[]"), 1, INT2NUM(0)) );
#endif
    }
    else {
      rb_raise(rb_eTypeError, 
               "Specify key code for AcceleratorEntry with a String or Fixnum");
    }
      
  }
%}
%typemap("in") int keyCode "$1 = wxRuby_RubyStringOrIntToKeyCode($input);"

%typemap("typecheck") int keyCode {
  $1 = ( ( TYPE($input) == T_FIXNUM ) || 
         ( TYPE($input) == T_STRING && RSTRING_LEN($input) == 1) );
}

%include "include/wxAcceleratorEntry.h"
