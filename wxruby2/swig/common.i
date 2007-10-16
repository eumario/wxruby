// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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

extern VALUE mWxruby2; // The global Wxruby2 module
extern swig_class cWxTopLevelWindow; // used for wxWindow typemap in typemap.i
extern bool GC_IsWindowDeleted(void *ptr);
// Defined in wx.i; get and set SWIGTYPE type info from ruby class
extern swig_type_info* wxRuby_GetSwigTypeForClass(VALUE cls);
extern void wxRuby_SetSwigTypeForClass(VALUE cls, swig_type_info* ty);
%}

%include "typedefs.i"
%include "typemap.i"
%include "memory_management.i"
