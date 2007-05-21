// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxMemoryDC
GC_MANAGE_AS_OBJECT(wxMemoryDC);

%import "include/wxObject.h"
// TODO: Figure out why the following line causes swig 
// to remove the allocator for this class
//%import "include/wxDC.h"

%include "include/wxMemoryDC.h"
