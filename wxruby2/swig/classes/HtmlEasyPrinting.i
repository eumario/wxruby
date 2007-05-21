// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxHtmlEasyPrinting
GC_MANAGE_AS_OBJECT(wxHtmlEasyPrinting);

%{
#include <wx/html/htmprint.h>
%}


%import "include/wxObject.h"

%include "include/wxHtmlEasyPrinting.h"
