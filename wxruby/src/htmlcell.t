/**********************************************************************

  htmlcell.t -

  $Author$
  $Date$
  created at: 2004-08-04 18:19

  Copyright (C) 2004  Tobias Gruetzmacher

**********************************************************************/

//$$ CLASS HtmlCell
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
    wxHtmlCell();

    void SetParent(wxHtmlContainerCell *p);
    wxHtmlContainerCell *GetParent() const;

    int GetPosX() const;
    int GetPosY() const;
    int GetWidth() const;
    int GetHeight() const;
    int GetDescent() const;

    const wxString& GetId() const;
    void SetId(const wxString& id);
#(1)    virtual wxHtmlLinkInfo* GetLink(int WXUNUSED(x) = 0, int WXUNUSED(y) = 0) const
    wxHtmlCell *GetNext() const;
    virtual void SetPos(int x, int y);
#(1)    void SetLink(const wxHtmlLinkInfo& link);
    void SetNext(wxHtmlCell *cell);
    virtual void Layout(int w);
    virtual void Draw(wxDC& WXUNUSED(dc), int WXUNUSED(x), int WXUNUSED(y), int WXUNUSED(view_y1), int WXUNUSED(view_y2));
    virtual void DrawInvisible(wxDC& WXUNUSED(dc), int WXUNUSED(x), int WXUNUSED(y));
    virtual const wxHtmlCell* Find(int condition, const void* param) const;
    virtual void OnMouseClick(wxWindow *parent, int x, int y, const wxMouseEvent& event);
    virtual bool AdjustPagebreak(int *pagebreak) const;
    void SetCanLiveOnPagebreak(bool can);
#(2)    virtual void GetHorizontalConstraints(int *left, int *right) const;
    virtual bool IsTerminalCell() const;
    virtual wxHtmlCell *FindCellByPos(wxCoord x, wxCoord y) const;

//$$ METHODS_END

#(1) Other class not implemented in wxRuby
#(2) See below

//$$ BEGIN_H_FILE
#include "wx/html/htmlcell.h"

class WxHtmlCell
{
public:
        //$$ RB_DECLARE

    static VALUE GetHorizontalConstraints(VALUE self);
};
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
#include "window.h"
#include "htmlcontainercell.h"

void WxHtmlCell::DefineClass()
{
    //$$ RB_DEFINE

	rb_define_method(rubyClass,"get_horizontal_constrains",VALUEFUNC(WxHtmlCell::GetHorizontalConstraints),0);
}

//$$ RB_IMPLEMENT

VALUE
WxHtmlCell::GetHorizontalConstraints(VALUE self)
{
    int left;
    int right;
    wxRbHtmlCell *ptr;
    Data_Get_Struct(self, wxRbHtmlCell, ptr);
    ptr->GetHorizontalConstrains(&left, &right);
    return rb_ary_new3(2, INT2NUM(left), INT2NUM(right));
}

//$$ END_CPP_FILE
