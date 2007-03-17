#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxTextCtrl

%apply long * OUTPUT { long * }

%ignore wxTextCtrl::wxTextCtrl();
%ignore wxTextCtrl::operator<<;


%{
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
        *ptr << (double)(RFLOAT(value)->value);
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
