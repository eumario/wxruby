#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

%module(directors="1") wxFunctions

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
    extern VALUE mWx;
    rb_define_module_function(mWx, "xrcid", VALUEFUNC(xrcid), 1);
%}
