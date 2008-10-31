// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxMouseEvent_h_)
#define _wxMouseEvent_h_
class wxMouseEvent : public wxEvent
{
public:
   wxMouseEvent(wxEventType mouseEventType = 0) ;
  wxMouseEvent(const wxMouseEvent& event) ;
  bool AltDown() const;
  bool Button(int  button ) const;
  bool ButtonDClick(int but = wxMOUSE_BTN_ANY) const;
  bool ButtonDown(int but = -1) const;
  bool ButtonIsDown(int but) const;
  bool ButtonUp(int but = -1) const;
  bool ControlDown() const;
  bool Dragging() const;
  bool Entering() const;
  int GetButton() const;
  wxPoint GetPosition() const;
  // wxCoord is typedef'd to int and interferes with one below
  //void GetPosition(wxCoord*  x , wxCoord*  y ) const;
  void GetPosition(long*  x , long*  y ) const;
  wxPoint GetLogicalPosition(const wxDC&  dc ) const;
  int GetLinesPerAction() const;
  int GetWheelRotation() const;
  int GetWheelDelta() const;
  long GetX() const;
  long GetY() const;
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

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;
};

#endif
