// wxLocale.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLocale_h_)
#define _wxLocale_h_
class wxLocale
{
public:
   wxLocale() ;
   wxLocale(int  language , int  flags = wxLOCALE_LOAD_DEFAULT) ;
   // wxLocale(const char  *szName , const char  *szShort = NULL, const char  *szLocale = NULL, bool  bLoadDefault = true, bool  bConvertEncoding = false) ;
  virtual  ~wxLocale() ;
  bool AddCatalog(const char  *szDomain ) ;
  static void AddLanguage(const wxLanguageInfo&  info ) ;
  static wxLanguageInfo * FindLanguageInfo(const wxString&  locale ) const;
  wxString GetCanonicalName() const;
  int GetLanguage() const;
  static wxLanguageInfo * GetLanguageInfo(int  lang ) const;
  static wxString GetLanguageName(int  lang ) const;
  const char* GetLocale() const;
  const wxString& GetName() const;
  const char* GetString(const char  *szOrigString , const char  *szDomain = NULL) const;
  wxString GetSysName() const;
  static wxFontEncoding GetSystemEncoding() const;
  static wxString GetSystemEncodingName() const;
  static int GetSystemLanguage() const;
  bool Init(int  language = wxLANGUAGE_DEFAULT, int  flags = wxLOCALE_LOAD_DEFAULT) ;

  static bool IsAvailable(int lang);
  bool IsLoaded(const char*  domain ) const;
  bool IsOk() const;
};


#endif
