// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxLog
GC_MANAGE(wxLog);

%ignore wxLog::OnLog;

%include "include/wxLog.h"
