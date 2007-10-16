// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPen
GC_MANAGE_AS_OBJECT(wxPen);

%typemap(in,numinputs=1) (int n, wxDash *dashes) (wxDash *arr)
{
  if (($input == Qnil) || (TYPE($input) != T_ARRAY))
  {
    $1 = 0;
    $2 = NULL;
  }
  else
  {
    arr = new wxDash[RARRAY($input)->len];
    for (int i = 0; i < RARRAY($input)->len; i++)
    {
	arr[i] = NUM2INT(rb_ary_entry($input,i));
    }
    $1 = RARRAY($input)->len;
    $2 = arr;
  }
}

%typemap(default,numinputs=1) (int n, wxDash *dashes)
{
    $1 = 0;
    $2 = NULL;
}

%typemap(freearg) (int n , wxDash *dashes)
{
    if ($2 != NULL) delete [] $2;
}

%typemap(typecheck) (int n , wxDash *dashes)
{
   $1 = (TYPE($input) == T_ARRAY);
}

%import "include/wxObject.h"
%import "include/wxGDIObject.h"

%include "include/wxPen.h"
