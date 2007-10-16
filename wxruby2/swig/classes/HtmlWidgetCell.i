// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxHtmlWidgetCell
GC_MANAGE_AS_OBJECT(wxHtmlWidgetCell);

%{
#include <wx/html/htmlcell.h>
%}

%import "include/wxObject.h"
%import "include/wxHtmlCell.h"

%include "include/wxHtmlWidgetCell.h"
