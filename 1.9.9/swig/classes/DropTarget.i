// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDropTarget
GC_MANAGE_AS_OBJECT(wxDropTarget);

%{
#include <wx/dnd.h>
%}

%include "include/wxDropTarget.h"
