// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGraphicsMatrix
GC_MANAGE_AS_OBJECT(wxGraphicsMatrix);

%{
#include <wx/graphics.h>
%}

// Avoid shadowing warnings
%ignore wxGraphicsMatrix::Concat(const wxGraphicsMatrix& t);
%ignore wxGraphicsMatrix::IsEqual(const wxGraphicsMatrix& t);

// Deal with GraphicsMatrix#get method
%apply double *OUTPUT { wxDouble *a, wxDouble *b,
                        wxDouble *c, wxDouble *d,
                        wxDouble *tx , wxDouble *ty };


%import "include/wxObject.h"
%import "include/wxGraphicsObject.h"
%include "include/wxGraphicsMatrix.h"

