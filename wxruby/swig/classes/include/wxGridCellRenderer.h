// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGridCellRenderer_h_)
#define _wxGridCellRenderer_h_
class wxGridCellRenderer : public wxGridCellWorker
{
public:
    virtual void Draw(wxGrid& grid,
                      wxGridCellAttr& attr,
                      wxDC& dc,
                      const wxRect& rect,
                      int row, int col,
                      bool isSelected) = 0;
    virtual wxSize GetBestSize(wxGrid& grid,
                               wxGridCellAttr& attr,
                               wxDC& dc,
                               int row, int col) = 0;
    virtual wxGridCellRenderer *Clone() const = 0;
};


#endif
