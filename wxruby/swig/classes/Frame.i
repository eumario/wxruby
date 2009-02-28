// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxFrame
GC_MANAGE_AS_FRAME(wxFrame);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxFrame);

%apply SWIGTYPE *DISOWN { wxMenuBar * }

%typemap(in,numinputs=1) (int n, int * widths) (int size, int i, int *arr){

  size = RARRAY_LEN($input);
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
%feature("nodirector") IsFullScreen;


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"

%include "include/wxFrame.h"
