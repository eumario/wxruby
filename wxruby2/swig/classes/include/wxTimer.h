// wxTimer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTimer_h_)
#define _wxTimer_h_
class wxTimer : public wxEvtHandler
{
public:
   wxTimer() ;
   wxTimer(wxEvtHandler * owner , int  id = -1) ;
  virtual  ~wxTimer() ;
  int GetInterval() const;
  bool IsOneShot() const;
  bool IsRunning() const;
  void Notify() ;
  void SetOwner(wxEvtHandler * owner , int  id = -1) ;
  bool Start(int milliseconds = -1, bool  oneShot = false) ;
  void Stop() ;
};


#endif
