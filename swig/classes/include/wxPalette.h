// wxPalette.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPalette_h_)
#define _wxPalette_h_
class wxPalette : public wxGDIObject
{
public:
   wxPalette() ;
   wxPalette(const wxPalette&  palette ) ;
   wxPalette(int  n , const unsigned char*  red , const unsigned char*  green , const unsigned char*  blue ) ;
  virtual  ~wxPalette() ;
  bool Create(int  n , const unsigned char*  red , const unsigned char*  green , const unsigned char*  blue ) ;
  int GetPixel(const unsigned char  red , const unsigned char  green , const unsigned char  blue ) const;
  bool GetRGB(int  pixel , const unsigned char*  red , const unsigned char*  green , const unsigned char*  blue ) const;
  bool Ok() const;
};


#endif
