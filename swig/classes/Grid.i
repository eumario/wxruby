// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGrid
GC_MANAGE_AS_WINDOW(wxGrid);

%{
#include <wx/grid.h>
%}

// Because cells, rows and columns may have Editors and Renderers
// associated with them, and because these two classes require
// directors, they must be preserved when ruby's GC runs it mark
// phase. The function below deals with the marking of renderers and
// editors that are associated with individual cells, and the default
// ones for the whole Wx::Grid.
// 
// Because SetColAttr and SetRowAttr may indirectly set editors or
// renderers for a whole column or row, we also need to handle
// those. Unfortunately, as of wxWidgets 2.8.3, there does not appear to
// be any way to retrieve those attributes directly; there is no
// GetRowAttr method, and neither GetCellEditor nor
// GetOrCreateCellAttr->GetEditor return the required values. Therefore,
// special treatment is given to those ruby methods in
// lib/wx/classes/grid.rb
%{
  static void mark_wxGrid(void *ptr)
	{
	  if ( GC_IsWindowDeleted(ptr) )
		return;
	  GC_mark_wxWindow(ptr);
	  
	  wxGrid* wx_grid = (wxGrid*)ptr;

	  wxGridCellEditor* default_editor = wx_grid->GetDefaultEditor();
	  rb_gc_mark( SWIG_RubyInstanceFor( default_editor) );

	  wxGridCellRenderer* default_renderer = wx_grid->GetDefaultRenderer();
	  rb_gc_mark( SWIG_RubyInstanceFor( default_renderer) );

	  int rows = wx_grid->GetNumberRows();
	  int cols = wx_grid->GetNumberCols();

	  wxGridCellEditor* editor;
	  wxGridCellRenderer* renderer;

	  for ( int x = 0; x < rows; x++ )
		{
		  for ( int y = 0; y < cols; y++ )
			{
			  wxGridCellAttr *attr = wx_grid->GetOrCreateCellAttr(x, y);
			  if ( attr->HasEditor() )
				{
				  editor = attr->GetEditor(wx_grid, x, y);
				  rb_gc_mark( SWIG_RubyInstanceFor(editor) );
				}
			  if ( attr->HasRenderer() )
				{
				  renderer = attr->GetRenderer(wx_grid, x, y);
				  rb_gc_mark( SWIG_RubyInstanceFor(renderer) );
				}
			}
		}
	  return;
	}
%}

%markfunc wxGrid "mark_wxGrid"

%apply SWIGTYPE *DISOWN { wxGridCellAttr* attr };
%apply SWIGTYPE *DISOWN { wxGridCellEditor* editor };
%apply SWIGTYPE *DISOWN { wxGridCellRenderer* renderer };

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"
%import "include/wxScrolledWindow.h"

%include "include/wxGrid.h"
