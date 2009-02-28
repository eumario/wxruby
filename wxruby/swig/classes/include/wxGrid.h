// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGrid_h_)
#define _wxGrid_h_
class wxGrid : public wxScrolledWindow
{
 public:
  wxGrid() ;

  wxGrid( wxWindow *parent,
          wxWindowID id,
          const wxPoint& pos = wxDefaultPosition,
          const wxSize& size = wxDefaultSize,
          long style = wxWANTS_CHARS,
          const wxString& name = wxPanelNameStr );

  bool Create( wxWindow *parent,
               wxWindowID id,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxWANTS_CHARS,
               const wxString& name = wxPanelNameStr );

  virtual ~wxGrid();




  enum wxGridSelectionModes {wxGridSelectCells,
                             wxGridSelectRows,
                             wxGridSelectColumns};

  bool AppendCols( int numCols = 1, bool updateLabels = true );
  bool AppendRows( int numRows = 1, bool updateLabels = true );
  void AutoSize();
  void AutoSizeColumn( int col, bool setAsMin = true );
  void AutoSizeColumns( bool setAsMin = true );
  void AutoSizeRow( int row, bool setAsMin = true );
  void AutoSizeRows( bool setAsMin = true );
  void BeginBatch();
  wxRect BlockToDeviceRect( const wxGridCellCoords & topLeft,
                            const wxGridCellCoords & bottomRight );

  bool CanDragColMove();
  bool CanDragColSize();
  bool CanDragRowSize();
  bool CanDragGridSize();
  bool CanEnableCellControl() const;
  // bool CanHaveAttributes();  // protected
  wxRect CellToRect( int row, int col );
  wxRect CellToRect( const wxGridCellCoords& coords );
  void ClearGrid();
  void ClearSelection();
  bool CreateGrid( int numRows, int numCols,
                   wxGrid::wxGridSelectionModes selmode =
                   wxGrid::wxGridSelectCells );
  bool DeleteCols( int pos = 0, int numCols = 1, bool updateLabels = true );
  bool DeleteRows( int pos = 0, int numRows = 1, bool updateLabels = true );
  void DisableCellEditControl();
  void DisableDragColMove();
  void DisableDragColSize();
  void DisableDragGridSize();
  void DisableDragRowSize();
  void EnableCellEditControl( bool enable = true );
  void EnableDragColMove();
  void EnableDragColSize( bool enable = true );
  void EnableDragGridSize(bool enable = true);
  void EnableDragRowSize( bool enable = true );
  void EnableEditing( bool edit );
  void EnableGridLines( bool enable = true );
  void EndBatch();
  void Fit();
  void ForceRefresh();
  int GetBatchCount();
  void GetCellAlignment( int row, int col, int *horiz, int *vert );
  wxColour GetCellBackgroundColour( int row, int col );
  wxGridCellEditor* GetCellEditor(int row, int col);
  wxFont GetCellFont( int row, int col );
  wxGridCellRenderer* GetCellRenderer(int row, int col);
  wxColour GetCellTextColour( int row, int col );
  wxString GetCellValue( int row, int col );
  wxString GetCellValue( const wxGridCellCoords& coords );
  int GetColAt( int colPos );
  // int GetColLeft(int col) const; // protected
  void GetColLabelAlignment( int *horiz, int *vert );
  int GetColLabelSize();
  wxString GetColLabelValue( int col );
  int GetColMinimalAcceptableWidth();
  // int GetColMinimalWidth(int col) const; // protected
  int GetColPos( int colID ) const;
  // int GetColRight(int col) const; // protected
  int GetColSize( int col );
  void GetDefaultCellAlignment( int *horiz, int *vert );
  wxColour GetDefaultCellBackgroundColour();
  wxFont GetDefaultCellFont();
  wxColour GetDefaultCellTextColour();
  int GetDefaultColLabelSize();
  int GetDefaultColSize();
  wxGridCellEditor *GetDefaultEditor() const;
  wxGridCellEditor* GetDefaultEditorForCell(int row, int col) const;
  wxGridCellEditor* GetDefaultEditorForCell(const wxGridCellCoords& c) const;
  wxGridCellEditor* GetDefaultEditorForType(const wxString& typeName) const;
  wxGridCellRenderer* GetDefaultRenderer() const;
  wxGridCellRenderer* GetDefaultRendererForCell(int row, int col) const;
  wxGridCellRenderer* GetDefaultRendererForType(const wxString& typeName) const;
  int GetDefaultRowLabelSize();
  int GetDefaultRowSize();
  int GetGridCursorCol();
  int GetGridCursorRow();
  wxColour GetGridLineColour();
  virtual wxPen GetColGridLinePen(int col);
  virtual wxPen GetDefaultGridLinePen();
  virtual wxPen GetRowGridLinePen(int row);
  bool GridLinesEnabled();
  wxColour GetLabelBackgroundColour();
  wxFont GetLabelFont();
  wxColour GetLabelTextColour();
  int GetNumberCols();
  int GetNumberRows();
  wxGridCellAttr *GetOrCreateCellAttr(int row, int col) const;
  int GetRowMinimalAcceptableHeight();
  // int GetRowMinimalHeight(int col) const; // protected
  void GetRowLabelAlignment( int *horiz, int *vert );
  int GetRowLabelSize();
  wxString GetRowLabelValue( int row );
  int GetRowSize( int row );
  int GetScrollLineX() const;
  int GetScrollLineY() const;
  wxGrid::wxGridSelectionModes GetSelectionMode() const;
  wxGridCellCoordsArray GetSelectedCells() const;
  wxArrayInt GetSelectedCols() const;
  wxArrayInt GetSelectedRows() const;
  wxColour GetSelectionBackground() const;
  wxGridCellCoordsArray GetSelectionBlockBottomRight() const;
  wxGridCellCoordsArray GetSelectionBlockTopLeft() const;
  wxColour GetSelectionForeground() const;
  wxGridTableBase* GetTable() const;
  int GetViewWidth();
  void HideCellEditControl();
  bool InsertCols( int pos = 0, int numCols = 1, bool updateLabels = true );
  bool InsertRows( int pos = 0, int numRows = 1, bool updateLabels = true );
  bool IsCellEditControlEnabled() const;
  bool IsCurrentCellReadOnly() const;
  bool IsEditable() const;
  bool IsInSelection( int row, int col ) const;
  bool IsInSelection( const wxGridCellCoords& coords ) const;
  bool IsReadOnly(int row, int col) const;
  bool IsSelection();
  bool IsVisible( int row, int col, bool wholeCellVisible = true );
  bool IsVisible( const wxGridCellCoords& coords, bool wholeCellVisible = true );  
  void MakeCellVisible( int row, int col );
  void MakeCellVisible( const wxGridCellCoords& coords );
  bool MoveCursorDown( bool expandSelection );
  bool MoveCursorLeft( bool expandSelection );
  bool MoveCursorRight( bool expandSelection );
  bool MoveCursorUp( bool expandSelection );
  bool MoveCursorDownBlock( bool expandSelection );
  bool MoveCursorLeftBlock( bool expandSelection );
  bool MoveCursorRightBlock( bool expandSelection );
  bool MoveCursorUpBlock( bool expandSelection );
  bool MovePageDown();
  bool MovePageUp();
  void RegisterDataType(const wxString& typeName,
                        wxGridCellRenderer* renderer,
                        wxGridCellEditor* editor);
  void SaveEditControlValue();
  void SelectAll();
  void SelectBlock( int topRow, int leftCol, int bottomRow, int rightCol,
                    bool addToSelected = false );

  void SelectBlock( const wxGridCellCoords& topLeft,
                    const wxGridCellCoords& bottomRight,
                    bool addToSelected = false );

  void SelectCol( int col, bool addToSelected = false );
  // wxRect SelectionToDeviceRect(); // missing in wx 2.8.7?
  void SelectRow( int row, bool addToSelected = false );
  void SetCellAlignment( int row, int col, int horiz, int vert );
  void SetCellBackgroundColour( int row, int col, const wxColour& );
  void SetCellEditor(int row, int col, wxGridCellEditor *editor);
  void SetCellFont( int row, int col, const wxFont& );
  void SetCellRenderer(int row, int col, wxGridCellRenderer *renderer);
  void SetCellTextColour( int row, int col, const wxColour& );
  void SetCellValue( int row, int col, const wxString& s );
  void SetCellValue( const wxGridCellCoords& coords, const wxString& s );
  void SetColAttr(int col, wxGridCellAttr *attr);
  void SetColFormatBool(int col);
  void SetColFormatNumber(int col);
  void SetColFormatFloat(int col, int width = -1, int precision = -1);
  void SetColFormatCustom(int col, const wxString& typeName);
  void SetColLabelAlignment( int horiz, int vert );
  void SetColLabelTextOrientation( int textOrientation ); 
  void SetColLabelSize( int height );
  void SetColLabelValue( int col, const wxString& );
  void SetColMinimalAcceptableWidth( int width );
  void SetColMinimalWidth( int col, int width );
  void SetColPos(int colID, int newPos);
  void SetColSize( int col, int width );
  void SetDefaultCellAlignment( int horiz, int vert );
  void SetDefaultCellBackgroundColour( const wxColour& );
  void SetDefaultCellFont( const wxFont& );
  void SetDefaultCellTextColour( const wxColour& );
  void SetDefaultEditor(wxGridCellEditor *editor);
  void SetDefaultRenderer(wxGridCellRenderer *renderer);
  void SetDefaultColSize( int width, bool resizeExistingCols = false );
  void SetDefaultRowSize( int height, bool resizeExistingRows = false );
  void SetGridCursor( int row, int col );
  void SetGridLineColour( const wxColour& );
  void SetLabelBackgroundColour( const wxColour& );
  void SetLabelFont( const wxFont& );
  void SetLabelTextColour( const wxColour& );
  void SetMargins(int extraWidth, int extraHeight);
  void SetReadOnly(int row, int col, bool isReadOnly = true);
  void SetRowAttr(int row, wxGridCellAttr *attr);
  void SetRowLabelAlignment( int horiz, int vert );
  void SetRowLabelSize( int width );
  void SetRowLabelValue( int row, const wxString& );
  void SetRowMinimalAcceptableHeight( int height );
  void SetRowMinimalHeight( int row, int height );
  void SetRowSize( int row, int height );
  void SetScrollLineX(int x);
  void SetScrollLineY(int y);
  void SetSelectionBackground(const wxColour& c);
  void SetSelectionForeground(const wxColour& c);
  void SetSelectionMode(wxGrid::wxGridSelectionModes selmode);
  bool SetTable( wxGridTableBase *table, bool takeOwnership = false,
                 wxGrid::wxGridSelectionModes selmode =
                 wxGrid::wxGridSelectCells );
  void ShowCellEditControl();
  int XToCol( int x );
  int XToEdgeOfCol( int x );
  int YToEdgeOfRow( int y );
  int YToRow( int y );


  // THe following methods were in the autogenerated file, but are not
  // part of the public documented API in wxWidgets 2.8.7. Some appear to be
  // private implementation methods, some may be deprecated in 2.8, and some
  // should perhaps be in the public API but are missing from the wxWidgets
  // documentation (AFF 26/03/08)

  /*
  wxArrayInt CalcRowLabelsExposed( const wxRegion& reg );
  wxArrayInt CalcColLabelsExposed( const wxRegion& reg );
  wxGridCellCoordsArray CalcCellsExposed( const wxRegion& reg );

  void ProcessRowLabelMouseEvent( wxMouseEvent& event );
  void ProcessColLabelMouseEvent( wxMouseEvent& event );
  void ProcessCornerLabelMouseEvent( wxMouseEvent& event );
  void ProcessGridCellMouseEvent( wxMouseEvent& event );
  bool ProcessTableMessage( wxGridTableMessage& );

  void DoEndDragResizeRow();
  void DoEndDragResizeCol();

  void DrawGridCellArea( wxDC& dc , const wxGridCellCoordsArray& cells );
  void DrawGridSpace( wxDC& dc );
  void DrawCellBorder( wxDC& dc, const wxGridCellCoords& );
  void DrawAllGridLines( wxDC& dc, const wxRegion & reg );
  void DrawCell( wxDC& dc, const wxGridCellCoords& );
  void DrawHighlight(wxDC& dc, const wxGridCellCoordsArray& cells);

  virtual void DrawCellHighlight( wxDC& dc, const wxGridCellAttr *attr );

  virtual void DrawRowLabels( wxDC& dc, const wxArrayInt& rows );
  virtual void DrawRowLabel( wxDC& dc, int row );

  virtual void DrawColLabels( wxDC& dc, const wxArrayInt& cols );
  virtual void DrawColLabel( wxDC& dc, int col );

  void DrawTextRectangle( wxDC& dc, const wxString&, const wxRect&,
                          int horizontalAlignment = wxALIGN_LEFT,
                          int verticalAlignment = wxALIGN_TOP,
                          int textOrientation = wxHORIZONTAL );

  void DrawTextRectangle( wxDC& dc, const wxArrayString& lines, const wxRect&,
                          int horizontalAlignment = wxALIGN_LEFT,
                          int verticalAlignment = wxALIGN_TOP,
                          int textOrientation = wxHORIZONTAL );

  void StringToLines( const wxString& value, wxArrayString& lines );
  void GetTextBoxSize( wxDC& dc,
                       const wxArrayString& lines,
                       long *width, long *height );
  virtual void Refresh(bool eraseb = true,
                       const wxRect* rect = (const wxRect *)  NULL);
  bool IsCellEditControlShown() const;
  void XYToCell( int x, int y, wxGridCellCoords& );
  int      GetColLabelTextOrientation();
  wxColour GetCellHighlightColour();
  int      GetCellHighlightPenWidth();
  int      GetCellHighlightROPenWidth();
  void     SetColLabelTextOrientation( int textOrientation );
  void     SetCellHighlightColour( const wxColour& );
  void     SetCellHighlightPenWidth(int width);
  void     SetCellHighlightROPenWidth(int width);
  void     EnableDragCell( bool enable = true );
  void     DisableDragCell();
  bool     CanDragCell();
  // this sets the specified attribute for this cell or in this row/col
  void     SetAttr(int row, int col, wxGridCellAttr *attr);
  bool     GetDefaultCellOverflow();
  bool     GetCellOverflow( int row, int col );
  void     GetCellSize( int row, int col, int *num_rows, int *num_cols );
  void     AutoSizeRowLabelSize( int row );
  void     AutoSizeColLabelSize( int col );
  void     SetDefaultCellOverflow( bool allow );
  void     SetCellOverflow( int row, int col, bool allow );
  void     SetCellSize( int row, int col, int num_rows, int num_cols );
  // ------ deselect blocks or cells
  //
  void DeselectRow( int row );
  void DeselectCol( int col );
  void DeselectCell( int row, int col );
  // Accessors for component windows
  wxWindow* GetGridWindow();
  wxWindow* GetGridRowLabelWindow();
  wxWindow* GetGridColLabelWindow();
  wxWindow* GetGridCornerLabelWindow();
  // Implementation
  int GetScrollX(int x) const;

  int GetScrollY(int y) const;
  // override some base class functions
  virtual bool Enable(bool enable = true);
*/

};


#endif
