// wxDialUpManager.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDialUpManager_h_)
#define _wxDialUpManager_h_
class wxDialUpManager
{
public:
  wxDialUpManager* Create() ;
  bool IsOk() const;
  virtual  ~wxDialUpManager() ;
  size_t GetISPNames(wxArrayString&  names ) const;
  bool Dial(const wxString&  nameOfISP = wxEmptyString, const wxString&  username = wxEmptyString, const wxString&  password = wxEmptyString, bool  async = true) ;
  bool IsDialing() const;
  bool CancelDialing() ;
  bool HangUp() ;
  bool IsAlwaysOnline() const;
  bool IsOnline() const;
  void SetOnlineStatus(bool  isOnline = true) ;
  bool EnableAutoCheckOnlineStatus(size_t  nSeconds = 60) ;
  void DisableAutoCheckOnlineStatus() ;
  void SetWellKnownHost(const wxString&  hostname , int  portno = 80) ;
   SetConnectCommand(const wxString&  commandDial = wxT("/usr/bin/pon"), const wxString&  commandHangup = wxT("/usr/bin/poff")) ;
};


#endif
