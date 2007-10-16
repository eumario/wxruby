// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxWindowDisabler
GC_MANAGE(wxWindowDisabler);
%feature("nodirector") wxWindowDisabler;

%{
//NO_DIRECTOR
%}

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
