// wxEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxEvent_h_)
#define _wxEvent_h_
class wxEvent : public wxObject
{
public:
   wxEvent(int  id = 0, wxEventType  eventType = wxEVT_NULL) ;
  virtual wxEvent* Clone() const = 0;
  wxObject* GetEventObject() ;
  WXTYPE GetEventType() ;
  int GetId() ;
  bool GetSkipped() ;
  long GetTimestamp() ;
  void SetEventObject(wxObject*  object ) ;
  void SetEventType(WXTYPE  typ ) ;
  void SetId(int  id ) ;
  void SetTimestamp(long  timeStamp ) ;
  void Skip(bool skip = true) ;
};


#endif
