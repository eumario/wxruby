// wxProcess.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxProcess_h_)
#define _wxProcess_h_
class wxProcess : public wxEvtHandler
{
public:
   wxProcess(wxEvtHandler * parent = NULL, int id = -1) ;
   wxProcess(int  flags ) ;
  virtual  ~wxProcess() ;
  void CloseOutput() ;
  void Detach() ;
  wxInputStream*  GetErrorStream() const;
  wxInputStream*  GetInputStream() const;
  wxOutputStream*  GetOutputStream() const;
  bool IsErrorAvailable() const;
  bool IsInputAvailable() const;
  bool IsInputOpened() const;
  static wxKillError Kill(int  pid , wxSignal signal = wxSIGNONE) ;
  static bool Exists(int  pid ) ;
  virtual void OnTerminate(int  pid , int  status ) const;
  static wxProcess * Open(const wxString&  cmd , int  flags = wxEXEC_ASYNC) ;
  void Redirect() ;
};


#endif
