// Copyright 2006 - 2007 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxIconizeEvent_h_)
#define _wxIconizeEvent_h_
class wxIconizeEvent : public wxEvent
{
public:
  wxIconizeEvent(int  id = 0, bool iconized = true) ;
  bool Iconized() const;
};


#endif
