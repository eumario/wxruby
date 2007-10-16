// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxIconizeEvent_h_)
#define _wxIconizeEvent_h_
class wxIconizeEvent : public wxEvent
{
public:
  wxIconizeEvent(int  id = 0, bool iconized = true) ;
  bool Iconized() const;
};


#endif
