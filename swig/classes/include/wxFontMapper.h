// wxFontMapper.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFontMapper_h_)
#define _wxFontMapper_h_
class wxFontMapper
{
public:
   wxFontMapper() ;
  virtual  ~wxFontMapper() ;
  static wxFontMapper * Get() ;
  bool GetAltForEncoding(wxFontEncoding  encoding , wxNativeEncodingInfo*  info , const wxString&  facename = wxEmptyString, bool  interactive = true) ;
  bool GetAltForEncoding(wxFontEncoding  encoding , wxFontEncoding*  alt_encoding , const wxString&  facename = wxEmptyString, bool  interactive = true) ;
  bool IsEncodingAvailable(wxFontEncoding  encoding , const wxString&  facename = wxEmptyString) ;
  wxFontEncoding CharsetToEncoding(const wxString&  charset , bool  interactive = true) ;
  static wxFontEncoding GetEncoding(size_t  n ) ;
  static wxString GetEncodingName(wxFontEncoding  encoding ) ;
  static wxString GetEncodingDescription(wxFontEncoding  encoding ) ;
  static size_t GetSupportedEncodingsCount() ;
  void SetDialogParent(wxWindow*  parent ) ;
  void SetDialogTitle(const wxString&  title ) ;
  static wxFontMapper * Set(wxFontMapper * mapper ) ;
  void SetConfig(wxConfigBase*  config ) ;
  void SetConfigPath(const wxString&  prefix ) ;
};


#endif
