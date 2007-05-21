// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxHtmlLinkInfo
GC_MANAGE_AS_OBJECT(wxHtmlLinkInfo);

%{
#include <wx/html/htmlcell.h>
%}

// for some reason this ignore doesn't actually ignore
// so then there is a problem b/c the 'redirect' string isn't 
// mapped as output

%import "include/wxObject.h"

%include "include/wxHtmlLinkInfo.h"
