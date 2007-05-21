// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxPrintDialogData
GC_MANAGE_AS_OBJECT(wxPrintDialogData);

%import "include/wxObject.h"

%include "include/wxPrintDialogData.h"
