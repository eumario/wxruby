// wxMenuEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMenuEvent_h_)
#define _wxMenuEvent_h_
class wxMenuEvent : public wxEvent
{
public:
   wxMenuEvent(WXTYPE  id = 0, int  id = 0, wxDC*  dc = NULL) ;
  int GetMenuId() const;
  bool IsPopup() const;
};


#endif
