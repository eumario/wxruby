// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxAuiDockArt
GC_MANAGE(wxAuiDockArt);

%{
#include <wx/aui/aui.h>
%}

%include "include/wxAuiDockArt.h"
