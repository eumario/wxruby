#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

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

void GcMarkDeleted(void *);
bool GcIsDeleted(void *);
%}

%include "typedefs.i"
%include "typemap.i"
