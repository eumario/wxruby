// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxControlWithItems
GC_MANAGE_AS_WINDOW(wxControlWithItems);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxControlWithItems);

%ignore wxControlWithItems::SetSelection;
%ignore wxControlWithItems::SetStringSelection;

// Typemap for GetStrings - which returns an object not a reference,
// unlike all other ArrayString-returning methods
%typemap(out) wxArrayString {
  $result = rb_ary_new();
  for (size_t i = 0; i < $1.GetCount(); i++)
  {
    rb_ary_push($result, WXSTR_TO_RSTR($1.Item(i)));
  }
}

// TODO: Not sure how this class fits into the inheritance chain,
// since it seems to be via multiple inheritance.
// Do we need it at all?
%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxControlWithItems.h"
