// wxJoystickEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxJoystickEvent_h_)
#define _wxJoystickEvent_h_
class wxJoystickEvent : public wxEvent
{
public:
   wxJoystickEvent(WXTYPE eventType = 0, int state = 0, int joystick = wxJOYSTICK1, int  change = 0) ;
  bool ButtonDown(int button = wxJOY_BUTTON_ANY) const;
  bool ButtonIsDown(int button = wxJOY_BUTTON_ANY) const;
  bool ButtonUp(int button = wxJOY_BUTTON_ANY) const;
  int GetButtonChange() const;
  int GetButtonState() const;
  int GetJoystick() const;
  wxPoint GetPosition() const;
  int GetZPosition() const;
  bool IsButton() const;
  bool IsMove() const;
  bool IsZMove() const;
};


#endif
