// wxRect.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxRect_h_)
#define _wxRect_h_
class wxRect
{
public:
   wxRect() ;
   wxRect(int  x , int  y , int  width , int  height ) ;
   wxRect(const wxPoint&  topLeft , const wxPoint&  bottomRight ) ;
   wxRect(const wxPoint&  pos , const wxSize&  size ) ;
  void Deflate(wxCoord  dx , wxCoord  dy ) ;
  void Deflate(wxCoord  diff ) ;
  wxRect Deflate(wxCoord  dx , wxCoord  dy ) const;
  int GetBottom() const;
  int GetHeight() const;
  int GetLeft() const;
  wxPoint GetPosition() const;
  int GetRight() const;
  wxSize GetSize() const;
  int GetTop() const;
  int GetWidth() const;
  int GetX() const;
  int GetY() const;
  void Inflate(wxCoord  dx , wxCoord  dy ) ;
  void Inflate(wxCoord  diff ) ;
  wxRect Inflate(wxCoord  dx , wxCoord  dy ) const;
  void Offset(wxCoord  dx , wxCoord  dy ) ;
  void Offset(const wxPoint&  pt ) ;
  void SetHeight(int  height ) ;
  void SetWidth(int  width ) ;
  void SetX(int  x ) ;
  void SetY(int  y ) ;
};


#endif
