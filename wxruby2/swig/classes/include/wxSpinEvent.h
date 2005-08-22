//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

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
