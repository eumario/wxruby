// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxToolBarToolBase;
GC_MANAGE_AS_OBJECT(wxToolBarToolBase);

%{
#include <wx/toolbar.h>
%}

#define wxToolBarBase wxToolBar

%rename(ToolBarTool) wxToolBarToolBase;

%import "include/wxObject.h"
%include "include/wxToolBarToolBase.h"
