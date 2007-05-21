// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridRangeSelectEvent
GC_MANAGE_AS_EVENT(wxGridRangeSelectEvent);

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
%import "include/wxEvtHandler.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"

%include "include/wxGridRangeSelectEvent.h"
