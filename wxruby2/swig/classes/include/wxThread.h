// wxThread.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxThread_h_)
#define _wxThread_h_
class wxThread
{
public:
   wxThread(wxThreadKind  kind = wxTHREAD_DETACHED) ;
  virtual  ~wxThread() ;
  wxThreadError Create(unsigned int  stackSize = 0) ;
  void Delete() ;
  virtual ExitCode Entry() ;
  void Exit(ExitCode  exitcode = 0) ;
  static int GetCPUCount() ;
  static unsigned long GetCurrentId() ;
  unsigned long GetId() const;
  int GetPriority() const;
  bool IsAlive() const;
  bool IsDetached() const;
  static bool IsMain() ;
  bool IsPaused() const;
  bool IsRunning() const;
  wxThreadError Kill() ;
  virtual void OnExit() ;
  wxThreadError Pause() ;
  wxThreadError Run() ;
  void SetPriority(int  priority ) ;
  static void Sleep(unsigned long  milliseconds ) ;
  wxThreadError Resume() ;
  static bool SetConcurrency(size_t  level ) ;
  bool TestDestroy() ;
  static wxThread * This() ;
  void Yield() ;
  ExitCode Wait() const;
};


#endif
