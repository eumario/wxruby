// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGrid
GC_MANAGE_AS_WINDOW(wxGrid);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxGrid);

%{
#include <wx/grid.h>
%}

// The main memory management for this class is done in Ruby in
// lib/wx/classes/grid.rb because the wxWidgets wxGrid public API does
// not make it easy to write an efficient C++ markfunc that preserves
// the required objects. For an attempt, see SVN:1163
//
// Here, we simply tell SWIG that once these three classes have been
// applied, they are owned and will be cleaned up by wxWidgets, and so
// should not be freed by Ruby.
%apply SWIGTYPE *DISOWN { wxGridCellAttr* attr };
%apply SWIGTYPE *DISOWN { wxGridCellEditor* editor };
%apply SWIGTYPE *DISOWN { wxGridCellRenderer* renderer };

// If invalid grid-cell co-ordinates are passed into wxWidgets,
// segfaults may result, so check to avoid this.
%typemap(check) int row, int col {
  if ( $1 < 0 )
    rb_raise(rb_eIndexError, "Negative grid cell co-ordinate is not valid");
}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"
%import "include/wxScrolledWindow.h"

%include "include/wxGrid.h"
