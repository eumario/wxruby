// wxMouseCaptureChangedEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMouseCaptureChangedEvent_h_)
#define _wxMouseCaptureChangedEvent_h_
class wxMouseCaptureChangedEvent : public wxEvent
{
public:
   wxMouseCaptureChangedEvent(wxWindowID  windowId = 0, wxWindow* gainedCapture = NULL) ;
  wxWindow* GetCapturedWindow() const;
};


#endif
