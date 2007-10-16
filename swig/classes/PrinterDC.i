// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPrinterDC
GC_MANAGE_AS_OBJECT(wxPrinterDC);

%import "include/wxObject.h"
%import "include/wxDC.h"

%include "include/wxPrinterDC.h"
