#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxTipWindow

%{
#include  <wx/tipwin.h>
%}


%typemap(default,numinputs=0) wxTipWindow **windowPtr {
  $1 = NULL;
}

%typemap(in,numinputs=0) wxTipWindow** windowPtr (wxTipWindow *ptr){
  $1 = &ptr;
}


%include "include/wxTipWindow.h"

