#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxFrame

%ignore wxFrame::wxFrame();

%apply SWIGTYPE *DISOWN { wxMenuBar * }

%typemap(in,numinputs=1) (int n, int * widths) (int size, int i, int *arr){

  size = RARRAY($input)->len;
  arr = new int[size];

  for(i = 0; i < size; i++)
  {
    arr[i] = NUM2INT(rb_ary_entry($input,i));
  }

  $1 = size;
  $2 = arr;
}

%typemap(freearg) (int n, int * widths) {
  delete $2;
}

%ignore wxFrame::Command;

GC_NEVER(wxFrame);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"

%include "include/wxFrame.h"