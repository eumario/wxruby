#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxBusyCursor


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
