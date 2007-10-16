// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
