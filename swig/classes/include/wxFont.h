// wxFont.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFont_h_)
#define _wxFont_h_
class wxFont : public wxGDIObject
{
public:
   wxFont() ;
   wxFont(int  pointSize , int  family , int  style , int  weight , const bool underline = false, const wxString&  faceName = wxT(""), wxFontEncoding  encoding = wxFONTENCODING_DEFAULT) ;
  virtual  ~wxFont() ;
  bool IsFixedWidth() const;
  static wxFontEncoding GetDefaultEncoding() ;
  wxString GetFaceName() const;
  int GetFamily() const;
  wxString GetNativeFontInfoDesc() const;
  wxString GetNativeFontInfoUserDesc();
  int GetPointSize() const;
  int GetStyle() const;
  bool GetUnderlined() const;
  int GetWeight() const;
  bool IsOk() const;
  static void SetDefaultEncoding(wxFontEncoding  encoding ) ;
  void SetFaceName(const wxString&  faceName ) ;
  void SetFamily(int  family ) ;
  void SetNativeFontInfo(const wxString&  info ) ;
  bool SetNativeFontInfoUserDesc(const wxString& info);
  void SetPointSize(int  pointSize ) ;
  void SetStyle(int  style ) ;
  void SetUnderlined(const bool  underlined ) ;
  void SetWeight(int  weight ) ;
};


#endif
