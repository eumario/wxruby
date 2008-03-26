// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGrid
GC_MANAGE_AS_WINDOW(wxGrid);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxGrid);


// All of the methods have alternate versions that accept row, col pair
// of integers, so these are redundant
%ignore wxGrid::CellToRect( const wxGridCellCoords& coords );
%ignore wxGrid::GetCellValue( wxGridCellCoords& coords );
%ignore wxGrid::IsInSelection( const wxGridCellCoords& coords ) const;
%ignore wxGrid::IsVisible( const wxGridCellCoords& coords, 
                           bool wholeCellVisible = true );
%ignore wxGrid::MakeCellVisible( const wxGridCellCoords& coords );
%ignore wxGrid::SelectBlock( const wxGridCellCoords& topLeft,
                    const wxGridCellCoords& bottomRight,
                    bool addToSelected = false );
%ignore wxGrid::SetCellValue( const wxGridCellCoords& coords, 
                              const wxString& s );

/* check these are working 
  void GetDefaultCellAlignment( int *horiz, int *vert );
  void GetColLabelAlignment( int *horiz, int *vert );
  wxGridCellEditor* GetDefaultEditorForCell(const wxGridCellCoords& c) const;
  void GetRowLabelAlignment( int *horiz, int *vert );
*/

/* May need additional wrapping
  wxGridCellCoordsArray GetSelectedCells() const;
  wxGridCellCoordsArray GetSelectionBlockTopLeft() const;
  wxGridCellCoordsArray GetSelectionBlockBottomRight() const;
*/
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
