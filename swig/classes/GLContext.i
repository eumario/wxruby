// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGLContext
GC_MANAGE_AS_OBJECT(wxGLContext);

%{
#ifdef __WXMAC__
static int _T_DATA = T_DATA;
#undef T_DATA
#endif
#include <wx/glcanvas.h>
#ifdef __WXMAC__
#define T_DATA _T_DATA
#endif
%}

%import "include/wxObject.h"
%import "include/wxGLCanvas.h"

%include "include/wxGLContext.h"
