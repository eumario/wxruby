// wxMask.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMask_h_)
#define _wxMask_h_
class wxMask : public wxObject
{
public:
   wxMask() ;
   wxMask(const \helpref{wxBitmap wxbitmap ) ;
   wxMask(const \helpref{wxBitmap wxbitmap , const \helpref{wxColour wxcolour ) ;
   wxMask(const wxBitmap&  bitmap , int  index ) ;
  virtual  ~wxMask() ;
  bool Create(const wxBitmap&  bitmap ) ;
  bool Create(const wxBitmap&  bitmap , const wxColour&  colour ) ;
  bool Create(const wxBitmap&  bitmap , int  index ) ;
};


#endif
