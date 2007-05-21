// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxLayoutAlgorithm
GC_MANAGE_AS_OBJECT(wxLayoutAlgorithm);

%{
#include <wx/laywin.h>
%}

%import "include/wxObject.h"

%include "include/wxLayoutAlgorithm.h"
