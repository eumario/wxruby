// wxEvtHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxEvtHandler_h_)
#define _wxEvtHandler_h_
class wxEvtHandler : public wxObject
{
public:
   wxEvtHandler() ;
  virtual  ~wxEvtHandler() ;
  virtual void AddPendingEvent(wxEvent&  event ) ;
  void Connect(int  id , wxEventType  eventType , wxObjectEventFunction  function , wxObject* userData = NULL) ;
  void Connect(int  id , int  lastId , wxEventType  eventType , wxObjectEventFunction  function , wxObject* userData = NULL) ;
  bool Disconnect(int  id , wxEventType  eventType = wxEVT_NULL, wxObjectEventFunction function = NULL, wxObject* userData = NULL) ;
  bool Disconnect(int  id , int lastId = -1, wxEventType  eventType = wxEVT_NULL, wxObjectEventFunction function = NULL, wxObject* userData = NULL) ;
  void*  GetClientData() ;
  wxClientData* GetClientObject() const;
  bool GetEvtHandlerEnabled() ;
  wxEvtHandler* GetNextHandler() ;
  wxEvtHandler* GetPreviousHandler() ;
  virtual bool ProcessEvent(wxEvent&  event ) ;
  bool SearchEventTable(wxEventTable&  table , wxEvent&  event ) ;
  void SetClientData(void*  data ) ;
  void SetClientObject(wxClientData*  data ) ;
  void SetEvtHandlerEnabled(bool  enabled ) ;
  void SetNextHandler(wxEvtHandler*  handler ) ;
  void SetPreviousHandler(wxEvtHandler*  handler ) ;
};


#endif
