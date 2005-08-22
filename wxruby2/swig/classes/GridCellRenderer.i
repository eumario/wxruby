#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGridCellRenderer
%feature("nodirector") wxGridCellRenderer;  // abstract base class

%{
//NO_DIRECTOR
#include <wx/grid.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%include "include/wxGridCellRenderer.h"
