// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTextDropTarget
GC_MANAGE_AS_OBJECT(wxTextDropTarget);

%{
#include <wx/dnd.h>
%}

%ignore OnDrop;
%ignore OnData;  

// Use C++ implementations, don't call into Ruby
%feature("nodirector") OnData;

%import "include/wxDropTarget.h"

%include "include/wxTextDropTarget.h"
