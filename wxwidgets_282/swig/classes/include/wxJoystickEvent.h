// wxJoystickEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxJoystickEvent_h_)
#define _wxJoystickEvent_h_
class wxJoystickEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param WXTYPE  
	 * \param int  
	 * \param int  
	 * \param int   
	*/

   wxJoystickEvent(WXTYPE eventType = 0, int state = 0, int joystick = wxJOYSTICK1, int  change = 0) ;
	/**
	 * \brief Returns true if the event was a down event from the specified button (or any button). 
	 * \param int  
	*/

  bool ButtonDown(int button = wxJOY_BUTTON_ANY) const;
	/**
	 * \brief Returns true if the specified button (or any button) was in a down state. 
	 * \param int  
	*/

  bool ButtonIsDown(int button = wxJOY_BUTTON_ANY) const;
	/**
	 * \brief Returns true if the event was an up event from the specified button (or any button). 
	 * \param int  
	*/

  bool ButtonUp(int button = wxJOY_BUTTON_ANY) const;
	/**
	 * \brief Returns the identifier of the button changing state. This is a wxJOY_BUTTONn identifier, where
n is one of 1, 2, 3, 4. 
	*/

  int GetButtonChange() const;
	/**
	 * \brief Returns the down state of the buttons. This is a bitlist of wxJOY_BUTTONn identifiers, where
n is one of 1, 2, 3, 4. 
	*/

  int GetButtonState() const;
	/**
	 * \brief Returns the identifier of the joystick generating the event - one of wxJOYSTICK1 and wxJOYSTICK2. 
	*/

  int GetJoystick() const;
	/**
	 * \brief Returns the x, y position of the joystick event. 
	*/

  wxPoint GetPosition() const;
	/**
	 * \brief Returns the z position of the joystick event. 
	*/

  int GetZPosition() const;
	/**
	 * \brief Returns true if this was a button up or down event (  'is any button down?'). 
	*/

  bool IsButton() const;
	/**
	 * \brief Returns true if this was an x, y move event. 
	*/

  bool IsMove() const;
	/**
	 * \brief Returns true if this was a z move event. 
	*/

  bool IsZMove() const;
};


#endif
