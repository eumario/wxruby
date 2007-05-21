// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxHtmlCell
GC_MANAGE_AS_OBJECT(wxHtmlCell);

%{
#include <wx/html/htmlcell.h>
%}

%import "include/wxObject.h"

%include "include/wxHtmlCell.h"
