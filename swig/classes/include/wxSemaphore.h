// wxSemaphore.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSemaphore_h_)
#define _wxSemaphore_h_
class wxSemaphore
{
public:
   wxSemaphore(int  initialcount = 0, int  maxcount = 0) ;
  virtual  ~wxSemaphore() ;
  wxSemaError  Post() ;
  wxSemaError  TryWait() ;
  wxSemaError  Wait() ;
  wxSemaError  WaitTimeout(unsigned
long timeout_millis ) ;
};


#endif
