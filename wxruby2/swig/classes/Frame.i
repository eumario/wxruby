#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxFrame

%ignore wxFrame::wxFrame();

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

%include "include/wxFrame.h"
