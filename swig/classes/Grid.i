#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGrid

%{
#include <wx/grid.h>
%}

%ignore wxGrid::wxGrid();
%ignore wxGrid::wxGrid(wxWindow*  parent , int  x , int  y , int  w = -1, int  h = -1, long  style = wxWANTS_CHARS, const wxString&  name = wxPanelNameStr);
%ignore wxGrid::SelectionToDeviceRect;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxScrolledWindow.h"

%include "include/wxGrid.h"
