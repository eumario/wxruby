// wxNotifyEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxNotifyEvent_h_)
#define _wxNotifyEvent_h_
class wxNotifyEvent : public wxCommandEvent
{
public:
   wxNotifyEvent(wxEventType eventType = wxEVT_NULL, int id = 0) ;
  void Allow() ;
  bool IsAllowed() const;
  void Veto() ;
};


#endif
