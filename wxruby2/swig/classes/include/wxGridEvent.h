// wxGridEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridEvent_h_)
#define _wxGridEvent_h_
class wxGridEvent : public wxNotifyEvent
{
public:
   wxGridEvent() ;
   wxGridEvent(int  id , wxEventType  type , wxObject*  obj , int  row = -1, int  col = -1, int  x = -1, int  y = -1, bool  sel = true, bool  control = false, bool  shift = false, bool  alt = false, bool  meta = false) ;
  bool AltDown() ;
  bool ControlDown() ;
  int GetCol() ;
  wxPoint GetPosition() ;
  int GetRow() ;
  bool MetaDown() ;
  bool Selecting() ;
  bool ShiftDown() ;
};


#endif
