// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridCellRenderer
GC_MANAGE(wxGridCellRenderer);

%feature("nodirector") wxGridCellRenderer::GetBestSize;

%{
#include <wx/grid.h>
%}

%include "include/wxGridCellRenderer.h"
