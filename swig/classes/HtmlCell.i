// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxHtmlCell
GC_MANAGE_AS_OBJECT(wxHtmlCell);

%{
#include <wx/html/htmlcell.h>
%}

%import "include/wxObject.h"

%include "include/wxHtmlCell.h"
