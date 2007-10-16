// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license
// Do not make changes directly to this file!

#if !defined(_wxColour_h_)
#define _wxColour_h_
class wxColour : public wxObject
{
public:
   wxColour() ;
   wxColour(const unsigned char  red , const unsigned char  green , const unsigned char  blue, const unsigned char alpha = wxALPHA_OPAQUE );
   wxColour(const wxString&  colourNname ) ;
   wxColour(const wxColour&  colour ) ;
  unsigned char Alpha() const;
  unsigned char Blue() const;
  wxString GetAsString(long flags) const;
  long GetPixel() const;
  unsigned char Green() const;
  bool IsOk() const;
  unsigned char Red() const;
  void Set(const unsigned char  red , const unsigned char  green , const unsigned char  blue, const unsigned char alpha = wxALPHA_OPAQUE ) ;
};


#endif
