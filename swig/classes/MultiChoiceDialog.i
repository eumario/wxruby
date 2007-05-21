// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxMultiChoiceDialog
GC_MANAGE_AS_DIALOG(wxMultiChoiceDialog);

%{
#include <wx/choicdlg.h>
%}

// for SetSelections - note that GetSelectiosn is dealt with the standard
// typemap(out) ArrayInt in typemap.i
%typemap(in) const wxArrayInt& selections (wxArrayInt tmp){
  if (($input == Qnil) || (TYPE($input) != T_ARRAY))
  {
    $1 = &tmp;
  }
  else
  {
    for (int i = 0; i < RARRAY($input)->len; i++)
    {
      int item = NUM2INT(rb_ary_entry($input,i));
      tmp.Add(item);
    }
    $1 = &tmp;
  }
}

%import "include/wxObject.h"
%import "include/wxWindow.h"
%import "include/wxEvtHandler.h"
%import "include/wxDialog.h"

%include "include/wxMultiChoiceDialog.h"
