// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
