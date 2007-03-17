#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

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


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

%include "include/wxTipWindow.h"
