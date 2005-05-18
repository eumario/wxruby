#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
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


%include "include/wxGridRangeSelectEvent.h"

