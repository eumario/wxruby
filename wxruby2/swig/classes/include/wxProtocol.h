// wxProtocol.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxProtocol_h_)
#define _wxProtocol_h_
class wxProtocol : public wxSocketClient
{
public:
  bool Reconnect() ;
  wxInputStream * GetInputStream(const wxString&  path ) ;
  bool Abort() ;
  wxProtocolError GetError() ;
  wxString GetContentType() ;
  void  SetUser(const wxString&  user ) ;
  void SetPassword(const wxString&  user ) ;
};


#endif
