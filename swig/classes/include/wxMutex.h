// wxMutex.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMutex_h_)
#define _wxMutex_h_
class wxMutex
{
public:
   wxMutex() ;
  virtual  ~wxMutex() ;
  wxMutexError Lock() ;
  wxMutexError TryLock() ;
  wxMutexError Unlock() ;
};


#endif
