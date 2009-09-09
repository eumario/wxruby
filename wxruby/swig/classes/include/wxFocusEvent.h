// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxFocusEvent_h_)
#define _wxFocusEvent_h_
class wxFocusEvent : public wxEvent
{
public:
   wxFocusEvent(WXTYPE  eventType = 0, int  id = 0) ;

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;

  wxWindow *GetWindow() const;
  void SetWindow(wxWindow *win);
};


#endif
