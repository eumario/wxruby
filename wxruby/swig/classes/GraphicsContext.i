// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGraphicsContext;
GC_MANAGE_AS_OBJECT(wxGraphicsContext);

%{
#include <wx/graphics.h>
%}


// Typemap to fix GraphicsContext#get_text_extent
%apply double *OUTPUT { wxDouble* width, wxDouble* height, 
                        wxDouble* descent, wxDouble* externalLeading }

%typemap(directorargout) ( wxDouble* width, wxDouble* height, 
                           wxDouble* descent, wxDouble* externalLeading) {
  if ( (TYPE(result) == T_ARRAY) && (RARRAY_LEN(result) >= 2) )
    {
      *$1 = ($*1_ltype)NUM2INT(rb_ary_entry(result,0));
      *$2 = ($*2_ltype)NUM2INT(rb_ary_entry(result,1));
      if ( ($3 != NULL ) && RARRAY_LEN(result) >= 3)
        *$3 = ($*3_ltype)NUM2INT(rb_ary_entry(result,2));
      if ( ( $4 != NULL ) && RARRAY_LEN(result) >= 4 )
        *$4 = ($*4_ltype)NUM2INT(rb_ary_entry(result,3));
    }
}

%ignore wxGraphicsContext(wxGraphicsRenderer* renderer);
%ignore wxGraphicsContext::CreateFromNative;
%ignore wxGraphicsContext::CreateFromNativeWindow;

%import  "include/wxObject.h"
%import  "include/wxGraphicsObject.h"

%include "include/wxGraphicsContext.h"
