// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxHtmlWidgetCell
GC_MANAGE_AS_OBJECT(wxHtmlWidgetCell);

%{
#include <wx/html/htmlcell.h>
%}

%import "include/wxObject.h"
%import "include/wxHtmlCell.h"

%include "include/wxHtmlWidgetCell.h"
