// wxGridEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridEvent_h_)
#define _wxGridEvent_h_
class wxGridEvent : public wxNotifyEvent
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxGridEvent() ;
	/**
	 * \brief  
	 * \param int   
	 * \param wxEventType   
	 * \param wxObject*   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param bool   
	 * \param bool   
	 * \param bool   
	 * \param bool   
	 * \param bool   
	*/

   wxGridEvent(int  id , wxEventType  type , wxObject*  obj , int  row = -1, int  col = -1, int  x = -1, int  y = -1, bool  sel = true, bool  control = false, bool  shift = false, bool  alt = false, bool  meta = false) ;
	/**
	 * \brief Returns true if the Alt key was down at the time of the event. 
	*/

  bool AltDown() ;
	/**
	 * \brief Returns true if the Control key was down at the time of the event. 
	*/

  bool ControlDown() ;
	/**
	 * \brief Column at which the event occurred. 
	*/

  int GetCol() ;
	/**
	 * \brief Position in pixels at which the event occurred. 
	*/

  wxPoint GetPosition() ;
	/**
	 * \brief Row at which the event occurred. 
	*/

  int GetRow() ;
	/**
	 * \brief Returns true if the Meta key was down at the time of the event. 
	*/

  bool MetaDown() ;
	/**
	 * \brief Returns true if the user deselected a cell, false if the user
deselected a cell. 
	*/

  bool Selecting() ;
	/**
	 * \brief Returns true if the Shift key was down at the time of the event. 
	*/

  bool ShiftDown() ;
};


#endif
