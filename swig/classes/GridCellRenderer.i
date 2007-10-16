// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGridCellRenderer
GC_MANAGE(wxGridCellRenderer);

%feature("nodirector") wxGridCellRenderer::GetBestSize;

%{
#include <wx/grid.h>
%}

%include "include/wxGridCellRenderer.h"
