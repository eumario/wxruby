#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxChoice

%ignore wxChoice::wxChoice();


%typemap(in) (int  n , const wxString  choices[]) {
    $1 = NUM2INT(rb_funcall($input, rb_intern("size"), 0));
printf("Size: %d\n", $1);
    $2 = new wxString[$1];
    for(int i=0; i < $1; ++i)
    {
        VALUE thisItem = rb_ary_entry($input, i);
        $2[i] = STR2CSTR(thisItem);
printf("Item %d: %s\n", i, $2[i].c_str());
    }
}


%include "include/wxChoice.h"
