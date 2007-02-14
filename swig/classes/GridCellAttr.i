// Copyright 2004-2007 by Kevin Smith
// released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGridCellAttr

%{
#include <wx/grid.h>
%}

%apply SWIGTYPE *DISOWN { wxGridCellEditor* editor };
%apply SWIGTYPE *DISOWN { wxGridCellRenderer* renderer };

// This is to get arround SWIG trying to call a protected destructor
%nodefaultdtor wxGridCellAttr;

%include "include/wxGridCellAttr.h"

