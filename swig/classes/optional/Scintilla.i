#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../../common.i"

%module(directors="1") wxScintilla

%{
#include <wx/wxscintilla.h>
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

%import "../include/wxObject.h"
%import "../include/wxEvtHandler.h"
%import "../include/wxWindow.h"
%import "../include/wxControl.h"

%include "wx/wxscintilla.h"
