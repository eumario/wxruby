//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

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
