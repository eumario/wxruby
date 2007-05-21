// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxBusyCursor
GC_MANAGE(wxBusyCursor);
%feature("nodirector") wxBusyCursor;

%{
//NO_DIRECTOR
%}


%include "include/wxBusyCursor.h"

%extend wxBusyCursor  {

  static void busy() 
  {
    if (rb_block_given_p())
    {
      wxBusyCursor cursor;
      rb_yield(Qnil);
    }
  }
}
