// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxFileDropTarget
GC_MANAGE_AS_OBJECT(wxFileDropTarget);

%{
#include <wx/dnd.h>
%}

%ignore OnDrop;
%ignore OnData;  

// Use C++ implementations, don't call into Ruby
%feature("nodirector") OnData;

// For on_drop_files
%typemap(directorin) wxArrayString & {
  $input = rb_ary_new();
  for (int i = 0; i < $1.GetCount(); i++)
  {
    rb_ary_push($input, WXSTR_TO_RSTR($1[i]));
  }
}

%import "include/wxDropTarget.h"

%include "include/wxFileDropTarget.h"
