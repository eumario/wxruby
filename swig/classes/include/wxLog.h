// wxLog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLog_h_)
#define _wxLog_h_
class wxLog
{
public:
  static void AddTraceMask(const wxString&  mask ) ;
  static void ClearTraceMasks() ;
  static const wxArrayString & GetTraceMasks() ;
  static void OnLog(wxLogLevel   level , const char *   message );
  static wxLog * GetActiveTarget() ;
  static wxLog * SetActiveTarget(wxLog *   logtarget ) ;
  static void Suspend() ;
  static void Resume() ;
  //virtual void DoLog(wxLogLevel  level , const wxChar  *msg , time_t  timestamp );
  //virtual void DoLogString(const wxChar  *msg , time_t  timestamp );
  static void DontCreateOnDemand() ;
  virtual void Flush() ;
  static void FlushActive() ;
  static void SetVerbose(bool  verbose = true) ;
  static bool GetVerbose() ;
  static void SetLogLevel(wxLogLevel   logLevel ) ;
  static wxLogLevel GetLogLevel() ;
  void SetTimestamp(const char *   format ) ;
  const char * GetTimestamp() const;
  static void SetTraceMask(wxTraceMask   mask ) ;
  static bool IsAllowedTraceMask(const wxChar * mask ) ;
  static void RemoveTraceMask(const wxString&  mask ) ;
};


#endif
