// wxGrid.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

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

    bool CreateGrid( int numRows, int numCols,
                     wxGrid::wxGridSelectionModes selmode =
                     wxGrid::wxGridSelectCells );

    void SetSelectionMode(wxGrid::wxGridSelectionModes selmode);
    wxGrid::wxGridSelectionModes GetSelectionMode() const;

    // ------ grid dimensions
    //
    int      GetNumberRows();
    int      GetNumberCols();


    // ------ display update functions
    //
    wxArrayInt CalcRowLabelsExposed( const wxRegion& reg );

    wxArrayInt CalcColLabelsExposed( const wxRegion& reg );
    wxGridCellCoordsArray CalcCellsExposed( const wxRegion& reg );


    // ------ event handlers
    //
    void ProcessRowLabelMouseEvent( wxMouseEvent& event );
    void ProcessColLabelMouseEvent( wxMouseEvent& event );
    void ProcessCornerLabelMouseEvent( wxMouseEvent& event );
    void ProcessGridCellMouseEvent( wxMouseEvent& event );
    bool ProcessTableMessage( wxGridTableMessage& );

    void DoEndDragResizeRow();
    void DoEndDragResizeCol();

    wxGridTableBase * GetTable() const;
    bool SetTable( wxGridTableBase *table, bool takeOwnership = false,
                   wxGrid::wxGridSelectionModes selmode =
                   wxGrid::wxGridSelectCells );

    void ClearGrid();
    bool InsertRows( int pos = 0, int numRows = 1, bool updateLabels = true );
    bool AppendRows( int numRows = 1, bool updateLabels = true );
    bool DeleteRows( int pos = 0, int numRows = 1, bool updateLabels = true );
    bool InsertCols( int pos = 0, int numCols = 1, bool updateLabels = true );
    bool AppendCols( int numCols = 1, bool updateLabels = true );
    bool DeleteCols( int pos = 0, int numCols = 1, bool updateLabels = true );

    void DrawGridCellArea( wxDC& dc , const wxGridCellCoordsArray& cells );
    void DrawGridSpace( wxDC& dc );
    void DrawCellBorder( wxDC& dc, const wxGridCellCoords& );
    void DrawAllGridLines( wxDC& dc, const wxRegion & reg );
    void DrawCell( wxDC& dc, const wxGridCellCoords& );
    void DrawHighlight(wxDC& dc, const wxGridCellCoordsArray& cells);

    // this function is called when the current cell highlight must be redrawn
    // and may be overridden by the user
    virtual void DrawCellHighlight( wxDC& dc, const wxGridCellAttr *attr );

    virtual void DrawRowLabels( wxDC& dc, const wxArrayInt& rows );
    virtual void DrawRowLabel( wxDC& dc, int row );

    virtual void DrawColLabels( wxDC& dc, const wxArrayInt& cols );
    virtual void DrawColLabel( wxDC& dc, int col );


    // ------ Cell text drawing functions
    //
    void DrawTextRectangle( wxDC& dc, const wxString&, const wxRect&,
                            int horizontalAlignment = wxALIGN_LEFT,
                            int verticalAlignment = wxALIGN_TOP,
                            int textOrientation = wxHORIZONTAL );

    void DrawTextRectangle( wxDC& dc, const wxArrayString& lines, const wxRect&,
                            int horizontalAlignment = wxALIGN_LEFT,
                            int verticalAlignment = wxALIGN_TOP,
                            int textOrientation = wxHORIZONTAL );


    // Split a string containing newline chararcters into an array of
    // strings and return the number of lines
    //
    void StringToLines( const wxString& value, wxArrayString& lines );

    void GetTextBoxSize( wxDC& dc,
                         const wxArrayString& lines,
                         long *width, long *height );


    // ------
    // Code that does a lot of grid modification can be enclosed
    // between BeginBatch() and EndBatch() calls to avoid screen
    // flicker
    //
    void     BeginBatch();
    void     EndBatch();

    int      GetBatchCount();

    virtual void Refresh(bool eraseb = true,
                         const wxRect* rect = (const wxRect *)  NULL);

    // Use this, rather than wxWindow::Refresh(), to force an
    // immediate repainting of the grid. Has no effect if you are
    // already inside a BeginBatch / EndBatch block.
    //
    // This function is necessary because wxGrid has a minimal OnPaint()
    // handler to reduce screen flicker.
    //
    void     ForceRefresh();


    // ------ edit control functions
    //
    bool IsEditable() const;
    void EnableEditing( bool edit );

    void EnableCellEditControl( bool enable = true );
    void DisableCellEditControl();
    bool CanEnableCellControl() const;
    bool IsCellEditControlEnabled() const;
    bool IsCellEditControlShown() const;

    bool IsCurrentCellReadOnly() const;

    void ShowCellEditControl();
    void HideCellEditControl();
    void SaveEditControlValue();


    // ------ grid location functions
    //  Note that all of these functions work with the logical coordinates of
    //  grid cells and labels so you will need to convert from device
    //  coordinates for mouse events etc.
    //
    void XYToCell( int x, int y, wxGridCellCoords& );
    int  YToRow( int y );
    int  XToCol( int x );

    int  YToEdgeOfRow( int y );
    int  XToEdgeOfCol( int x );

    wxRect CellToRect( int row, int col );
    wxRect CellToRect( const wxGridCellCoords& coords );

    int  GetGridCursorRow();
    int  GetGridCursorCol();

    // check to see if a cell is either wholly visible (the default arg) or
    // at least partially visible in the grid window
    //
    bool IsVisible( int row, int col, bool wholeCellVisible = true );
    bool IsVisible( const wxGridCellCoords& coords, bool wholeCellVisible = true );
    void MakeCellVisible( int row, int col );
    void MakeCellVisible( const wxGridCellCoords& coords );


    // ------ grid cursor movement functions
    //
    void SetGridCursor( int row, int col );

    bool MoveCursorUp( bool expandSelection );
    bool MoveCursorDown( bool expandSelection );
    bool MoveCursorLeft( bool expandSelection );
    bool MoveCursorRight( bool expandSelection );
    bool MovePageDown();
    bool MovePageUp();
    bool MoveCursorUpBlock( bool expandSelection );
    bool MoveCursorDownBlock( bool expandSelection );
    bool MoveCursorLeftBlock( bool expandSelection );
    bool MoveCursorRightBlock( bool expandSelection );


    // ------ label and gridline formatting
    //
    int      GetDefaultRowLabelSize();
    int      GetRowLabelSize();
    int      GetDefaultColLabelSize();
    int      GetColLabelSize();
    wxColour GetLabelBackgroundColour();
    wxColour GetLabelTextColour();
    wxFont   GetLabelFont();
    void     GetRowLabelAlignment( int *horiz, int *vert );
    void     GetColLabelAlignment( int *horiz, int *vert );
    int      GetColLabelTextOrientation();
    wxString GetRowLabelValue( int row );
    wxString GetColLabelValue( int col );
    wxColour GetGridLineColour();
    virtual wxPen GetDefaultGridLinePen();
    virtual wxPen GetRowGridLinePen(int row);
    virtual wxPen GetColGridLinePen(int col);
    wxColour GetCellHighlightColour();
    int      GetCellHighlightPenWidth();
    int      GetCellHighlightROPenWidth();

    void     SetRowLabelSize( int width );
    void     SetColLabelSize( int height );
    void     SetLabelBackgroundColour( const wxColour& );
    void     SetLabelTextColour( const wxColour& );
    void     SetLabelFont( const wxFont& );
    void     SetRowLabelAlignment( int horiz, int vert );
    void     SetColLabelAlignment( int horiz, int vert );
    void     SetColLabelTextOrientation( int textOrientation );
    void     SetRowLabelValue( int row, const wxString& );
    void     SetColLabelValue( int col, const wxString& );
    void     SetGridLineColour( const wxColour& );
    void     SetCellHighlightColour( const wxColour& );
    void     SetCellHighlightPenWidth(int width);
    void     SetCellHighlightROPenWidth(int width);

    void     EnableDragRowSize( bool enable = true );
    void     DisableDragRowSize();
    bool     CanDragRowSize();
    void     EnableDragColSize( bool enable = true );
    void     DisableDragColSize();
    bool     CanDragColSize();
    void     EnableDragColMove();
    void     DisableDragColMove();
    bool     CanDragColMove();
    void     EnableDragGridSize(bool enable = true);
    void     DisableDragGridSize();
    bool     CanDragGridSize();


    void     EnableDragCell( bool enable = true );
    void     DisableDragCell();
    bool     CanDragCell();

    // this sets the specified attribute for this cell or in this row/col
    void     SetAttr(int row, int col, wxGridCellAttr *attr);
    void     SetRowAttr(int row, wxGridCellAttr *attr);
    void     SetColAttr(int col, wxGridCellAttr *attr);

    // returns the attribute we may modify in place: a new one if this cell
    // doesn't have any yet or the existing one if it does
    //
    // DecRef() must be called on the returned pointer, as usual
    wxGridCellAttr *GetOrCreateCellAttr(int row, int col) const;


    // shortcuts for setting the column parameters

    // set the format for the data in the column: default is string
    void     SetColFormatBool(int col);
    void     SetColFormatNumber(int col);
    void     SetColFormatFloat(int col, int width = -1, int precision = -1);
    void     SetColFormatCustom(int col, const wxString& typeName);

    void     EnableGridLines( bool enable = true );
    bool     GridLinesEnabled();

    // ------ row and col formatting
    //
    int      GetDefaultRowSize();
    int      GetRowSize( int row );
    int      GetDefaultColSize();
    int      GetColSize( int col );
    wxColour GetDefaultCellBackgroundColour();
    wxColour GetCellBackgroundColour( int row, int col );
    wxColour GetDefaultCellTextColour();
    wxColour GetCellTextColour( int row, int col );
    wxFont   GetDefaultCellFont();
    wxFont   GetCellFont( int row, int col );
    void     GetDefaultCellAlignment( int *horiz, int *vert );
    void     GetCellAlignment( int row, int col, int *horiz, int *vert );
    bool     GetDefaultCellOverflow();
    bool     GetCellOverflow( int row, int col );
    void     GetCellSize( int row, int col, int *num_rows, int *num_cols );

    void     SetDefaultRowSize( int height, bool resizeExistingRows = false );
    void     SetRowSize( int row, int height );
    void     SetDefaultColSize( int width, bool resizeExistingCols = false );

    void     SetColSize( int col, int width );

	int      GetColAt( int colPos );
    int      GetColPos( int colID ) const;

    // automatically size the column or row to fit to its contents, if
    // setAsMin is true, this optimal width will also be set as minimal width
    // for this column
    void     AutoSizeColumn( int col, bool setAsMin = true );
    void     AutoSizeRow( int row, bool setAsMin = true );

    // auto size all columns (very ineffective for big grids!)
    void     AutoSizeColumns( bool setAsMin = true );

    void     AutoSizeRows( bool setAsMin = true );

    // auto size the grid, that is make the columns/rows of the "right" size
    // and also set the grid size to just fit its contents
    void     AutoSize();

    // autosize row height depending on label text
    void     AutoSizeRowLabelSize( int row );

    // autosize column width depending on label text
    void     AutoSizeColLabelSize( int col );

    // column won't be resized to be lesser width - this must be called during
    // the grid creation because it won't resize the column if it's already
    // narrower than the minimal width
    void     SetColMinimalWidth( int col, int width );
    void     SetRowMinimalHeight( int row, int width );

    /*  These members can be used to query and modify the minimal
     *  acceptable size of grid rows and columns. Call this function in
     *  your code which creates the grid if you want to display cells
     *  with a size smaller than the default acceptable minimum size.
     *  Like the members SetColMinimalWidth and SetRowMinimalWidth,
     *  the existing rows or columns will not be checked/resized.
     */
    void     SetColMinimalAcceptableWidth( int width );
    void     SetRowMinimalAcceptableHeight( int width );
    int      GetColMinimalAcceptableWidth() const;
    int      GetRowMinimalAcceptableHeight() const;

    void     SetDefaultCellBackgroundColour( const wxColour& );
    void     SetCellBackgroundColour( int row, int col, const wxColour& );
    void     SetDefaultCellTextColour( const wxColour& );

    void     SetCellTextColour( int row, int col, const wxColour& );
    void     SetDefaultCellFont( const wxFont& );
    void     SetCellFont( int row, int col, const wxFont& );
    void     SetDefaultCellAlignment( int horiz, int vert );
    void     SetCellAlignment( int row, int col, int horiz, int vert );
    void     SetDefaultCellOverflow( bool allow );
    void     SetCellOverflow( int row, int col, bool allow );
    void     SetCellSize( int row, int col, int num_rows, int num_cols );

    // takes ownership of the pointer
    void SetDefaultRenderer(wxGridCellRenderer *renderer);
    void SetCellRenderer(int row, int col, wxGridCellRenderer *renderer);
    wxGridCellRenderer *GetDefaultRenderer() const;
    wxGridCellRenderer* GetCellRenderer(int row, int col);

    // takes ownership of the pointer
    void SetDefaultEditor(wxGridCellEditor *editor);
    void SetCellEditor(int row, int col, wxGridCellEditor *editor);
    wxGridCellEditor *GetDefaultEditor() const;
    wxGridCellEditor* GetCellEditor(int row, int col);



    // ------ cell value accessors
    //
    wxString GetCellValue( int row, int col );

    wxString GetCellValue( const wxGridCellCoords& coords );

    void SetCellValue( int row, int col, const wxString& s );
    void SetCellValue( const wxGridCellCoords& coords, const wxString& s );

    // returns true if the cell can't be edited
    bool IsReadOnly(int row, int col) const;

    // make the cell editable/readonly
    void SetReadOnly(int row, int col, bool isReadOnly = true);

    // ------ select blocks of cells
    //
    void SelectRow( int row, bool addToSelected = false );
    void SelectCol( int col, bool addToSelected = false );

    void SelectBlock( int topRow, int leftCol, int bottomRow, int rightCol,
                      bool addToSelected = false );

    void SelectBlock( const wxGridCellCoords& topLeft,
                      const wxGridCellCoords& bottomRight,
                      bool addToSelected = false );

    void SelectAll();

    bool IsSelection();

    // ------ deselect blocks or cells
    //
    void DeselectRow( int row );
    void DeselectCol( int col );
    void DeselectCell( int row, int col );

    void ClearSelection();

    bool IsInSelection( int row, int col ) const;

    bool IsInSelection( const wxGridCellCoords& coords ) const;

    wxGridCellCoordsArray GetSelectedCells() const;
    wxGridCellCoordsArray GetSelectionBlockTopLeft() const;
    wxGridCellCoordsArray GetSelectionBlockBottomRight() const;
    wxArrayInt GetSelectedRows() const;
    wxArrayInt GetSelectedCols() const;

    // This function returns the rectangle that encloses the block of cells
    // limited by TopLeft and BottomRight cell in device coords and clipped
    //  to the client size of the grid window.
    //
    wxRect BlockToDeviceRect( const wxGridCellCoords & topLeft,
                              const wxGridCellCoords & bottomRight );

    // Access or update the selection fore/back colours
    wxColour GetSelectionBackground() const;
    wxColour GetSelectionForeground() const;

    void SetSelectionBackground(const wxColour& c);
    void SetSelectionForeground(const wxColour& c);


    // Methods for a registry for mapping data types to Renderers/Editors
    void RegisterDataType(const wxString& typeName,
                          wxGridCellRenderer* renderer,
                          wxGridCellEditor* editor);
    // DJC MAPTEK
    virtual wxGridCellEditor* GetDefaultEditorForCell(int row, int col) const;
    wxGridCellEditor* GetDefaultEditorForCell(const wxGridCellCoords& c) const;
    virtual wxGridCellRenderer* GetDefaultRendererForCell(int row, int col) const;
    virtual wxGridCellEditor* GetDefaultEditorForType(const wxString& typeName) const;
    virtual wxGridCellRenderer* GetDefaultRendererForType(const wxString& typeName) const;

    // grid may occupy more space than needed for its rows/columns, this
    // function allows to set how big this extra space is
    void SetMargins(int extraWidth, int extraHeight);

    // Accessors for component windows
    wxWindow* GetGridWindow();
    wxWindow* GetGridRowLabelWindow();
    wxWindow* GetGridColLabelWindow();
    wxWindow* GetGridCornerLabelWindow();

    // Allow adjustment of scroll increment. The default is (15, 15).
    void SetScrollLineX(int x);
    void SetScrollLineY(int y);
    int GetScrollLineX() const;
    int GetScrollLineY() const;

    // Implementation
    int GetScrollX(int x) const;

    int GetScrollY(int y) const;


    // override some base class functions
    virtual bool Enable(bool enable = true);

};


#endif
