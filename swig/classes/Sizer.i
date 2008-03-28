// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxSizer
GC_MANAGE_AS_SIZER(wxSizer);

%feature("nodirector") wxSizer::CalcMin;
%ignore wxSizer::IsShown;

// shared functions
%include "../shared/sizers.i"

// Typemap for GetChildren - convert to array of Sizer items
%typemap(out) wxSizerItemList& {
  $result = rb_ary_new();

  wxSizerItemList::compatibility_iterator node = $1->GetFirst();
  while (node)
  {
    wxSizerItem *wx_si = node->GetData();
    VALUE rb_si = SWIG_NewPointerObj(wx_si, SWIGTYPE_p_wxSizerItem, 0);
    rb_ary_push($result, rb_si);
    node = node->GetNext();
  }
}

%import "include/wxObject.h"

%include "include/wxSizer.h"
