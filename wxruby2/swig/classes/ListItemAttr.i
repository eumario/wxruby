// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxListItemAttr
GC_MANAGE(wxListItemAttr);

%{
#include "wx/listbase.h"
%}

%include "include/wxListItemAttr.h"
