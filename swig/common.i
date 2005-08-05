#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%feature("director");

%{
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
#  undef _
#  undef Connect
#  undef connect

#include <wx/wx.h>
#include <wx/dcbuffer.h>

void GcMarkDeleted(void *);
bool GcIsDeleted(void *);
void GcMapPtrToValue(void *ptr, VALUE val);
VALUE GcGetValueFromPtr(void *ptr);
void GcFreefunc(void *);
%}

%include "typedefs.i"
%include "typemap.i"

#
# Protect certain classes from the GC
#
%define GC_NEVER(kls)
%feature("freefunc") kls "GcFreefunc";
%enddef

#
# This may do something someday
#
%define GC_ALWAYS(klass)
%enddef
