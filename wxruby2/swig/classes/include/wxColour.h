// wxColour.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxColour_h_)
#define _wxColour_h_
class wxColour : public wxObject
{
public:
   wxColour() ;
   wxColour(const unsigned char  red , const unsigned char  green , const unsigned char  blue ) ;
   wxColour(const wxString&  colourNname ) ;
   wxColour(const wxColour&  colour ) ;
  unsigned char Blue() const;
  long GetPixel() const;
  unsigned char Green() const;
  bool Ok() const;
  unsigned char Red() const;
  void Set(const unsigned char  red , const unsigned char  green , const unsigned char  blue ) ;
};


#endif
