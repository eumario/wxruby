#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGridCellRenderer
%feature("nodirector") wxGridCellRenderer;

%{
#include <wx/grid.h>
%}

%include "include/wxGridCellRenderer.h"

