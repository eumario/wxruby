// wxScrollWinEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScrollWinEvent_h_)
#define _wxScrollWinEvent_h_
class wxScrollWinEvent : public wxEvent
{
public:
   wxScrollWinEvent(WXTYPE  commandType = 0, int  id = 0, int pos = 0, int orientation = 0) ;
  int GetOrientation() const;
  int GetPosition() const;
};


#endif
