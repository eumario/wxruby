#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"


%module(directors="1") wxTextCtrl

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

%include "include/wxTextCtrl.h"
