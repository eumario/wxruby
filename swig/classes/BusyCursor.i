#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxBusyCursor

# this class is "not polymorphic" (has no vtable),
# so we have to disable directors for it
%feature("nodirector") wxBusyCursor;


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
