//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxMoveEvent_h_)
#define _wxMoveEvent_h_
class wxMoveEvent : public wxEvent
{
public:
   wxMoveEvent(const wxPoint&  pt , int  id = 0) ;
  wxPoint GetPosition() const;

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;
};


#endif
