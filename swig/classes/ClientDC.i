// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxClientDC
GC_MANAGE_AS_OBJECT(wxClientDC);

%import "include/wxObject.h"
%import "include/wxDC.h"
%import "include/wxWindowDC.h"

%include "include/wxClientDC.h"
