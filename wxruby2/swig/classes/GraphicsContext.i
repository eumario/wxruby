// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGraphicsContext;
GC_MANAGE_AS_OBJECT(wxGraphicsContext);

%{
#include <wx/graphics.h>
%}

%ignore wxGraphicsContext(wxGraphicsRenderer* renderer);
%ignore wxGraphicsContext::CreateFromNative;
%ignore wxGraphicsContext::CreateFromNativeWindow;

%import  "include/wxObject.h"
%import  "include/wxGraphicsObject.h"

%include "include/wxGraphicsContext.h"
