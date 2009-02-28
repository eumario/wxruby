// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxGraphicsFont
GC_MANAGE_AS_OBJECT(wxGraphicsFont);

%{
#include <wx/graphics.h>
%}

%import "include/wxObject.h"
%import "include/wxGraphicsObject.h"
%include "include/wxGraphicsFont.h"

