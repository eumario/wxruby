// wxProcessEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxProcessEvent_h_)
#define _wxProcessEvent_h_
class wxProcessEvent : public wxEvent
{
public:
   wxProcessEvent(int  id = 0, int  pid = 0, int  exitcode = 0) ;
  int GetPid() const;
  int GetExitCode() ;
};


#endif
