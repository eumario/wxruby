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

// problematic Wx definition of _ macro conflicts with SWIG 
#define WXINTL_NO_GETTEXT_MACRO 1

// appears in both ruby headers and wx headers, avoid warning on MSW
#ifdef __WXMSW__
#undef HAVE_FSYNC
#endif

#include <wx/wx.h>
#include <wx/dcbuffer.h>


#if ! wxCHECK_VERSION(2,8,5)
#error "This version of wxRuby requires WxWidgets 2.8.5 or greater"
#endif

extern VALUE mWxruby2; // The global Wxruby2 module
extern swig_class cWxTopLevelWindow; // used for wxWindow typemap in typemap.i
extern bool GC_IsWindowDeleted(void *ptr);
// Defined in wx.i; getting, setting and using swig_type <-> ruby class
// mappings
extern swig_type_info* wxRuby_GetSwigTypeForClass(VALUE cls);
extern void wxRuby_SetSwigTypeForClass(VALUE cls, swig_type_info* ty);
extern VALUE wxRuby_WrapWxObjectInRuby(wxObject* obj);
extern VALUE wxRuby_WrapWxEventInRuby(wxEvent* event);
%}

%include "typedefs.i"
%include "typemap.i"
%include "memory_management.i"

// Used to reduce bloat in classes inheriting from Wx::Window
%include "shared/no_window_virtuals.i"
