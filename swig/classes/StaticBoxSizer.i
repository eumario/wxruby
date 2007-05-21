// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxStaticBoxSizer
GC_MANAGE_AS_OBJECT(wxStaticBoxSizer);

%import "include/wxObject.h"
%import "include/wxSizer.h"
%import "include/wxBoxSizer.h"

%include "include/wxStaticBoxSizer.h"
