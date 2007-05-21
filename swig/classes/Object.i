// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxObject
GC_MANAGE_AS_OBJECT(wxObject);

%ignore wxObject(wxObject const &other);
%ignore wxObject::Dump;

%include "include/wxObject.h"
