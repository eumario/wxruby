// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxAuiDefaultDockArt
GC_MANAGE(wxAuiDefaultDockArt);

%{
#include <wx/aui/aui.h>
%}

%import "include/wxAuiDockArt.h"
%include "include/wxAuiDefaultDockArt.h"
