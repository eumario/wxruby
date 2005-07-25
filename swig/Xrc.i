#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

%module(directors="1") wxXrc

%include "common.i"


%{

#include <wx/xrc/xmlres.h>

static VALUE 
xrcid(VALUE self,VALUE str_id)  
{
  char *tmp = STR2CSTR(str_id);
  int ret;
  VALUE retval;
  
  ret = wxXmlResource::GetXRCID((const wxChar *)tmp);
  
  retval = INT2NUM(ret);
  
  return retval;  
}

%}



%init %{
    extern VALUE mWxruby2;
    rb_define_module_function(mWxruby2, "xrcid", VALUEFUNC(xrcid), 1);
%}
