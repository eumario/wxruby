#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxGrid

%{
#include <wx/grid.h>
%}

%ignore wxGrid::wxGrid();
%ignore wxGrid::wxGrid(wxWindow*  parent , int  x , int  y , int  w = -1, int  h = -1, long  style = wxWANTS_CHARS, const wxString&  name = wxPanelNameStr);
%ignore wxGrid::SelectionToDeviceRect;

%include "include/wxGrid.h"

