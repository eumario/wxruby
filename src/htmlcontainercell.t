/**********************************************************************

  htmlcontainercell.t -

  $Author$
  $Date$
  created at: 2004-08-04 18:19

  Copyright (C) 2004  Tobias Gruetzmacher

**********************************************************************/

//$$ CLASS HtmlContainerCell : HtmlCell
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
    wxHtmlContainerCell(wxHtmlContainerCell *parent);

    virtual void Layout(int w);
    virtual void Draw(wxDC& dc, int x, int y, int view_y1, int view_y2);
    virtual void DrawInvisible(wxDC& dc, int x, int y);
    virtual bool AdjustPagebreak(int *pagebreak) const;
    void InsertCell(wxHtmlCell *cell);
    void SetAlignHor(int al);
    int GetAlignHor() const;
    void SetAlignVer(int al);
    int GetAlignVer() const;
    void SetIndent(int i, int what, int units = wxHTML_UNITS_PIXELS);
    int GetIndent(int ind) const;
    int GetIndentUnits(int ind) const;
#(1)    void SetAlign(const wxHtmlTag& tag);
    void SetWidthFloat(int w, int units);
#(1)    void SetWidthFloat(const wxHtmlTag& tag, double pixel_scale = 1.0);
    void SetMinHeight(int h, int align = wxHTML_ALIGN_TOP);
    void SetBackgroundColour(const wxColour& clr);
    wxColour GetBackgroundColour();
    void SetBorder(const wxColour& clr1, const wxColour& clr2);
#(1)    virtual wxHtmlLinkInfo* GetLink(int x = 0, int y = 0) const;
    virtual const wxHtmlCell* Find(int condition, const void* param) const;
    virtual void OnMouseClick(wxWindow *parent, int x, int y, const wxMouseEvent& event);
#(2)    virtual void GetHorizontalConstraints(int *left, int *right) const;
    wxHtmlCell* GetFirstCell() const;
    virtual bool IsTerminalCell() const;
    virtual wxHtmlCell *FindCellByPos(wxCoord x, wxCoord y) const;
//$$ METHODS_END

#(1) Other class not implemented in wxRuby

//$$ BEGIN_H_FILE
#include "wx/html/htmlcell.h"

//$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
#include "window.h"
#include "colour.h"
//$$ RB_IMPLEMENT_CLASS

//$$ END_CPP_FILE
