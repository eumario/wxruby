// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxBusyInfo
GC_MANAGE(wxBusyInfo);

%{
#include <wx/busyinfo.h>
%}

%ignore wxBusyInfo::wxBusyInfo;

// BusyInfo is an exception to the general rule in typemap.i - it
// accepts a wxWindow* parent argument which may be null - but it does
// not inherit from TopLevelWindow - so special typemap for this class.
%typemap(check) wxWindow* parent {
  if ( ! rb_const_defined(mWxruby2, rb_intern("THE_APP") ) )
	{ rb_raise(rb_eRuntimeError,
			   "Cannot create BusyInfo before App.main_loop has been called");}
}

%include "include/wxBusyInfo.h"

%extend wxBusyInfo {
  static void busy(const wxString& message, wxWindow *parent = NULL)
  {
    if (rb_block_given_p())
    {
      wxBusyInfo disabler(message,parent);
      rb_yield(Qnil);
    }
    return ;
  }
}
