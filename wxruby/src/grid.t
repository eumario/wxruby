/**********************************************************************

  grid.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS Grid : ScrolledWindow

//$$ METHODS_BEGIN
#   wxGrid();
   wxGrid(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxWANTS_CHARS, const wxString& name = wxPanelNameStr);
#   wxGrid(wxWindow* parent, int x, int y, int w = -1, int h = -1, long style = wxWANTS_CHARS, const wxString& name = wxPanelNameStr);

  bool AppendCols(int numCols = 1, bool updateLabels = TRUE);
  bool AppendRows(int numRows = 1, bool updateLabels = TRUE);
  void AutoSize();
  void AutoSizeColumn(int col, bool setAsMin = TRUE);
  void AutoSizeColumns(bool setAsMin = TRUE);
  void AutoSizeRow(int row, bool setAsMin = TRUE);
  void AutoSizeRows(bool setAsMin = TRUE);
  void BeginBatch();
  bool CanDragColSize();
  bool CanDragRowSize();
  bool CanDragGridSize();
  bool CanEnableCellControl();
  wxRect CellToRect(int row, int col);
#  wxRect CellToRect(const wxGridCellCoords& coords);
  void ClearGrid();
  void ClearSelection();
#  bool CreateGrid(int numRows, int numCols, wxGrid::wxGridSelectionModes selmode = wxGrid::wxGridSelectCells);
  bool CreateGrid(int numRows, int numCols){, wxGrid::wxGridSelectionModes selmode = wxGrid::wxGridSelectCells);}
  bool DeleteCols(int pos = 0, int numCols = 1, bool updateLabels = TRUE);
  bool DeleteRows(int pos = 0, int numRows = 1, bool updateLabels = TRUE);
  void DisableCellEditControl();
  void DisableDragColSize();
  void DisableDragGridSize();
  void DisableDragRowSize();
  void EnableCellEditControl(bool enable = TRUE);
  void EnableDragColSize(bool enable = TRUE);
  void EnableDragGridSize(bool enable = TRUE);
  void EnableDragRowSize(bool enable = TRUE);
  void EnableEditing(bool edit);
  void EnableGridLines(bool enable = TRUE);
  void EndBatch();
  void ForceRefresh();
  int GetBatchCount();
  void GetCellAlignment(int row, int col, int* horiz, int* vert);
  wxColour GetCellBackgroundColour(int row, int col);
#  wxGridCellEditor* GetCellEditor(int row, int col);
  wxFont GetCellFont(int row, int col);
#  wxGridCellRenderer* GetCellRenderer(int row, int col);
  wxColour GetCellTextColour(int row, int col);
  wxString GetCellValue(int row, int col);
#  wxString GetCellValue(const wxGridCellCoords& coords);
#  void GetColLabelAlignment(int* horiz, int* vert);
  int GetColLabelSize();
  wxString GetColLabelValue(int col);
  int GetColSize(int col);
#  void GetDefaultCellAlignment(int* horiz, int* vert);
  wxColour GetDefaultCellBackgroundColour();
  wxFont GetDefaultCellFont();
  wxColour GetDefaultCellTextColour();
  int GetDefaultColLabelSize();
  int GetDefaultColSize();
#  wxGridCellEditor* GetDefaultEditor();
#  wxGridCellRenderer* GetDefaultRenderer();
  int GetDefaultRowLabelSize();
  int GetDefaultRowSize();
  int GetGridCursorCol();
  int GetGridCursorRow();
  wxColour GetGridLineColour();
  bool GridLinesEnabled();
  wxColour GetLabelBackgroundColour();
  wxFont GetLabelFont();
  wxColour GetLabelTextColour();
  int GetNumberCols();
  int GetNumberRows();
#  void GetRowLabelAlignment(int* horiz, int* vert);
  int GetRowLabelSize();
  wxString GetRowLabelValue(int row);
  int GetRowSize(int row);
#  wxGrid::wxGridSelectionModes GetSelectionMode();
#  wxGridCellCoordsArray GetSelectedCells();
#  wxArrayInt GetSelectedCols();
#  wxArrayInt GetSelectedRows();
#  wxGridCellCoordsArray GetSelectionBlockTopLeft();
#  wxGridCellCoordsArray GetSelectionBlockBottomRight();
#  wxGridTableBase * GetTable();
  void HideCellEditControl();
  bool InsertCols(int pos = 0, int numCols = 1, bool updateLabels = TRUE);
  bool InsertRows(int pos = 0, int numRows = 1, bool updateLabels = TRUE);
  bool IsCellEditControlEnabled();
  bool IsCurrentCellReadOnly();
  bool IsEditable();
  bool IsInSelection(int row, int col);
#  bool IsInSelection(const wxGridCellCoords& coords);
  bool IsReadOnly(int row, int col);
  bool IsSelection();
  bool IsVisible(int row, int col, bool wholeCellVisible = TRUE);
#  bool IsVisible(const wxGridCellCoords& coords, bool wholeCellVisible = TRUE);
  void MakeCellVisible(int row, int col);
#  void MakeCellVisible(const wxGridCellCoords& coords);
  bool MoveCursorDown(bool expandSelection);
  bool MoveCursorLeft(bool expandSelection);
  bool MoveCursorRight(bool expandSelection);
  bool MoveCursorUp(bool expandSelection);
  bool MoveCursorDownBlock(bool expandSelection);
  bool MoveCursorLeftBlock(bool expandSelection);
  bool MoveCursorRightBlock(bool expandSelection);
  bool MoveCursorUpBlock(bool expandSelection);
  bool MovePageDown();
  bool MovePageUp();
  void SaveEditControlValue();
  void SelectAll();
  void SelectBlock(int topRow, int leftCol, int bottomRow, int rightCol, bool addToSelected = FALSE);
#  void SelectBlock(const wxGridCellCoords& topLeft, const wxGridCellCoords& bottomRight, bool addToSelected = FALSE);
  void SelectCol(int col, bool addToSelected = FALSE);
  void SelectRow(int row, bool addToSelected = FALSE);
  void SetCellAlignment(int row, int col, int horiz, int vert);
#  void SetCellAlignment(int align, int row, int col);
#  void SetCellAlignment(int align);
#  void SetCellEditor(int row, int col, wxGridCellEditor* editor);
  void SetCellFont(int row, int col, const wxFont& font);
#  void SetCellRenderer(int row, int col, wxGridCellRenderer* renderer);
  void SetCellTextColour(int row, int col, const wxColour& colour);
#  void SetCellTextColour(const wxColour& val, int row, int col);
#  void SetCellTextColour(const wxColour& colour);
  void SetCellValue(int row, int col, const wxString& s);
#  void SetCellValue(const wxGridCellCoords& coords, const wxString& s);
#  void SetCellValue(const wxString& val, int row, int col);
#  void SetColAttr(int col, wxGridCellAttr* attr);
  void SetColFormatBool(int col);
  void SetColFormatNumber(int col);
  void SetColFormatFloat(int col, int width = -1, int precision = -1);
  void SetColFormatCustom(int col, const wxString& typeName);
  void SetColLabelAlignment(int horiz, int vert);
  void SetColLabelSize(int height);
  void SetColLabelValue(int col, const wxString& value);
  void SetColMinimalWidth(int col, int width);
  void SetColSize(int col, int width);
  void SetDefaultCellAlignment(int horiz, int vert);
  void SetDefaultCellBackgroundColour(const wxColour& colour);
  void SetDefaultCellFont(const wxFont& font);
#  void SetDefaultEditor(wxGridCellEditor* editor);
#  void SetDefaultRenderer(wxGridCellRenderer* renderer);
  void SetDefaultColSize(int width, bool resizeExistingCols = FALSE);
  void SetDefaultRowSize(int height, bool resizeExistingRows = FALSE);
  void SetGridCursor(int row, int col);
  void SetGridLineColour(const wxColour& colour);
  void SetLabelBackgroundColour(const wxColour& colour);
  void SetLabelFont(const wxFont& font);
  void SetLabelTextColour(const wxColour& colour);
  void SetReadOnly(int row, int col, bool isReadOnly = TRUE);
#  void SetRowAttr(int row, wxGridCellAttr* attr);
  void SetRowLabelAlignment(int horiz, int vert);
  void SetRowLabelSize(int width);
  void SetRowLabelValue(int row, const wxString& value);
  void SetRowMinimalHeight(int row, int width);
  void SetRowSize(int row, int height);
#  void SetSelectionMode(wxGrid::wxGridSelectionModes selmode);
#  bool SetTable(wxGridTableBase* table, bool takeOwnership = FALSE, wxGrid::wxGridSelectionModes selmode = wxGrid::wxGridSelectCells);
  void ShowCellEditControl();
  int XToCol(int x);
  int XToEdgeOfCol(int x);
  int YToEdgeOfRow(int y);
  int YToRow(int y);
#  wxRect BlockToDeviceRect(const wxGridCellCoords & topLeft, const wxGridCellCoords & bottomRight);
#  wxRect SelectionToDeviceRect();
  wxColour GetSelectionBackground();
  wxColour GetSelectionForeground();
  void SetSelectionBackground(const wxColour& c);
  void SetSelectionForeground(const wxColour& c);
#  void RegisterDataType(const wxString& typeName, wxGridCellRenderer* renderer, wxGridCellEditor* editor);
#  wxGridCellEditor* GetDefaultEditorForCell(int row, int col);
#  wxGridCellEditor* GetDefaultEditorForCell(const wxGridCellCoords& c);
#  wxGridCellRenderer* GetDefaultRendererForCell(int row, int col);
#  wxGridCellEditor* GetDefaultEditorForType(const wxString& typeName);
#  wxGridCellRenderer* GetDefaultRendererForType(const wxString& typeName);
  void SetMargins(int extraWidth, int extraHeight);
  void UpdateDimensions();
  int GetRows();
  int GetCols();
  int GetCursorRow();
  int GetCursorColumn();
  int GetScrollPosX();
  int GetScrollPosY();
  void SetScrollX(int x);
  void SetScrollY(int y);
  void SetColumnWidth(int col, int width);
  int GetColumnWidth(int col);
  void SetRowHeight(int row, int height);
  int GetViewHeight();
  int GetViewWidth();
  void SetLabelSize(int orientation, int sz);
  int GetLabelSize(int orientation);
  void SetLabelAlignment(int orientation, int align);
  int GetLabelAlignment(int orientation, int align);
  void SetLabelValue(int orientation, const wxString& val, int pos);
  wxString GetLabelValue(int orientation, int pos);
#  wxFont GetCellTextFont();
  wxFont GetCellTextFont(int row, int col);
#  void SetCellTextFont(const wxFont& fnt);
  void SetCellTextFont(const wxFont& fnt, int row, int col);
#  void SetCellBackgroundColour(const wxColour& col);
  void SetCellBackgroundColour(int row, int col, const wxColour& colour);
#  void SetCellBackgroundColour(const wxColour& colour, int row, int col);
  bool GetEditable();
  void SetEditable(bool edit = TRUE);
  bool GetEditInPlace();
  void SetEditInPlace(bool edit = TRUE);
  void SetCellBitmap(wxBitmap* bitmap, int row, int col);
  void SetDividerPen(const wxPen& pen);
#  wxPen& GetDividerPen();
  void OnActivate(bool active);
  void Fit();
#  wxSize DoGetBestSize();
#  void InitRowHeights();
#  void InitColWidths();
#  int GetColWidth(int col);
#  int GetColLeft(int col);
#  int GetColRight(int col);
#  int GetRowHeight(int row);
#  int GetRowTop(int row);
#  int GetRowBottom(int row);
#  int SetOrCalcColumnSizes(bool calcOnly, bool setAsMin = TRUE);
#  int SetOrCalcRowSizes(bool calcOnly, bool setAsMin = TRUE);
#  void AutoSizeColOrRow(int n, bool setAsMin, bool column);
#  int GetColMinimalWidth(int col);
#  int GetRowMinimalHeight(int col);
#  bool CanHaveAttributes();
#  wxGridCellAttr* GetOrCreateCellAttr(int row, int col);

//$$ METHODS_END



//$$ BEGIN_H_FILE

class wxGrid;

//$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
#include <wx/grid.h>

#include "font.h"
#include "colour.h"
#include "pen.h"
#include "rect.h"
#include "size.h"

//$$ RB_IMPLEMENT_CLASS

//$$ END_CPP_FILE
