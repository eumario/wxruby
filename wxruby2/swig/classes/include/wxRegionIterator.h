// wxRegionIterator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxRegionIterator_h_)
#define _wxRegionIterator_h_
class wxRegionIterator : public wxObject
{
public:
   wxRegionIterator() ;
   wxRegionIterator(const wxRegion&  region ) ;
  wxCoord GetX() const;
  wxCoord GetY() const;
  wxCoord GetW() const;
  wxCoord GetWidth() const;
  wxCoord GetH() const;
  wxCoord GetHeight() const;
  wxRect GetRect() const;
  bool HaveRects() const;
  void Reset() ;
  void Reset(const wxRegion&  region ) ;
};


#endif
