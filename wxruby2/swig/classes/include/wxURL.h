// wxURL.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxURL_h_)
#define _wxURL_h_
class wxURL : public wxObject
{
public:
   wxURL(const wxString&  url ) ;
  virtual  ~wxURL() ;
  wxString GetProtocolName() const;
  wxProtocol& GetProtocol() ;
  wxString GetPath() ;
  wxURLError GetError() const;
  wxInputStream * GetInputStream() ;
  static void SetDefaultProxy(const wxString&  url_proxy ) ;
  void SetProxy(const wxString&  url_proxy ) ;
  static wxString ConvertToValidURI(const wxString&  uri ) ;
};


#endif
