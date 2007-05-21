// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxHtmlContainerCell
GC_MANAGE_AS_OBJECT(wxHtmlContainerCell);

%{
#include <wx/html/htmlcell.h>
%}

%import "include/wxObject.h"
%import "include/wxHtmlCell.h"

%include "include/wxHtmlContainerCell.h"
