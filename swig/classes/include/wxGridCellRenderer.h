// wxGridCellRenderer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellRenderer_h_)
#define _wxGridCellRenderer_h_
class wxGridCellRenderer
{
public:
  void Draw(wxGrid&  grid , wxGridCellAttr&  attr , wxDC&  dc , const wxRect&  rect , int  row , int  col , bool  isSelected ) ;
  wxSize GetBestSize(wxGrid&  grid , wxGridCellAttr&  attr , wxDC&  dc , int  row , int  col ) ;
  wxGridCellRenderer* Clone() const;
};


#endif
