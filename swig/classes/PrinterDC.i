// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxPrinterDC
GC_MANAGE_AS_OBJECT(wxPrinterDC);

%import "include/wxObject.h"
%import "include/wxDC.h"

%include "include/wxPrinterDC.h"
