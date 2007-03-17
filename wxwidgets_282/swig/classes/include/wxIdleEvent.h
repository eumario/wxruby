//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxIdleEvent_h_)
#define _wxIdleEvent_h_
class wxIdleEvent : public wxEvent
{
public:
   wxIdleEvent() ;
  void RequestMore(bool needMore = true) ;
  bool MoreRequested() const;

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;
};


#endif
