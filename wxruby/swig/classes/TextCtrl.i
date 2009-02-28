// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTextCtrl
GC_MANAGE_AS_WINDOW(wxTextCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxTextCtrl);

%apply long * OUTPUT { long * }
%apply long * OUTPUT { wxTextCoord *col, wxTextCoord *row }

%ignore wxTextCtrl::operator<<;

%rename(check_spelling) MacCheckSpelling;

%{

// Ruby 1.9 compatibility - changed to RFLOAT_VALUE
#ifndef RFLOAT_VALUE
#define RFLOAT_VALUE(x) RFLOAT(x)->value
#endif

// Allow << to work with a TextCtrl
VALUE op_append(VALUE self,VALUE value)
  {
    wxTextCtrl *ptr;
    Data_Get_Struct(self, wxTextCtrl, ptr);
    if(TYPE(value)==T_STRING)
      *ptr << wxString(StringValuePtr(value), wxConvUTF8);
    else if(TYPE(value)==T_FIXNUM)
      *ptr << NUM2INT(value);
    else if(TYPE(value)==T_FLOAT)
      *ptr << (double)(RFLOAT_VALUE(value));
    return self;
  }

%}

%init %{
  extern VALUE mWxTextCtrl;
  rb_define_method(mWxTextCtrl, "<<", VALUEFUNC(op_append), 1);
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxTextCtrl.h"
