#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxChoice

%ignore wxChoice::wxChoice();
%ignore wxChoice::wxChoice(wxWindow *parent,
           wxWindowID id,
           const wxPoint& pos = wxDefaultPosition,
           const wxSize& size = wxDefaultSize,
           int n = 0, const wxString choices[] = NULL,
           long style = 0,
           const wxValidator& validator = wxDefaultValidator,
           const wxString& name = wxChoiceNameStr);
%ignore wxChoice::DoAppend(const wxString& item);
%ignore wxChoice::DoInsert(const wxString& item, int pos);


%typemap(in) (int  n , const wxString  choices[]) {
    $1 = NUM2INT(rb_funcall($input, rb_intern("size"), 0));
    $2 = new wxString[$1];
    for(int i=0; i < $1; ++i)
    {
        VALUE thisItem = rb_ary_entry($input, i);
        $2[i] = (wxChar *)STR2CSTR(thisItem);
    }
}


%include "include/wxChoice.h"
