// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license


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

  bool IsCommandEvent() const ;
  bool ShouldPropagate() const ;
  int StopPropagation() ;
  void ResumePropagation(int propagationLevel) ;


};


#endif
