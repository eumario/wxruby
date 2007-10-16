// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxListItemAttr
GC_MANAGE(wxListItemAttr);

%{
#include "wx/listbase.h"
%}

%include "include/wxListItemAttr.h"
