# Copyright 2004-2006 by Kevin Smith
# released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxHtmlWidgetCell

%{
#include <wx/html/htmlcell.h>
%}

%import "include/wxObject.h"
%import "include/wxHtmlCell.h"

%include "include/wxHtmlWidgetCell.h"
