// wxGridCellBoolRenderer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellBoolRenderer_h_)
#define _wxGridCellBoolRenderer_h_
class wxGridCellBoolRenderer : public wxGridCellRenderer
{
public:
	wxGridCellBoolRenderer();

    // draw a check mark or nothing
    virtual void Draw(wxGrid& grid,
                      wxGridCellAttr& attr,
                      wxDC& dc,
                      const wxRect& rect,
                      int row, int col,
                      bool isSelected);

    // return the checkmark size
    virtual wxSize GetBestSize(wxGrid& grid,
                               wxGridCellAttr& attr,
                               wxDC& dc,
                               int row, int col);

    virtual wxGridCellRenderer *Clone() const;
};


#endif
