// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxClientDC
GC_MANAGE_AS_OBJECT(wxClientDC);

%import "include/wxObject.h"
%import "include/wxDC.h"
%import "include/wxWindowDC.h"

%include "include/wxClientDC.h"
