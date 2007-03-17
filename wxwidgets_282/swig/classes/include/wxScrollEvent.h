// Copyright 2004-2006 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxScrollEvent_h_)
#define _wxScrollEvent_h_
class wxScrollEvent : public wxCommandEvent
{
public:
   wxScrollEvent(WXTYPE  commandType = 0, int  id = 0, int pos = 0, int orientation = 0) ;
  int GetOrientation() const;
  int GetPosition() const;
};


#endif
