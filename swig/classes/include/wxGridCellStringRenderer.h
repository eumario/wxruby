// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGridCellStringRenderer_h_)
#define _wxGridCellStringRenderer_h_
class wxGridCellStringRenderer : public wxGridCellRenderer
{
public:
   wxGridCellStringRenderer() ;

    // define pure virtual methods from base classes
    virtual void Draw(wxGrid& grid,
                      wxGridCellAttr& attr,
                      wxDC& dc,
                      const wxRect& rect,
                      int row, int col,
                      bool isSelected);
    virtual wxSize GetBestSize(wxGrid& grid,
                               wxGridCellAttr& attr,
                               wxDC& dc,
                               int row, int col);
    virtual wxGridCellRenderer *Clone() const;
};


#endif
