// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxLogTextCtrl
GC_MANAGE(wxLogTextCtrl);

%import "include/wxLog.h"

%include "include/wxLogTextCtrl.h"
