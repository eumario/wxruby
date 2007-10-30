// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxFileDropTarget
GC_MANAGE_AS_OBJECT(wxFileDropTarget);

%{
#include <wx/dnd.h>
%}

%ignore OnDrop;
%ignore OnData;  

%import "include/wxDropTarget.h"

%include "include/wxFileDropTarget.h"
