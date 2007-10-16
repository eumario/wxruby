// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxNotifyEvent_h_)
#define _wxNotifyEvent_h_
class wxNotifyEvent : public wxCommandEvent
{
public:
   wxNotifyEvent(wxEventType eventType = wxEVT_NULL, int id = 0) ;
   wxNotifyEvent(const wxNotifyEvent& event) ;
  void Allow() ;
  bool IsAllowed() const;
  void Veto() ;
};


#endif
