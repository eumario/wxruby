#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxBusyInfo

%{
#include <wx/busyinfo.h>
%}

%ignore wxBusyInfo::wxBusyInfo;

%include "include/wxBusyInfo.h"

%extend wxBusyInfo {
  static void busy(const char *msg, wxWindow *parent = NULL)
  {
    if (rb_block_given_p())
    {
      wxBusyInfo disabler(msg,parent);
      rb_yield(Qnil);
    }
    return ;
  }
}
