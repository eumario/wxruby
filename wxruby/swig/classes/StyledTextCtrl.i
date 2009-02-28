// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxStyledTextCtrl
GC_MANAGE_AS_WINDOW(wxStyledTextCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxStyledTextCtrl);

%{
#include <wx/stc/stc.h>
%}

%typemap(in,numinputs=0) (int *OUTPUT) (int a)
{
  $1 = &a;
}

%typemap(argout) (int *OUTPUT)
{
  $result = rb_ary_new();
  rb_ary_push($result, INT2NUM(*$1));
}

%typemap(in,numinputs=0) (int *OUTPUT, int *OUTPUT) (int a, int b)
{
  $1 = &a;
  $2 = &b;
}

%typemap(argout) (int *OUTPUT, int *OUTPUT)
{
  $result = rb_ary_new();
  rb_ary_push($result, INT2NUM(*$1));
  rb_ary_push($result, INT2NUM(*$2));
}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxStyledTextCtrl.h"
