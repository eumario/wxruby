// wxServer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxServer_h_)
#define _wxServer_h_
class wxServer
{
public:
   wxServer() ;
  bool Create(const wxString&  service ) ;
  virtual wxConnectionBase * OnAcceptConnection(const wxString&  topic ) ;
};


#endif
