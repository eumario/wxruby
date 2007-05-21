// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxTextAttr;
GC_MANAGE(wxTextAttr);

%{
#include <wx/textctrl.h>
%}

%include "include/wxTextAttr.h"
