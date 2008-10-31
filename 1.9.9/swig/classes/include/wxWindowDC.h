// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxWindowDC_h_)
#define _wxWindowDC_h_
class wxWindowDC : public wxDC
{
public:
  wxWindowDC(wxWindow*  window ) ;
  virtual ~wxWindowDC();
};


#endif
