// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxAuiDefaultDockArt
GC_MANAGE(wxAuiDefaultDockArt);

%{
// Workaround for wx's auibar.h incompatibility 2.8.10 with OS X compiler
// Should be fixed by future wxWidgets 
#ifdef __WXMAC__
#define id toolid
#endif

#include <wx/aui/aui.h>
%}

%import "include/wxAuiDockArt.h"
%include "include/wxAuiDefaultDockArt.h"
