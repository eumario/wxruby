// Copyright 2004-2007 by Kevin Smith
// released under the MIT-style wxruby2 license

%feature("director");
%feature("compactdefaultargs");

%runtime %{
// # SWIG 1.3.29 added this new feature which we can't use (yet)
#define SWIG_DIRECTOR_NOUEH TRUE



#  undef GetClassName
#  undef GetClassInfo
#  undef Yield
#  undef GetMessage
#  undef FindWindow
#  undef GetCharWidth
#  undef DrawText
#  undef StartDoc
#  undef CreateDialog
#  undef Sleep
#  undef Connect
#  undef connect

#  define WXINTL_NO_GETTEXT_MACRO 1
#include <wx/wx.h>
#include <wx/dcbuffer.h>


#if ! wxCHECK_VERSION(2,8,3)
#error "This version of wxRuby requires WxWidgets 2.8.3 or greater"
#endif

extern VALUE mWxruby2;
%}

%include "typedefs.i"
%include "typemap.i"
%include "memory_management.i"
