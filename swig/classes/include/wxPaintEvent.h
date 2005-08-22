//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxPaintEvent_h_)
#define _wxPaintEvent_h_
class wxPaintEvent : public wxEvent
{
public:
   wxPaintEvent(int  id = 0) ;
  virtual ~wxPaintEvent();

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;
};


#endif
