// wxMouseEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMouseEvent_h_)
#define _wxMouseEvent_h_
class wxMouseEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. Valid event types are: 
	 * \param WXTYPE  
	 * \param int  
	*/

   wxMouseEvent(WXTYPE mouseEventType = 0, int id = 0) ;
	/**
	 * \brief Returns true if the Alt key was down at the time of the event. 
	*/

  bool AltDown() ;
	/**
	 * \brief Returns true if the identified mouse button is changing state. Valid
values of   are: 
	 * \param int  
	*/

  bool Button(int  button ) ;
	/**
	 * \brief If the argument is omitted, this returns true if the event was a mouse
double click event. Otherwise the argument specifies which double click event
was generated (see   for the possible
values). 
	 * \param int  
	*/

  bool ButtonDClick(int but = wxMOUSE_BTN_ANY) ;
	/**
	 * \brief If the argument is omitted, this returns true if the event was a mouse
button down event. Otherwise the argument specifies which button-down event
was generated (see   for the possible
values). 
	 * \param int  
	*/

  bool ButtonDown(int but = -1) ;
	/**
	 * \brief If the argument is omitted, this returns true if the event was a mouse
button up event. Otherwise the argument specifies which button-up event
was generated (see   for the possible
values). 
	 * \param int  
	*/

  bool ButtonUp(int but = -1) ;
	/**
	 * \brief Returns true if the control key was down at the time of the event. 
	*/

  bool ControlDown() ;
	/**
	 * \brief Returns true if this was a dragging event (motion while a button is depressed). 
	*/

  bool Dragging() ;
	/**
	 * \brief Returns true if the mouse was entering the window.

See also  . 
	*/

  bool Entering() ;
	/**
	 * \brief Returns the mouse button which generated this event or   
if no button is involved (for mouse move, enter or leave event, for example).
Otherwise   is returned for the left button down, up and
double click events,   and   
for the same events for the middle and the right buttons respectively. 
	*/

  int GetButton() const;
	/**
	 * \brief  
	*/

  wxPoint GetPosition() const;
	/**
	 * \brief  
	 * \param wxCoord*  
	 * \param wxCoord*  
	*/

  void GetPosition(wxCoord*  x , wxCoord*  y ) const;
	/**
	 * \brief Sets &#42;x and &#42;y to the position at which the event occurred.

Returns the physical mouse position in pixels. 
	 * \param long*  
	 * \param long*  
	*/

  void GetPosition(long*  x , long*  y ) const;
	/**
	 * \brief Returns the logical mouse position in pixels (i.e. translated according to the
translation set for the DC, which usually indicates that the window has been scrolled). 
	 * \param const wxDC&  
	*/

  wxPoint GetLogicalPosition(const wxDC&  dc ) const;
	/**
	 * \brief Returns the configured number of lines (or whatever) to be scrolled per
wheel action.  Defaults to three. 
	*/

  int GetLinesPerAction() const;
	/**
	 * \brief Get wheel rotation, positive or negative indicates direction of
rotation.  Current devices all send an event when rotation is equal to
+/-WheelDelta, but this allows for finer resolution devices to be
created in the future.  Because of this you shouldn't assume that one
event is equal to 1 line or whatever, but you should be able to either
do partial line scrolling or wait until +/-WheelDelta rotation values
have been accumulated before scrolling. 
	*/

  int GetWheelRotation() const;
	/**
	 * \brief Get wheel delta, normally 120.  This is the threshold for action to be
taken, and one such action (for example, scrolling one increment)
should occur for each delta. 
	*/

  int GetWheelDelta() const;
	/**
	 * \brief Returns X coordinate of the physical mouse event position. 
	*/

  long GetX() const;
	/**
	 * \brief Returns Y coordinate of the physical mouse event position. 
	*/

  long GetY() ;
	/**
	 * \brief Returns true if the event was a mouse button event (not necessarily a button down event -
that may be tested using  ). 
	*/

  bool IsButton() const;
	/**
	 * \brief Returns true if the system has been setup to do page scrolling with
the mouse wheel instead of line scrolling. 
	*/

  bool IsPageScroll() const;
	/**
	 * \brief Returns true if the mouse was leaving the window.

See also  . 
	*/

  bool Leaving() const;
	/**
	 * \brief Returns true if the event was a left double click. 
	*/

  bool LeftDClick() const;
	/**
	 * \brief Returns true if the left mouse button changed to down. 
	*/

  bool LeftDown() const;
	/**
	 * \brief Returns true if the left mouse button is currently down, independent
of the current event type.

Please notice that it is   the same as
  which returns true if the left mouse
button was just pressed. Rather, it describes the state of the mouse button
before the event happened.

This event is usually used in the mouse event handlers which process &quot;move
mouse&quot; messages to determine whether the user is (still) dragging the mouse. 
	*/

  bool LeftIsDown() const;
	/**
	 * \brief Returns true if the left mouse button changed to up. 
	*/

  bool LeftUp() const;
	/**
	 * \brief Returns true if the Meta key was down at the time of the event. 
	*/

  bool MetaDown() const;
	/**
	 * \brief Returns true if the event was a middle double click. 
	*/

  bool MiddleDClick() const;
	/**
	 * \brief Returns true if the middle mouse button changed to down. 
	*/

  bool MiddleDown() const;
	/**
	 * \brief Returns true if the middle mouse button is currently down, independent
of the current event type. 
	*/

  bool MiddleIsDown() const;
	/**
	 * \brief Returns true if the middle mouse button changed to up. 
	*/

  bool MiddleUp() const;
	/**
	 * \brief Returns true if this was a motion event (whether some buttons are currently
pressed or not, use   if you need to
distinguish between these situations). 
	*/

  bool Moving() const;
	/**
	 * \brief Returns true if the event was a right double click. 
	*/

  bool RightDClick() const;
	/**
	 * \brief Returns true if the right mouse button changed to down. 
	*/

  bool RightDown() const;
	/**
	 * \brief Returns true if the right mouse button is currently down, independent
of the current event type. 
	*/

  bool RightIsDown() const;
	/**
	 * \brief Returns true if the right mouse button changed to up. 
	*/

  bool RightUp() const;
	/**
	 * \brief Returns true if the shift key was down at the time of the event. 
	*/

  bool ShiftDown() const;
};


#endif
