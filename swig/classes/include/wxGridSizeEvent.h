// wxGridSizeEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridSizeEvent_h_)
#define _wxGridSizeEvent_h_
class wxGridSizeEvent : public wxNotifyEvent
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxGridSizeEvent() ;
	/**
	 * \brief  
	 * \param int   
	 * \param wxEventType   
	 * \param wxObject*   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param bool   
	 * \param bool   
	 * \param bool   
	 * \param bool   
	*/

   wxGridSizeEvent(int  id , wxEventType  type , wxObject*  obj , int  rowOrCol = -1, int  x = -1, int  y = -1, bool  control = false, bool  shift = false, bool  alt = false, bool  meta = false) ;
	/**
	 * \brief Returns true if the Alt key was down at the time of the event. 
	*/

  bool AltDown() ;
	/**
	 * \brief Returns true if the Control key was down at the time of the event. 
	*/

  bool ControlDown() ;
	/**
	 * \brief Position in pixels at which the event occurred. 
	*/

  wxPoint GetPosition() ;
	/**
	 * \brief Row or column at that was resized. 
	*/

  int GetRowOrCol() ;
	/**
	 * \brief Returns true if the Meta key was down at the time of the event. 
	*/

  bool MetaDown() ;
	/**
	 * \brief Returns true if the Shift key was down at the time of the event. 
	*/

  bool ShiftDown() ;
};


#endif
