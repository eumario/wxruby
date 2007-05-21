// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxBrush
GC_MANAGE_AS_OBJECT(wxBrush);

%import "include/wxObject.h"
%import "include/wxGDIObject.h"

%include "include/wxBrush.h"
