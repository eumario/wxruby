// wxSocketClient.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSocketClient_h_)
#define _wxSocketClient_h_
class wxSocketClient : public wxSocketBase
{
public:
   wxSocketClient(wxSocketFlags flags = wxSOCKET_NONE) ;
  virtual  ~wxSocketClient() ;
  bool Connect(wxSockAddress&  address , bool wait = true) ;
  bool WaitOnConnect(long seconds = -1, long milliseconds = 0) ;
};


#endif
