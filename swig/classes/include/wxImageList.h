// wxImageList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxImageList_h_)
#define _wxImageList_h_
class wxImageList : public wxObject
{
public:
   wxImageList() ;
   wxImageList(int  width , int  height , const bool  mask = true, int  initialCount = 1) ;
  int Add(const wxBitmap&  bitmap , const wxBitmap& mask = wxNullBitmap) ;
  int Add(const wxBitmap&  bitmap , const wxColour&  maskColour ) ;
  int Add(const wxIcon&  icon ) ;
  bool Create(int  width , int  height , const bool  mask = true, int  initialCount = 1) ;
  bool Draw(int  index , wxDC&  dc , int  x , int  x , int  flags = wxIMAGELIST_DRAW_NORMAL, const bool  solidBackground = false) ;
  int GetImageCount() const;
  bool GetSize(int  index , int&  width , int & height ) const;
  bool Remove(int  index ) ;
  bool RemoveAll() ;
  bool Replace(int  index , const wxBitmap&  bitmap , const wxBitmap& mask = wxNullBitmap) ;
  bool Replace(int  index , const wxIcon&  icon ) ;
};


#endif
