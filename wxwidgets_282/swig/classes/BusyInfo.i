#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxBusyInfo

%{
#include <wx/busyinfo.h>
%}

%ignore wxBusyInfo::wxBusyInfo;

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
