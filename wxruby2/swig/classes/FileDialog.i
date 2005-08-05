#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxFileDialog

# Although this works for wxWidgets 2.6.1 on OS X 10.4, 
# it fails for wxWidgets 2.5.3 on Ubuntu Linux.
# typemaps don't belong here anyway, so let's find a better solution.
#if 0
%typemap(in,numinputs=0) wxArrayString &(wxArrayString sel)
{
	$1 = &sel;
}

%typemap(argout) wxArrayString &{
  $result = rb_ary_new();
  for (int i = 0; i < $1->GetCount(); i++)
    rb_ary_push($result,rb_str_new2((*$1)[i].c_str()));
}
#endif

%include "include/wxFileDialog.h"
