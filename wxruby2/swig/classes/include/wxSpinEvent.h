// wxSpinEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSpinEvent_h_)
#define _wxSpinEvent_h_
class wxSpinEvent : public wxNotifyEvent
{
public:
   wxSpinEvent(wxEventType  commandType = wxEVT_NULL, int  id = 0) ;
  int GetPosition() const;
  void SetPosition(int  pos ) ;
};


#endif
