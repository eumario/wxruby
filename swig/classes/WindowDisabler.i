#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
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
