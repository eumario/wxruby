// wxScrollEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

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
