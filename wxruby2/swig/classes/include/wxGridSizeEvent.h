// wxGridSizeEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridSizeEvent_h_)
#define _wxGridSizeEvent_h_
class wxGridSizeEvent : public wxNotifyEvent
{
public:
   wxGridSizeEvent() ;
   wxGridSizeEvent(int  id , wxEventType  type , wxObject*  obj , int  rowOrCol = -1, int  x = -1, int  y = -1, bool  control = false, bool  shift = false, bool  alt = false, bool  meta = false) ;
  bool AltDown() ;
  bool ControlDown() ;
  wxPoint GetPosition() ;
  int GetRowOrCol() ;
  bool MetaDown() ;
  bool ShiftDown() ;
};


#endif
