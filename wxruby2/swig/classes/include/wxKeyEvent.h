// wxKeyEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxKeyEvent_h_)
#define _wxKeyEvent_h_
class wxKeyEvent : public wxEvent
{
public:
   wxKeyEvent(WXTYPE  keyEventType ) ;
  bool AltDown() const;
  bool ControlDown() const;
  int GetKeyCode() const;
  wxUint32 GetRawKeyCode() const;
  wxUint32 GetRawKeyFlags() const;
  long GetX() const;
  long GetY() const;
  bool MetaDown() const;
  wxPoint GetPosition() const;
  void GetPosition(long * x , long * y ) const;
  bool HasModifiers() const;
  bool ShiftDown() const;
};


#endif
