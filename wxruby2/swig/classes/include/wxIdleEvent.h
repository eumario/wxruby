// wxIdleEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxIdleEvent_h_)
#define _wxIdleEvent_h_
class wxIdleEvent : public wxEvent
{
public:
   wxIdleEvent() ;
  void RequestMore(bool needMore = true) ;
  bool MoreRequested() const;
};


#endif
