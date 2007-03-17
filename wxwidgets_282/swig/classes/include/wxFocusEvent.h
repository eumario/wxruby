//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxFocusEvent_h_)
#define _wxFocusEvent_h_
class wxFocusEvent : public wxEvent
{
public:
   wxFocusEvent(WXTYPE  eventType = 0, int  id = 0) ;

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;
};


#endif
