// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxBogus
GC_MANAGE(wxBogus);

%{
#include "../swig/classes/include/wxBogus.h"
%}

%include "include/wxBogus.h"
