// wxSocketServer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSocketServer_h_)
#define _wxSocketServer_h_
class wxSocketServer : public wxSocketBase
{
public:
   wxSocketServer(wxSockAddress&  address , wxSocketFlags flags = wxSOCKET_NONE) ;
  virtual  ~wxSocketServer() ;
  wxSocketBase * Accept(bool wait = true) ;
  bool AcceptWith(wxSocketBase&  socket , bool wait = true) ;
  bool WaitForAccept(long seconds = -1, long millisecond = 0) ;
};


#endif
