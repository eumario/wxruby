// wxCondition.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCondition_h_)
#define _wxCondition_h_
class wxCondition
{
public:
   wxCondition(wxMutex&  mutex ) ;
  virtual  ~wxCondition() ;
  void Broadcast() ;
  bool IsOk() const;
  void Signal() ;
  wxCondError Wait() ;
  wxCondError WaitTimeout(unsigned long  milliseconds ) ;
};


#endif
