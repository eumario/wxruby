// wxHtmlContainerCell.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlContainerCell_h_)
#define _wxHtmlContainerCell_h_
class wxHtmlContainerCell : public wxHtmlCell
{
public:
   wxHtmlContainerCell(wxHtmlContainerCell  *parent ) ;
  int GetAlignHor() const;
  int GetAlignVer() const;
  wxColour GetBackgroundColour() ;
  //wxHtmlCell* GetFirstCell() ;
  wxHtmlCell* GetFirstChild() const;
  int GetIndent(int  ind ) const;
  int GetIndentUnits(int  ind ) const;
  void InsertCell(wxHtmlCell  *cell ) ;
  void SetAlign(const wxHtmlTag&  tag ) ;
  void SetAlignHor(int  al ) ;
  void SetAlignVer(int  al ) ;
  void SetBackgroundColour(const wxColour&  clr ) ;
  void SetBorder(const wxColour&  clr1 , const wxColour&  clr2 ) ;
  void SetIndent(int  i , int  what , int  units = wxHTML_UNITS_PIXELS) ;
  void SetMinHeight(int  h , int  align = wxHTML_ALIGN_TOP) ;
  void SetWidthFloat(int  w , int  units ) ;
  void SetWidthFloat(const wxHtmlTag&  tag , double  pixel_scale = 1.0) ;
};


#endif
