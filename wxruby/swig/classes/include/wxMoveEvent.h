// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
