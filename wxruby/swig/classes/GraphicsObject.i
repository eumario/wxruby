// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxGraphicsObject
GC_MANAGE_AS_OBJECT(wxGraphicsObject);

%{
#include <wx/graphics.h>
%}

%ignore wxGraphicsObject::GetRenderer;

%import  "include/wxObject.h"
%include  "include/wxGraphicsObject.h"

