// wxWizardEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWizardEvent_h_)
#define _wxWizardEvent_h_
class wxWizardEvent : public wxNotifyEvent
{
public:
   wxWizardEvent(wxEventType  type = wxEVT_NULL, int  id = -1, bool  direction = true) ;
  bool GetDirection() const;
  wxWizardPage* GetPage() const;
};


#endif
