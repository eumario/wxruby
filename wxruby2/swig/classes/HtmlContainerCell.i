// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxHtmlContainerCell
GC_MANAGE_AS_OBJECT(wxHtmlContainerCell);

%{
#include <wx/html/htmlcell.h>
%}

%import "include/wxObject.h"
%import "include/wxHtmlCell.h"

%include "include/wxHtmlContainerCell.h"
