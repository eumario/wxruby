// wxHelpEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHelpEvent_h_)
#define _wxHelpEvent_h_
class wxHelpEvent : public wxCommandEvent
{
public:
   wxHelpEvent(WXTYPE  eventType = 0, bool active = true, wxWindowID  id = 0, const wxPoint&  point ) ;
  const wxPoint& GetPosition() const;
  void SetPosition(const wxPoint&  pt ) ;
};


#endif
