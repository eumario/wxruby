// wxSocketBase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSocketBase_h_)
#define _wxSocketBase_h_
class wxSocketBase : public wxObject
{
public:
   wxSocketBase() ;
  virtual  ~wxSocketBase() ;
  wxSocketBase::wxSockCbk Callback(wxSocketBase::wxSockCbk  callback ) ;
  char * CallbackData(char * cdata ) ;
  void Close() ;
  bool Destroy() ;
  wxSocketBase& Discard() ;
  bool Error() const;
  void * GetClientData() const;
  bool GetLocal(wxSockAddress&  addr ) const;
  wxSocketFlags GetFlags() const;
  bool GetPeer(wxSockAddress&  addr ) const;
  void InterruptWait() ;
  bool IsConnected() const;
  bool IsData() const;
  bool IsDisconnected() const;
  wxUint32 LastCount() const;
  wxSocketError LastError() const;
  void Notify(bool  notify ) ;
  bool Ok() const;
  void RestoreState() ;
  void SaveState() ;
  void SetClientData(void * data ) ;
  void SetEventHandler(wxEvtHandler&  handler , int id = -1) ;
  void SetFlags(wxSocketFlags  flags ) ;
  void SetNotify(wxSocketEventFlags  flags ) ;
  void SetTimeout(int  seconds ) ;
  wxSocketBase& Peek(void *  buffer , wxUint32  nbytes ) ;
  wxSocketBase& Read(void *  buffer , wxUint32  nbytes ) ;
  wxSocketBase& ReadMsg(void *  buffer , wxUint32  nbytes ) ;
  wxSocketBase& Unread(const void *  buffer , wxUint32  nbytes ) ;
  bool Wait(long seconds = -1, long millisecond = 0) ;
  bool WaitForLost(long seconds = -1, long millisecond = 0) ;
  bool WaitForRead(long seconds = -1, long millisecond = 0) ;
  bool WaitForWrite(long seconds = -1, long millisecond = 0) ;
  wxSocketBase& Write(const void *  buffer , wxUint32  nbytes ) ;
  wxSocketBase& WriteMsg(const void *  buffer , wxUint32  nbytes ) ;
};


#endif
