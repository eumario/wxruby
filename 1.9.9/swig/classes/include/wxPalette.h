// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPalette_h_)
#define _wxPalette_h_
class wxPalette : public wxGDIObject
{
public:
   wxPalette() ;
   wxPalette(const wxPalette&  palette );
   wxPalette(int n, 
             const unsigned char* red, 
             const unsigned char* green, 
             const unsigned char* blue );
  virtual  ~wxPalette() ;
  bool Create(int n, 
              const unsigned char* red, 
              const unsigned char* green, 
              const unsigned char* blue);
  int GetPixel(unsigned char red, 
               unsigned char green, 
               unsigned char blue) const;
  bool GetRGB(int pixel, 
              unsigned char* red, 
              unsigned char* green, 
              unsigned char* blue) const;
  bool IsOk() const;
};


#endif
