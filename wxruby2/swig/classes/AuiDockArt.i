// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxAuiDockArt
GC_MANAGE(wxAuiDockArt);

%{
#include <wx/aui/aui.h>
%}

%include "include/wxAuiDockArt.h"
