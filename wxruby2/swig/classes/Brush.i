// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxBrush
GC_MANAGE_AS_OBJECT(wxBrush);

%import "include/wxObject.h"
%import "include/wxGDIObject.h"

%include "include/wxBrush.h"
