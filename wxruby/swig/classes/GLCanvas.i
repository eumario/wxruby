// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGLCanvas
GC_MANAGE_AS_WINDOW(wxGLCanvas);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxGLCanvas);

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

enum
{
    WX_GL_RGBA = 1,
    WX_GL_BUFFER_SIZE,
    WX_GL_LEVEL,
    WX_GL_DOUBLEBUFFER,
    WX_GL_STEREO,
    WX_GL_AUX_BUFFERS,
    WX_GL_MIN_RED,
    WX_GL_MIN_GREEN,
    WX_GL_MIN_BLUE,
    WX_GL_MIN_ALPHA, 
    WX_GL_DEPTH_SIZE,
    WX_GL_STENCIL_SIZE,
    WX_GL_MIN_ACCUM_RED,
    WX_GL_MIN_ACCUM_GREEN,
    WX_GL_MIN_ACCUM_BLUE,
    WX_GL_MIN_ACCUM_ALPHA
};

%typemap(typecheck) (int* attribList) {
  $1 = CLASS_OF($input)==rb_cArray ? 1 : 0;
}

%typemap(in) (int* attribList) (int sz, int i) {
  sz = NUM2INT(rb_funcall($input, rb_intern("size"), 0, NULL));
  $1 = (int *) malloc(sizeof(int)*(sz+1));
  for (i=0; i<sz; i++) {
    $1[i] = NUM2INT(rb_ary_entry($input, i));
  }
  $1[sz] = 0;
}

%typemap(freearg) (int* attribList) {
  free((void *) $1);
}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

%include "include/wxGLCanvas.h"
