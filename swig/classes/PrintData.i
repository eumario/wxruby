// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxPrintData
GC_MANAGE_AS_OBJECT(wxPrintData);

%import "include/wxObject.h"

%include "include/wxPrintData.h"
