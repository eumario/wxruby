// wxGrid.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGrid_h_)
#define _wxGrid_h_
class wxGrid : public wxScrolledWindow
{
public:
	/**
	 * \brief Default constructor 
	*/

   wxGrid() ;
	/**
	 * \brief Constructor to create a grid object. Call either   or 
  directly after this to initialize the grid before using
it. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	*/

   wxGrid(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxWANTS_CHARS, const wxString&  name = wxPanelNameStr) ;
	/**
	 * \brief Destructor. This will also destroy the associated grid table unless you passed a table
object to the grid and specified that the grid should not take ownership of the
table (see  ). 
	*/

  virtual  ~wxGrid() ;
	/**
	 * \brief Appends one or more new columns to the right of the grid and returns true if
successful. The updateLabels argument is not used at present.

If you are using a derived grid table class you will need to override 
 . See 
  for further information. 
	 * \param int   
	 * \param bool   
	*/

  bool AppendCols(int  numCols = 1, bool  updateLabels = true) ;
	/**
	 * \brief Appends one or more new rows to the bottom of the grid and returns true if
successful. The updateLabels argument is not used at present.

If you are using a derived grid table class you will need to override 
 . See 
  for further information. 
	 * \param int   
	 * \param bool   
	*/

  bool AppendRows(int  numRows = 1, bool  updateLabels = true) ;
	/**
	 * \brief Automatically sets the height and width of all rows and columns to fit their contents. 
	*/

  void AutoSize() ;
	/**
	 * \brief Automatically sizes the column to fit its contents. If setAsMin is true the calculated width will
also be set as the minimal width for the column. 
	 * \param int   
	 * \param bool   
	*/

  void AutoSizeColumn(int  col , bool  setAsMin = true) ;
	/**
	 * \brief Automatically sizes all columns to fit their contents. If setAsMin is true the calculated widths will
also be set as the minimal widths for the columns. 
	 * \param bool   
	*/

  void AutoSizeColumns(bool  setAsMin = true) ;
	/**
	 * \brief Automatically sizes the row to fit its contents. If setAsMin is true the calculated height will
also be set as the minimal height for the row. 
	 * \param int   
	 * \param bool   
	*/

  void AutoSizeRow(int  row , bool  setAsMin = true) ;
	/**
	 * \brief Automatically sizes all rows to fit their contents. If setAsMin is true the calculated heights will
also be set as the minimal heights for the rows. 
	 * \param bool   
	*/

  void AutoSizeRows(bool  setAsMin = true) ;
	/**
	 * \brief Increments the grid's batch count. When the count is greater than zero repainting of
the grid is suppressed. Each call to BeginBatch must be matched by a later call to 
 . Code that does a lot of grid
modification can be enclosed between BeginBatch and EndBatch calls to avoid
screen flicker. The final EndBatch will cause the grid to be repainted. 
	*/

  void BeginBatch() ;
	/**
	 * \brief Returns true if columns can be resized by dragging with the mouse. Columns can be resized
by dragging the edges of their labels. If grid line dragging is enabled they can also be
resized by dragging the right edge of the column in the grid cell area 
(see  ). 
	*/

  bool CanDragColSize() ;
	/**
	 * \brief Returns true if rows can be resized by dragging with the mouse. Rows can be resized
by dragging the edges of their labels. If grid line dragging is enabled they can also be
resized by dragging the lower edge of the row in the grid cell area 
(see  ). 
	*/

  bool CanDragRowSize() ;
	/**
	 * \brief Return true if the dragging of grid lines to resize rows and columns is enabled or false otherwise. 
	*/

  bool CanDragGridSize() ;
	/**
	 * \brief Returns true if the in-place edit control for the current grid cell can be used and
false otherwise (e.g. if the current cell is read-only). 
	*/

  bool CanEnableCellControl() const;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  wxRect CellToRect(int  row , int  col ) ;
	/**
	 * \brief Return the rectangle corresponding to the grid cell's size and position in logical
coordinates. 
	 * \param const wxGridCellCoords&   
	*/

  wxRect CellToRect(const wxGridCellCoords&  coords ) ;
	/**
	 * \brief Clears all data in the underlying grid table and repaints the grid. The table is not deleted by
this function. If you are using a derived table class then you need to override 
  for this function to have any effect. 
	*/

  void ClearGrid() ;
	/**
	 * \brief Deselects all cells that are currently selected. 
	*/

  void ClearSelection() ;
	/**
	 * \brief Creates a grid with the specified initial number of rows and columns.
Call this directly after the grid constructor. When you use this
function wxGrid will create and manage a simple table of string values
for you. All of the grid data will be stored in memory.

For applications with more complex data types or relationships, or for
dealing with very large datasets, you should derive your own grid table
class and pass a table object to the grid with  . 
	 * \param int   
	 * \param int   
	 * \param wxGrid::wxGridSelectionModes   
	*/

  bool CreateGrid(int  numRows , int  numCols , wxGrid::wxGridSelectionModes  selmode = wxGrid::wxGridSelectCells) ;
	/**
	 * \brief Deletes one or more columns from a grid starting at the specified position and returns
true if successful. The updateLabels argument is not used at present.

If you are using a derived grid table class you will need to override 
 . See 
  for further information. 
	 * \param int   
	 * \param int   
	 * \param bool   
	*/

  bool DeleteCols(int  pos = 0, int  numCols = 1, bool  updateLabels = true) ;
	/**
	 * \brief Deletes one or more rows from a grid starting at the specified position and returns
true if successful. The updateLabels argument is not used at present.

If you are using a derived grid table class you will need to override 
 . See 
  for further information. 
	 * \param int   
	 * \param int   
	 * \param bool   
	*/

  bool DeleteRows(int  pos = 0, int  numRows = 1, bool  updateLabels = true) ;
	/**
	 * \brief Disables in-place editing of grid cells. 
Equivalent to calling EnableCellEditControl(false). 
	*/

  void DisableCellEditControl() ;
	/**
	 * \brief Disables column sizing by dragging with the mouse. Equivalent to passing false to 
 . 
	*/

  void DisableDragColSize() ;
	/**
	 * \brief Disable mouse dragging of grid lines to resize rows and columns. Equivalent to passing
false to 
	*/

  void DisableDragGridSize() ;
	/**
	 * \brief Disables row sizing by dragging with the mouse. Equivalent to passing false to 
 . 
	*/

  void DisableDragRowSize() ;
	/**
	 * \brief Enables or disables in-place editing of grid cell data. The grid will issue either a
wxEVT_GRID_EDITOR_SHOWN or wxEVT_GRID_EDITOR_HIDDEN event. 
	 * \param bool   
	*/

  void EnableCellEditControl(bool  enable = true) ;
	/**
	 * \brief Enables or disables column sizing by dragging with the mouse. 
	 * \param bool   
	*/

  void EnableDragColSize(bool  enable = true) ;
	/**
	 * \brief Enables or disables row and column resizing by dragging gridlines with the mouse. 
	 * \param bool   
	*/

  void EnableDragGridSize(bool  enable = true) ;
	/**
	 * \brief Enables or disables row sizing by dragging with the mouse. 
	 * \param bool   
	*/

  void EnableDragRowSize(bool  enable = true) ;
	/**
	 * \brief If the edit argument is false this function sets the whole grid as read-only. If the
argument is true the grid is set to the default state where cells may be editable. In the
default state you can set single grid cells and whole rows and columns to be editable or
read-only via 
 . For single
cells you can also use the shortcut function 
 . 

For more information about controlling grid cell attributes see the 
  cell attribute class and the 
 . 
	 * \param bool   
	*/

  void EnableEditing(bool  edit ) ;
	/**
	 * \brief Turns the drawing of grid lines on or off. 
	 * \param bool   
	*/

  void EnableGridLines(bool  enable = true) ;
	/**
	 * \brief Decrements the grid's batch count. When the count is greater than zero repainting of
the grid is suppressed. Each previous call to 
  must be matched by a later call to
EndBatch. Code that does a lot of grid modification can be enclosed between
BeginBatch and EndBatch calls to avoid screen flicker. The final EndBatch will
cause the grid to be repainted. 
	*/

  void EndBatch() ;
	/**
	 * \brief Causes immediate repainting of the grid. Use this instead of the usual wxWindow::Refresh. 
	*/

  void ForceRefresh() ;
	/**
	 * \brief Returns the number of times that   has been called
without (yet) matching calls to  . While
the grid's batch count is greater than zero the display will not be updated. 
	*/

  int GetBatchCount() ;
	/**
	 * \brief Sets the arguments to the horizontal and vertical text alignment values for the
grid cell at the specified location.

Horizontal alignment will be one of wxALIGN_LEFT, wxALIGN_CENTRE or wxALIGN_RIGHT.  
Vertical alignment will be one of wxALIGN_TOP, wxALIGN_CENTRE or wxALIGN_BOTTOM.

\perlnote{This method only takes the parameters   and   and
returns a 2-element list  .} 
	 * \param int   
	 * \param int   
	 * \param int*   
	 * \param int*   
	*/

  void GetCellAlignment(int  row , int  col , int*  horiz , int*  vert ) ;
	/**
	 * \brief Returns the background colour of the cell at the specified location. 
	 * \param int   
	 * \param int   
	*/

  wxColour GetCellBackgroundColour(int  row , int  col ) ;
	/**
	 * \brief Returns a pointer to the editor for the cell at the specified location.

See   and
the   for more information about cell editors and renderers. 
	 * \param int   
	 * \param int   
	*/

  wxGridCellEditor* GetCellEditor(int  row , int  col ) ;
	/**
	 * \brief Returns the font for text in the grid cell at the specified location. 
	 * \param int   
	 * \param int   
	*/

  wxFont GetCellFont(int  row , int  col ) ;
	/**
	 * \brief Returns a pointer to the renderer for the grid cell at the specified location.

See   and
the   for more information about cell editors and renderers. 
	 * \param int   
	 * \param int   
	*/

  wxGridCellRenderer* GetCellRenderer(int  row , int  col ) ;
	/**
	 * \brief Returns the text colour for the grid cell at the specified location. 
	 * \param int   
	 * \param int   
	*/

  wxColour GetCellTextColour(int  row , int  col ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  wxString GetCellValue(int  row , int  col ) ;
	/**
	 * \brief Returns the string contained in the cell at the specified location. For simple applications where a
grid object automatically uses a default grid table of string values you use this function together
with   to access cell values. 

For more complex applications where you have derived your own grid table class that contains
various data types (e.g. numeric, boolean or user-defined custom types) then you only use this
function for those cells that contain string values. 

See  
and the   for more information. 
	 * \param const wxGridCellCoords&  
	*/

  wxString GetCellValue(const wxGridCellCoords& coords ) ;
	/**
	 * \brief Sets the arguments to the current column label alignment values.

Horizontal alignment will be one of wxLEFT, wxCENTRE or wxRIGHT.  
Vertical alignment will be one of wxTOP, wxCENTRE or wxBOTTOM.

\perlnote{This method takes no parameters and
returns a 2-element list  .} 
	 * \param int*   
	 * \param int*   
	*/

  void GetColLabelAlignment(int*  horiz , int*  vert ) ;
	/**
	 * \brief Returns the current height of the column labels. 
	*/

  int GetColLabelSize() ;
	/**
	 * \brief Returns the specified column label. The default grid table class provides column labels of
the form A,B...Z,AA,AB...ZZ,AAA... If you are using a custom grid table you can override 
  to provide
your own labels. 
	 * \param int   
	*/

  wxString GetColLabelValue(int  col ) ;
	/**
	 * \brief Returns the width of the specified column. 
	 * \param int   
	*/

  int GetColSize(int  col ) ;
	/**
	 * \brief Sets the arguments to the current default horizontal and vertical text alignment
values.

Horizontal alignment will be one of wxALIGN_LEFT, wxALIGN_CENTRE or wxALIGN_RIGHT.  
Vertical alignment will be one of wxALIGN_TOP, wxALIGN_CENTRE or wxALIGN_BOTTOM. 
	 * \param int*   
	 * \param int*   
	*/

  void GetDefaultCellAlignment(int*  horiz , int*  vert ) ;
	/**
	 * \brief Returns the current default background colour for grid cells. 
	*/

  wxColour GetDefaultCellBackgroundColour() ;
	/**
	 * \brief Returns the current default font for grid cell text. 
	*/

  wxFont GetDefaultCellFont() ;
	/**
	 * \brief Returns the current default colour for grid cell text. 
	*/

  wxColour GetDefaultCellTextColour() ;
	/**
	 * \brief Returns the default height for column labels. 
	*/

  int GetDefaultColLabelSize() ;
	/**
	 * \brief Returns the current default width for grid columns. 
	*/

  int GetDefaultColSize() ;
	/**
	 * \brief Returns a pointer to the current default grid cell editor.

See   and
the   for more information about cell editors and renderers. 
	*/

  wxGridCellEditor* GetDefaultEditor() const;
	/**
	 * \brief Returns a pointer to the current default grid cell renderer.

See   and
the   for more information about cell editors and renderers. 
	*/

  wxGridCellRenderer* GetDefaultRenderer() const;
	/**
	 * \brief Returns the default width for the row labels. 
	*/

  int GetDefaultRowLabelSize() ;
	/**
	 * \brief Returns the current default height for grid rows. 
	*/

  int GetDefaultRowSize() ;
	/**
	 * \brief Returns the current grid cell column position. 
	*/

  int GetGridCursorCol() ;
	/**
	 * \brief Returns the current grid cell row position. 
	*/

  int GetGridCursorRow() ;
	/**
	 * \brief Returns the colour used for grid lines. 
	*/

  wxColour GetGridLineColour() ;
	/**
	 * \brief Returns true if drawing of grid lines is turned on, false otherwise. 
	*/

  bool GridLinesEnabled() ;
	/**
	 * \brief Returns the colour used for the background of row and column labels. 
	*/

  wxColour GetLabelBackgroundColour() ;
	/**
	 * \brief Returns the font used for row and column labels. 
	*/

  wxFont GetLabelFont() ;
	/**
	 * \brief Returns the colour used for row and column label text. 
	*/

  wxColour GetLabelTextColour() ;
	/**
	 * \brief Returns the total number of grid columns (actually the number of columns in the underlying grid
table). 
	*/

  int GetNumberCols() ;
	/**
	 * \brief Returns the total number of grid rows (actually the number of rows in the underlying grid table). 
	*/

  int GetNumberRows() ;
	/**
	 * \brief Sets the arguments to the current row label alignment values.

Horizontal alignment will be one of wxLEFT, wxCENTRE or wxRIGHT.  
Vertical alignment will be one of wxTOP, wxCENTRE or wxBOTTOM.

\perlnote{This method takes no parameters and
returns a 2-element list  .} 
	 * \param int*   
	 * \param int*   
	*/

  void GetRowLabelAlignment(int*  horiz , int*  vert ) ;
	/**
	 * \brief Returns the current width of the row labels. 
	*/

  int GetRowLabelSize() ;
	/**
	 * \brief Returns the specified row label. The default grid table class provides numeric row labels.
If you are using a custom grid table you can override 
  to provide
your own labels. 
	 * \param int   
	*/

  wxString GetRowLabelValue(int  row ) ;
	/**
	 * \brief Returns the height of the specified row. 
	 * \param int   
	*/

  int GetRowSize(int  row ) ;
	/**
	 * \brief Returns the current selection mode, see  . 
	*/

  wxGrid::wxGridSelectionModes GetSelectionMode() const;
	/**
	 * \brief Returns an array of singly selected cells. 
	*/

  wxGridCellCoordsArray GetSelectedCells() const;
	/**
	 * \brief Returns an array of selected cols. 
	*/

  wxArrayInt GetSelectedCols() const;
	/**
	 * \brief Returns an array of selected rows. 
	*/

  wxArrayInt GetSelectedRows() const;
	/**
	 * \brief Returns an array of the top left corners of blocks of selected cells, 
see  . 
	*/

  wxGridCellCoordsArray GetSelectionBlockTopLeft() const;
	/**
	 * \brief Returns an array of the bottom right corners of blocks of selected cells,
see  . 
	*/

  wxGridCellCoordsArray GetSelectionBlockBottomRight() const;
	/**
	 * \brief Returns a base pointer to the current table object. 
	*/

  wxGridTableBase * GetTable() const;
	/**
	 * \brief Hides the in-place cell edit control. 
	*/

  void HideCellEditControl() ;
	/**
	 * \brief Inserts one or more new columns into a grid with the first new column at the
specified position and returns true if successful. The updateLabels argument is not
used at present. 

The sequence of actions begins with the grid object requesting the underlying grid
table to insert new columns. If this is successful the table notifies the grid and the
grid updates the display. For a default grid (one where you have called 
 ) this process is automatic. If you are
using a custom grid table (specified with  ) 
then you must override 
  in your derived
table class. 
	 * \param int   
	 * \param int   
	 * \param bool   
	*/

  bool InsertCols(int  pos = 0, int  numCols = 1, bool  updateLabels = true) ;
	/**
	 * \brief Inserts one or more new rows into a grid with the first new row at the specified
position and returns true if successful. The updateLabels argument is not used at
present. 

The sequence of actions begins with the grid object requesting the underlying grid
table to insert new rows. If this is successful the table notifies the grid and the
grid updates the display. For a default grid (one where you have called 
 ) this process is automatic. If you are
using a custom grid table (specified with  ) 
then you must override 
  in your derived
table class. 
	 * \param int   
	 * \param int   
	 * \param bool   
	*/

  bool InsertRows(int  pos = 0, int  numRows = 1, bool  updateLabels = true) ;
	/**
	 * \brief Returns true if the in-place edit control is currently enabled. 
	*/

  bool IsCellEditControlEnabled() const;
	/**
	 * \brief Returns true if the current cell has been set to read-only
(see  ). 
	*/

  bool IsCurrentCellReadOnly() const;
	/**
	 * \brief Returns false if the whole grid has been set as read-only or true otherwise.
See   for more information about
controlling the editing status of grid cells. 
	*/

  bool IsEditable() ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  bool IsInSelection(int  row , int  col ) const;
	/**
	 * \brief Is this cell currently selected. 
	 * \param const wxGridCellCoords&   
	*/

  bool IsInSelection(const wxGridCellCoords&  coords ) const;
	/**
	 * \brief Returns true if the cell at the specified location can't be edited.
See also  . 
	 * \param int   
	 * \param int   
	*/

  bool IsReadOnly(int  row , int  col ) const;
	/**
	 * \brief Returns true if there are currently rows, columns or blocks of cells selected. 
	*/

  bool IsSelection() ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param bool   
	*/

  bool IsVisible(int  row , int  col , bool  wholeCellVisible = true) ;
	/**
	 * \brief Returns true if a cell is either wholly visible (the default) or at least partially
visible in the grid window. 
	 * \param const wxGridCellCoords&   
	 * \param bool   
	*/

  bool IsVisible(const wxGridCellCoords&  coords , bool  wholeCellVisible = true) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  void MakeCellVisible(int  row , int  col ) ;
	/**
	 * \brief Brings the specified cell into the visible grid cell area with minimal scrolling. Does
nothing if the cell is already visible. 
	 * \param const wxGridCellCoords&   
	*/

  void MakeCellVisible(const wxGridCellCoords&  coords ) ;
	/**
	 * \brief Moves the grid cursor down by one row. If a block of cells was previously selected it
will expand if the argument is true or be cleared if the argument is false.

\wxheading{Keyboard} 
This function is called for Down cursor key presses or Shift+Down to expand a selection. 
	 * \param bool   
	*/

  bool MoveCursorDown(bool  expandSelection ) ;
	/**
	 * \brief Moves the grid cursor left by one column. If a block of cells was previously selected it
will expand if the argument is true or be cleared if the argument is false.

\wxheading{Keyboard} 
This function is called for Left cursor key presses or Shift+Left to expand a selection. 
	 * \param bool   
	*/

  bool MoveCursorLeft(bool  expandSelection ) ;
	/**
	 * \brief Moves the grid cursor right by one column. If a block of cells was previously selected it
will expand if the argument is true or be cleared if the argument is false.

\wxheading{Keyboard} 
This function is called for Right cursor key presses or Shift+Right to expand a selection. 
	 * \param bool   
	*/

  bool MoveCursorRight(bool  expandSelection ) ;
	/**
	 * \brief Moves the grid cursor up by one row. If a block of cells was previously selected it
will expand if the argument is true or be cleared if the argument is false.

\wxheading{Keyboard} 
This function is called for Up cursor key presses or Shift+Up to expand a selection. 
	 * \param bool   
	*/

  bool MoveCursorUp(bool  expandSelection ) ;
	/**
	 * \brief Moves the grid cursor down in the current column such that it skips to the beginning or
end of a block of non-empty cells. If a block of cells was previously selected it
will expand if the argument is true or be cleared if the argument is false.

\wxheading{Keyboard} 
This function is called for the Ctrl+Down key combination. Shift+Ctrl+Down expands a selection. 
	 * \param bool   
	*/

  bool MoveCursorDownBlock(bool  expandSelection ) ;
	/**
	 * \brief Moves the grid cursor left in the current row such that it skips to the beginning or
end of a block of non-empty cells. If a block of cells was previously selected it
will expand if the argument is true or be cleared if the argument is false.

\wxheading{Keyboard} 
This function is called for the Ctrl+Left key combination. Shift+Ctrl+left expands a selection. 
	 * \param bool   
	*/

  bool MoveCursorLeftBlock(bool  expandSelection ) ;
	/**
	 * \brief Moves the grid cursor right in the current row such that it skips to the beginning or
end of a block of non-empty cells. If a block of cells was previously selected it
will expand if the argument is true or be cleared if the argument is false.

\wxheading{Keyboard} 
This function is called for the Ctrl+Right key combination. Shift+Ctrl+Right expands a selection. 
	 * \param bool   
	*/

  bool MoveCursorRightBlock(bool  expandSelection ) ;
	/**
	 * \brief Moves the grid cursor up in the current column such that it skips to the beginning or
end of a block of non-empty cells. If a block of cells was previously selected it
will expand if the argument is true or be cleared if the argument is false.

\wxheading{Keyboard} 
This function is called for the Ctrl+Up key combination. Shift+Ctrl+Up expands a selection. 
	 * \param bool   
	*/

  bool MoveCursorUpBlock(bool  expandSelection ) ;
	/**
	 * \brief Moves the grid cursor down by some number of rows so that the previous bottom visible row
becomes the top visible row.

\wxheading{Keyboard} 
This function is called for PgDn keypresses. 
	*/

  bool MovePageDown() ;
	/**
	 * \brief Moves the grid cursor up by some number of rows so that the previous top visible row
becomes the bottom visible row.

\wxheading{Keyboard} 
This function is called for PgUp keypresses. 
	*/

  bool MovePageUp() ;
	/**
	 * \brief Sets the value of the current grid cell to the current in-place edit control value.
This is called automatically when the grid cursor moves from the current cell to a
new cell. It is also a good idea to call this function when closing a grid since
any edits to the final cell location will not be saved otherwise. 
	*/

  void SaveEditControlValue() ;
	/**
	 * \brief Selects all cells in the grid. 
	*/

  void SelectAll() ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param bool   
	*/

  void SelectBlock(int  topRow , int  leftCol , int  bottomRow , int  rightCol , bool  addToSelected = false) ;
	/**
	 * \brief Selects a rectangular block of cells. If addToSelected is false then any existing selection will be
deselected; if true the column will be added to the existing selection. 
	 * \param const wxGridCellCoords&   
	 * \param const wxGridCellCoords&   
	 * \param bool   
	*/

  void SelectBlock(const wxGridCellCoords&  topLeft , const wxGridCellCoords&  bottomRight , bool  addToSelected = false) ;
	/**
	 * \brief Selects the specified column. If addToSelected is false then any existing selection will be
deselected; if true the column will be added to the existing selection. 
	 * \param int   
	 * \param bool   
	*/

  void SelectCol(int  col , bool  addToSelected = false) ;
	/**
	 * \brief Selects the specified row. If addToSelected is false then any existing selection will be
deselected; if true the row will be added to the existing selection. 
	 * \param int   
	 * \param bool   
	*/

  void SelectRow(int  row , bool  addToSelected = false) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	*/

  void SetCellAlignment(int  row , int  col , int  horiz , int  vert ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param int   
	*/

  void SetCellAlignment(int  align , int  row , int  col ) ;
	/**
	 * \brief Sets the horizontal and vertical alignment for grid cell text at the specified location.

Horizontal alignment should be one of wxALIGN_LEFT, wxALIGN_CENTRE or wxALIGN_RIGHT.  
Vertical alignment should be one of wxALIGN_TOP, wxALIGN_CENTRE or wxALIGN_BOTTOM. 
	 * \param int   
	*/

  void SetCellAlignment(int  align ) ;
	/**
	 * \brief Sets the editor for the grid cell at the specified location. 
The grid will take ownership of the pointer.

See   and
the   for more information about cell editors and renderers. 
	 * \param int   
	 * \param int   
	 * \param wxGridCellEditor*   
	*/

  void SetCellEditor(int  row , int  col , wxGridCellEditor*  editor ) ;
	/**
	 * \brief Sets the font for text in the grid cell at the specified location. 
	 * \param int   
	 * \param int   
	 * \param const wxFont&  
	*/

  void SetCellFont(int  row , int  col , const wxFont&  font ) ;
	/**
	 * \brief Sets the renderer for the grid cell at the specified location. 
The grid will take ownership of the pointer.

See   and
the   for more information about cell editors and renderers. 
	 * \param int   
	 * \param int   
	 * \param wxGridCellRenderer*   
	*/

  void SetCellRenderer(int  row , int  col , wxGridCellRenderer*  renderer ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param const wxColour&  
	*/

  void SetCellTextColour(int  row , int  col , const wxColour&  colour ) ;
	/**
	 * \brief  
	 * \param const wxColour&   
	 * \param int   
	 * \param int   
	*/

  void SetCellTextColour(const wxColour&  val , int  row , int  col ) ;
	/**
	 * \brief Sets the text colour for the grid cell at the specified location. 
	 * \param const wxColour&   
	*/

  void SetCellTextColour(const wxColour&  colour ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param const wxString&   
	*/

  void SetCellValue(int  row , int  col , const wxString&  s ) ;
	/**
	 * \brief  
	 * \param const wxGridCellCoords&   
	 * \param const wxString&   
	*/

  void SetCellValue(const wxGridCellCoords&  coords , const wxString&  s ) ;
	/**
	 * \brief Sets the string value for the cell at the specified location. For simple applications where a
grid object automatically uses a default grid table of string values you use this function together
with   to access cell values. 

For more complex applications where you have derived your own grid table class that contains
various data types (e.g. numeric, boolean or user-defined custom types) then you only use this
function for those cells that contain string values.

The last form is for backward compatibility only.

See  
and the   for more information. 
	 * \param const wxString&   
	 * \param int   
	 * \param int   
	*/

  void SetCellValue(const wxString&  val , int  row , int  col ) ;
	/**
	 * \brief Sets the cell attributes for all cells in the specified column.

For more information about controlling grid cell attributes see the 
  cell attribute class and the 
 . 
	 * \param int   
	 * \param wxGridCellAttr*   
	*/

  void SetColAttr(int  col , wxGridCellAttr*  attr ) ;
	/**
	 * \brief Sets the specified column to display boolean values. wxGrid displays boolean values with a checkbox. 
	 * \param int   
	*/

  void SetColFormatBool(int  col ) ;
	/**
	 * \brief Sets the specified column to display integer values. 
	 * \param int   
	*/

  void SetColFormatNumber(int  col ) ;
	/**
	 * \brief Sets the specified column to display floating point values with the given width and precision. 
	 * \param int   
	 * \param int   
	 * \param int   
	*/

  void SetColFormatFloat(int  col , int  width = -1, int  precision = -1) ;
	/**
	 * \brief Sets the specified column to display data in a custom format.
See the   for more information on working
with custom data types. 
	 * \param int   
	 * \param const wxString&   
	*/

  void SetColFormatCustom(int  col , const wxString&  typeName ) ;
	/**
	 * \brief Sets the horizontal and vertical alignment of column label text.

Horizontal alignment should be one of wxALIGN_LEFT, wxALIGN_CENTRE or wxALIGN_RIGHT.

Vertical alignment should be one of wxALIGN_TOP, wxALIGN_CENTRE or wxALIGN_BOTTOM. 
	 * \param int   
	 * \param int   
	*/

  void SetColLabelAlignment(int  horiz , int  vert ) ;
	/**
	 * \brief Sets the height of the column labels. 
	 * \param int   
	*/

  void SetColLabelSize(int  height ) ;
	/**
	 * \brief Set the value for the given column label. If you are using a derived grid table you must 
override  
for this to have any effect. 
	 * \param int   
	 * \param const wxString&  
	*/

  void SetColLabelValue(int  col , const wxString&  value ) ;
	/**
	 * \brief Sets the minimal width for the specified column. This should normally be called when creating the grid
because it will not resize a column that is already narrower than the minimal width.
The width argument must be higher than the minimimal acceptable column width, see
 . 
	 * \param int   
	 * \param int   
	*/

  void SetColMinimalWidth(int  col , int  width ) ;
	/**
	 * \brief This modifies the minimum column width that can be handled correctly. Specifying a low value here
allows smaller grid cells to be dealt with correctly. Specifying a value here which is much smaller
than the actual minimum size will incur a performance penalty in the functions which perform
grid cell index lookup on the basis of screen coordinates.
This should normally be called when creating the grid because it will not resize existing columns
with sizes smaller than the value specified here. 
	 * \param int   
	*/

  void SetColMinimalAcceptableWidth(int  width ) ;
	/**
	 * \brief This returns the value of the lowest column width that can be handled correctly. See
member   for details. 
	*/

  int GetColMinimalAcceptableWidth() ;
	/**
	 * \brief Sets the width of the specified column. 

This function does not refresh the grid. If you are calling it outside of a BeginBatch / EndBatch
block you can use   to see the changes. 

Automatically sizes the column to fit its contents. If setAsMin is true the calculated width will
also be set as the minimal width for the column. 
	 * \param int   
	 * \param int   
	*/

  void SetColSize(int  col , int  width ) ;
	/**
	 * \brief Sets the default horizontal and vertical alignment for grid cell text.

Horizontal alignment should be one of wxALIGN_LEFT, wxALIGN_CENTRE or wxALIGN_RIGHT.

Vertical alignment should be one of wxALIGN_TOP, wxALIGN_CENTRE or wxALIGN_BOTTOM. 
	 * \param int   
	 * \param int   
	*/

  void SetDefaultCellAlignment(int  horiz , int  vert ) ;
	/**
	 * \brief Sets the default background colour for grid cells. 
	 * \param const wxColour&  
	*/

  void SetDefaultCellBackgroundColour(const wxColour&  colour ) ;
	/**
	 * \brief Sets the default font to be used for grid cell text. 
	 * \param const wxFont&  
	*/

  void SetDefaultCellFont(const wxFont&  font ) ;
	/**
	 * \brief Sets the default editor for grid cells. The grid will take ownership of the pointer.

See   and
the   for more information about cell editors and renderers. 
	 * \param wxGridCellEditor*   
	*/

  void SetDefaultEditor(wxGridCellEditor*  editor ) ;
	/**
	 * \brief Sets the default renderer for grid cells. The grid will take ownership of the pointer.

See   and
the   for more information about cell editors and renderers. 
	 * \param wxGridCellRenderer*   
	*/

  void SetDefaultRenderer(wxGridCellRenderer*  renderer ) ;
	/**
	 * \brief Sets the default width for columns in the grid. This will only affect columns subsequently added to
the grid unless resizeExistingCols is true. 
	 * \param int   
	 * \param bool   
	*/

  void SetDefaultColSize(int  width , bool  resizeExistingCols = false) ;
	/**
	 * \brief Sets the default height for rows in the grid. This will only affect rows subsequently added
to the grid unless resizeExistingRows is true. 
	 * \param int   
	 * \param bool   
	*/

  void SetDefaultRowSize(int  height , bool  resizeExistingRows = false) ;
	/**
	 * \brief Set the grid cursor to the specified cell. 
This function calls  . 
	 * \param int   
	 * \param int   
	*/

  void SetGridCursor(int  row , int  col ) ;
	/**
	 * \brief Sets the colour used to draw grid lines. 
	 * \param const wxColour&  
	*/

  void SetGridLineColour(const wxColour& colour ) ;
	/**
	 * \brief Sets the background colour for row and column labels. 
	 * \param const wxColour&  
	*/

  void SetLabelBackgroundColour(const wxColour&  colour ) ;
	/**
	 * \brief Sets the font for row and column labels. 
	 * \param const wxFont&  
	*/

  void SetLabelFont(const wxFont&  font ) ;
	/**
	 * \brief Sets the colour for row and column label text. 
	 * \param const wxColour&  
	*/

  void SetLabelTextColour(const wxColour&  colour ) ;
	/**
	 * \brief Makes the cell at the specified location read-only or editable.
See also  . 
	 * \param int   
	 * \param int   
	 * \param bool   
	*/

  void SetReadOnly(int  row , int  col , bool  isReadOnly = true) ;
	/**
	 * \brief Sets the cell attributes for all cells in the specified row.
See the   class for more information
about controlling cell attributes. 
	 * \param int   
	 * \param wxGridCellAttr*   
	*/

  void SetRowAttr(int  row , wxGridCellAttr*  attr ) ;
	/**
	 * \brief Sets the horizontal and vertical alignment of row label text.

Horizontal alignment should be one of wxALIGN_LEFT, wxALIGN_CENTRE or wxALIGN_RIGHT.

Vertical alignment should be one of wxALIGN_TOP, wxALIGN_CENTRE or wxALIGN_BOTTOM. 
	 * \param int   
	 * \param int   
	*/

  void SetRowLabelAlignment(int  horiz , int  vert ) ;
	/**
	 * \brief Sets the width of the row labels. 
	 * \param int   
	*/

  void SetRowLabelSize(int  width ) ;
	/**
	 * \brief Set the value for the given row label. If you are using a derived grid table you must 
override   
for this to have any effect. 
	 * \param int   
	 * \param const wxString&  
	*/

  void SetRowLabelValue(int  row , const wxString&  value ) ;
	/**
	 * \brief Sets the minimal height for the specified row. This should normally be called when creating the grid
because it will not resize a row that is already shorter than the minimal height.
The height argument must be higher than the minimimal acceptable row height, see
 . 
	 * \param int   
	 * \param int   
	*/

  void SetRowMinimalHeight(int  row , int  height ) ;
	/**
	 * \brief This modifies the minimum row width that can be handled correctly. Specifying a low value here
allows smaller grid cells to be dealt with correctly. Specifying a value here which is much smaller
than the actual minimum size will incur a performance penalty in the functions which perform
grid cell index lookup on the basis of screen coordinates.
This should normally be called when creating the grid because it will not resize existing rows
with sizes smaller than the value specified here. 
	 * \param int   
	*/

  void SetRowMinimalAcceptableHeight(int  height ) ;
	/**
	 * \brief This returns the value of the lowest row width that can be handled correctly. See
member   for details. 
	*/

  int GetRowMinimalAcceptableHeight() ;
	/**
	 * \brief Sets the height of the specified row. 

This function does not refresh the grid. If you are calling it outside of a BeginBatch / EndBatch
block you can use   to see the changes. 

Automatically sizes the column to fit its contents. If setAsMin is true the calculated width will
also be set as the minimal width for the column. 
	 * \param int   
	 * \param int   
	*/

  void SetRowSize(int  row , int  height ) ;
	/**
	 * \brief Set the selection behaviour of the grid. 
	 * \param wxGrid::wxGridSelectionModes  
	*/

  void SetSelectionMode(wxGrid::wxGridSelectionModes  selmode ) ;
	/**
	 * \brief Passes a pointer to a custom grid table to be used by the grid. This should be called
after the grid constructor and before using the grid object. If takeOwnership is set to
true then the table will be deleted by the wxGrid destructor. 

Use this function instead of   when your
application involves complex or non-string data or data sets that are too large to fit
wholly in memory. 
	 * \param wxGridTableBase*   
	 * \param bool   
	 * \param wxGrid::wxGridSelectionModes   
	*/

  bool SetTable(wxGridTableBase*  table , bool  takeOwnership = false, wxGrid::wxGridSelectionModes  selmode = wxGrid::wxGridSelectCells) ;
	/**
	 * \brief Displays the in-place cell edit control for the current cell. 
	*/

  void ShowCellEditControl() ;
	/**
	 * \brief Returns the grid column that corresponds to the logical x coordinate. Returns
wxNOT_FOUND if there is no column at the x position. 
	 * \param int   
	*/

  int XToCol(int  x ) ;
	/**
	 * \brief Returns the column whose right hand edge is close to the given logical x position.
If no column edge is near to this position wxNOT_FOUND is returned. 
	 * \param int   
	*/

  int XToEdgeOfCol(int  x ) ;
	/**
	 * \brief Returns the row whose bottom edge is close to the given logical y position.
If no row edge is near to this position wxNOT_FOUND is returned. 
	 * \param int   
	*/

  int YToEdgeOfRow(int  y ) ;
	/**
	 * \brief Returns the grid row that corresponds to the logical y coordinate. Returns
wxNOT_FOUND if there is no row at the y position. 
	 * \param int   
	*/

  int YToRow(int  y ) ;
	/**
	 * \brief This function returns the rectangle that encloses the block of cells
limited by TopLeft and BottomRight cell in device coords and clipped
to the client size of the grid window. 
	 * \param const wxGridCellCoords &   
	 * \param const wxGridCellCoords &   
	*/

  wxRect BlockToDeviceRect(const wxGridCellCoords &  topLeft , const wxGridCellCoords &  bottomRight ) ;
	/**
	 * \brief This function returns the rectangle that encloses the selected cells
in device coords and clipped to the client size of the grid window. 
	*/

  wxRect SelectionToDeviceRect() ;
	/**
	 * \brief Access or update the selection fore/back colours 
	*/

  wxColour GetSelectionBackground() const;
	/**
	 * \brief  
	*/

  wxColour GetSelectionForeground() const;
	/**
	 * \brief  
	 * \param const wxColour&   
	*/

  void SetSelectionBackground(const wxColour&  c ) ;
	/**
	 * \brief  
	 * \param const wxColour&   
	*/

  void SetSelectionForeground(const wxColour&  c ) ;
	/**
	 * \brief Methods for a registry for mapping data types to Renderers/Editors 
	 * \param const wxString&   
	 * \param wxGridCellRenderer*   
	 * \param wxGridCellEditor*   
	*/

  void RegisterDataType(const wxString&  typeName , wxGridCellRenderer*  renderer , wxGridCellEditor*  editor ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  wxGridCellEditor* GetDefaultEditorForCell(int  row , int  col ) const;
	/**
	 * \brief  
	 * \param const wxGridCellCoords&   
	*/

  wxGridCellEditor* GetDefaultEditorForCell(const wxGridCellCoords&  c ) const;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  wxGridCellRenderer* GetDefaultRendererForCell(int  row , int  col ) const;
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  wxGridCellEditor* GetDefaultEditorForType(const wxString&  typeName ) const;
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  wxGridCellRenderer* GetDefaultRendererForType(const wxString&  typeName ) const;
	/**
	 * \brief A grid may occupy more space than needed for its rows/columns. This
function allows to set how big this extra space is 
	 * \param int   
	 * \param int   
	*/

  void SetMargins(int  extraWidth , int  extraHeight ) ;
	/**
	 * \brief Backward compatibility. 
	 * \param wxWindow*   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param long   
	 * \param const wxString&   
	*/

   wxGrid(wxWindow*  parent , int  x , int  y , int  w = -1, int  h = -1, long  style = wxWANTS_CHARS, const wxString&  name = wxPanelNameStr) ;
	/**
	 * \brief Backward compatibility. 
	*/

  void UpdateDimensions() ;
	/**
	 * \brief Backward compatibility. 
	*/

  int GetRows() ;
	/**
	 * \brief Backward compatibility. 
	*/

  int GetCols() ;
	/**
	 * \brief Backward compatibility. 
	*/

  int GetCursorRow() ;
	/**
	 * \brief Backward compatibility. 
	*/

  int GetCursorColumn() ;
	/**
	 * \brief Backward compatibility. 
	*/

  int GetScrollPosX() ;
	/**
	 * \brief Backward compatibility. 
	*/

  int GetScrollPosY() ;
	/**
	 * \brief Backward compatibility. 
	 * \param int   
	*/

  void SetScrollX(int  x ) ;
	/**
	 * \brief Backward compatibility. 
	 * \param int   
	*/

  void SetScrollY(int  y ) ;
	/**
	 * \brief Backward compatibility. 
	 * \param int   
	 * \param int   
	*/

  void SetColumnWidth(int  col , int  width ) ;
	/**
	 * \brief Backward compatibility. 
	 * \param int   
	*/

  int GetColumnWidth(int  col ) ;
	/**
	 * \brief Backward compatibility. 
	 * \param int   
	 * \param int   
	*/

  void SetRowHeight(int  row , int  height ) ;
	/**
	 * \brief Backward compatibility. 
	*/

  int GetViewHeight() ;
	/**
	 * \brief Returned number of whole cols visible. 
	*/

  int GetViewWidth() ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  void SetLabelSize(int  orientation , int  sz ) ;
	/**
	 * \brief  
	 * \param int   
	*/

  int GetLabelSize(int  orientation ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  void SetLabelAlignment(int  orientation , int  align ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  int GetLabelAlignment(int  orientation , int  align ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param const wxString&   
	 * \param int   
	*/

  void SetLabelValue(int  orientation , const wxString&  val , int  pos ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  wxString GetLabelValue(int  orientation , int  pos ) ;
	/**
	 * \brief  
	*/

  wxFont GetCellTextFont() const;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  wxFont GetCellTextFont(int  row , int  col ) const;
	/**
	 * \brief  
	 * \param const wxFont&   
	*/

  void SetCellTextFont(const wxFont&  fnt ) ;
	/**
	 * \brief  
	 * \param const wxFont&   
	 * \param int   
	 * \param int   
	*/

  void SetCellTextFont(const wxFont&  fnt , int  row , int  col ) ;
	/**
	 * \brief  
	 * \param const wxColour&   
	*/

  void SetCellBackgroundColour(const wxColour&  col ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param const wxColour&  
	*/

  void SetCellBackgroundColour(int  row , int  col , const wxColour&  colour ) ;
	/**
	 * \brief  
	 * \param const wxColour&   
	 * \param int   
	 * \param int   
	*/

  void SetCellBackgroundColour(const wxColour&  colour , int  row , int  col ) ;
	/**
	 * \brief  
	*/

  bool GetEditable() ;
	/**
	 * \brief  
	 * \param bool   
	*/

  void SetEditable(bool  edit = true) ;
	/**
	 * \brief  
	*/

  bool GetEditInPlace() ;
	/**
	 * \brief  
	 * \param bool   
	*/

  void SetEditInPlace(bool  edit = true) ;
	/**
	 * \brief  
	 * \param wxBitmap*   
	 * \param int   
	 * \param int   
	*/

  void SetCellBitmap(wxBitmap*  bitmap , int  row , int  col ) ;
	/**
	 * \brief  
	 * \param const wxPen&   
	*/

  void SetDividerPen(const wxPen&  pen ) ;
	/**
	 * \brief  
	*/

  wxPen& GetDividerPen() const;
	/**
	 * \brief  
	 * \param bool   
	*/

  virtual void OnActivate(bool  active ) ;
	/**
	 * \brief Overridden wxWindow methods 
	*/

  void Fit() ;
	/**
	 * \brief  
	*/

  ;
	/**
	 * \brief NB:   access m_row/col arrays directly because they are created
on demand,   use accessor functions instead!

Init the m_rowHeights/Bottoms arrays with default values. 
	*/

  ;
	/**
	 * \brief Init the m_colWidths/Rights arrays 
	*/

  ;
	/**
	 * \brief Get the col/row coords 
	 * \param int   
	*/

  ;
	/**
	 * \brief  
	 * \param int   
	*/

  ;
	/**
	 * \brief  
	 * \param int   
	*/

  ;
	/**
	 * \brief This function must be public for compatibility. 
	 * \param int   
	*/

  ;
	/**
	 * \brief  
	 * \param int   
	*/

  ;
	/**
	 * \brief  
	 * \param int   
	*/

  ;
	/**
	 * \brief Common part of AutoSizeColumn/Row() and GetBestSize() 
	 * \param bool   
	 * \param bool   
	*/

  ;
	/**
	 * \brief  
	 * \param bool   
	 * \param bool   
	*/

  ;
	/**
	 * \brief Common part of AutoSizeColumn/Row() or row? 
	 * \param int   
	 * \param bool   
	 * \param bool   
	*/

  ;
	/**
	 * \brief get the minimal width of the given column/row 
	 * \param int   
	*/

  ;
	/**
	 * \brief  
	 * \param int   
	*/

  ;
	/**
	 * \brief Do we have some place to store attributes in? 
	*/

  ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  ;
};


#endif
