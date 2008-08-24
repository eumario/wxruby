// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxHelpEvent_h_)
#define _wxHelpEvent_h_
class wxHelpEvent : public wxCommandEvent
{
public:
   wxHelpEvent(WXTYPE eventType = 0, wxWindowID  id = 0, 
               const wxPoint& point = wxDefaultPosition);
  const wxPoint& GetPosition() const;
  void SetPosition(const wxPoint& pt);
};


#endif
