// wxMouseEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMouseEvent_h_)
#define _wxMouseEvent_h_
class wxMouseEvent : public wxEvent
{
public:
   wxMouseEvent(WXTYPE mouseEventType = 0, int id = 0) ;
  bool AltDown() ;
  bool Button(int  button ) ;
  bool ButtonDClick(int but = wxMOUSE_BTN_ANY) ;
  bool ButtonDown(int but = -1) ;
  bool ButtonUp(int but = -1) ;
  bool ControlDown() ;
  bool Dragging() ;
  bool Entering() ;
  int GetButton() const;
  wxPoint GetPosition() const;
  void GetPosition(wxCoord*  x , wxCoord*  y ) const;
  void GetPosition(long*  x , long*  y ) const;
  wxPoint GetLogicalPosition(const wxDC&  dc ) const;
  int GetLinesPerAction() const;
  int GetWheelRotation() const;
  int GetWheelDelta() const;
  long GetX() const;
  long GetY() ;
  bool IsButton() const;
  bool IsPageScroll() const;
  bool Leaving() const;
  bool LeftDClick() const;
  bool LeftDown() const;
  bool LeftIsDown() const;
  bool LeftUp() const;
  bool MetaDown() const;
  bool MiddleDClick() const;
  bool MiddleDown() const;
  bool MiddleIsDown() const;
  bool MiddleUp() const;
  bool Moving() const;
  bool RightDClick() const;
  bool RightDown() const;
  bool RightIsDown() const;
  bool RightUp() const;
  bool ShiftDown() const;
};


#endif
