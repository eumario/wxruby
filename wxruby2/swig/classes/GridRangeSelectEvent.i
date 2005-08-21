#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGridRangeSelectEvent

%{
#include <wx/grid.h>
%}

%typemap(in) wxGridCellCoords (int a,b) {
  a = NUM2INT(rb_ary_pop($1));
  b = NUM2INT(rb_ary_pop($1));
  $input = new wxGridCellCoords(a,b);
 
}

%typemap(out) wxGridCellCoords {
   $result = rb_ary_new();
   rb_ary_push($result,INT2NUM($1.GetRow()));
   rb_ary_push($result,INT2NUM($1.GetCol()));
}


%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"
%import "include/wxGridEvent.h"

%include "include/wxGridRangeSelectEvent.h"
