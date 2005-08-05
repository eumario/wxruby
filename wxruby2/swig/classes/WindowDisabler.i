#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxWindowDisabler

%ignore wxWindowDisabler::wxWindowDisabler;

%include "include/wxWindowDisabler.h"

%extend wxWindowDisabler {
  static void disable(wxWindow *parent = NULL)
  {
    if (rb_block_given_p())
    {
      wxWindowDisabler disabler(parent);
      rb_yield(Qnil);
    }
    return ;
  }
}
