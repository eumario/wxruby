// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxWindowDisabler
GC_MANAGE(wxWindowDisabler);

%ignore wxWindowDisabler::wxWindowDisabler;

%include "include/wxWindowDisabler.h"

%extend wxWindowDisabler {
  static void disable(wxWindow *to_skip = NULL)
  {
    if (rb_block_given_p())
    {
      wxWindowDisabler disabler(to_skip);
      rb_yield(Qnil);
    }
    return ;
  }
}
