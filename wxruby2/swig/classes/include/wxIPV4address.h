// wxIPV4address.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxIPV4address_h_)
#define _wxIPV4address_h_
class wxIPV4address : public wxSockAddress
{
public:
  bool Hostname(const wxString&  hostname ) ;
  wxString Hostname() ;
  bool Service(const wxString&  service ) ;
  bool Service(unsigned short  service ) ;
  unsigned short Service() ;
  bool AnyAddress() ;
  bool LocalHost() ;
};


#endif
