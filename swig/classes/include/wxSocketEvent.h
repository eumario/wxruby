// wxSocketEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSocketEvent_h_)
#define _wxSocketEvent_h_
class wxSocketEvent : public wxEvent
{
public:
   wxSocketEvent(int id = 0) ;
  void * GetClientData() ;
  wxSocketBase * GetSocket() const;
  wxSocketNotify GetSocketEvent() const;
};


#endif
