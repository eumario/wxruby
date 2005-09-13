#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGridCellAttr

%{
#include <wx/grid.h>
%}

#This is to get arround SWIG trying to call a protected destructor
%nodefault wxGridCellAttr;

%include "include/wxGridCellAttr.h"

