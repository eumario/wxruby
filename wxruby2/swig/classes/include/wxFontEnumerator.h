// wxFontEnumerator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFontEnumerator_h_)
#define _wxFontEnumerator_h_
class wxFontEnumerator
{
public:
  virtual bool EnumerateFacenames(wxFontEncoding  encoding = wxFONTENCODING_SYSTEM, bool  fixedWidthOnly = false) ;
  virtual bool EnumerateEncodings(const wxString&  font = "") ;
  wxArrayString* GetEncodings() ;
  wxArrayString* GetFacenames() ;
  virtual bool OnFacename(const wxString&  font ) ;
  virtual bool OnFontEncoding(const wxString&  font , const wxString&  encoding ) ;
};


#endif
