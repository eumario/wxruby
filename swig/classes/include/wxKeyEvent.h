// wxKeyEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxKeyEvent_h_)
#define _wxKeyEvent_h_
class wxKeyEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. Currently, the only valid event types are wxEVT_CHAR and wxEVT_CHAR_HOOK. 
	 * \param WXTYPE  
	*/

   wxKeyEvent(WXTYPE  keyEventType ) ;
	/**
	 * \brief Returns true if the Alt key was down at the time of the key event. 
	*/

  bool AltDown() const;
	/**
	 * \brief Returns true if the control key was down at the time of the key event. 
	*/

  bool ControlDown() const;
	/**
	 * \brief Returns the virtual key code. ASCII events return normal ASCII values,
while non-ASCII events return values such as   for the
left cursor key. See   for a full list of the virtual key codes. 
	*/

  int GetKeyCode() const;
	/**
	 * \brief Returns the raw key code for this event. This is a platform-dependent scan code
which should only be used in advanced applications.

  Currently the raw key codes are not supported by all ports, use
  to determine if this feature is available. 
	*/

  wxUint32 GetRawKeyCode() const;
	/**
	 * \brief Returns the low level key flags for this event. The flags are
platform-dependent and should only be used in advanced applications.

  Currently the raw key flags are not supported by all ports, use
  to determine if this feature is available. 
	*/

  wxUint32 GetRawKeyFlags() const;
	/**
	 * \brief Returns the X position (in client coordinates) of the event. 
	*/

  long GetX() const;
	/**
	 * \brief Returns the Y (in client coordinates) position of the event. 
	*/

  long GetY() const;
	/**
	 * \brief Returns true if the Meta key was down at the time of the key event. 
	*/

  bool MetaDown() const;
	/**
	 * \brief  
	*/

  wxPoint GetPosition() const;
	/**
	 * \brief Obtains the position (in client coordinates) at which the key was pressed. 
	 * \param long *  
	 * \param long *  
	*/

  void GetPosition(long * x , long * y ) const;
	/**
	 * \brief Returns true if either {\sc Ctrl} or {\sc Alt} keys was down
at the time of the key event. Note that this function does not take into
account neither {\sc Shift} nor {\sc Meta} key states (the reason for ignoring
the latter is that it is common for {\sc NumLock} key to be configured as
{\sc Meta} under X but the key presses even while {\sc NumLock} is on should
be still processed normally). 
	*/

  bool HasModifiers() const;
	/**
	 * \brief Returns true if the shift key was down at the time of the key event. 
	*/

  bool ShiftDown() const;
};


#endif
