// wxGridRangeSelectEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridRangeSelectEvent_h_)
#define _wxGridRangeSelectEvent_h_
class wxGridRangeSelectEvent : public wxNotifyEvent
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxGridRangeSelectEvent() ;
	/**
	 * \brief  
	 * \param int   
	 * \param wxEventType   
	 * \param wxObject*   
	 * \param const wxGridCellCoords&   
	 * \param const wxGridCellCoords&   
	 * \param bool   
	 * \param bool   
	 * \param bool   
	 * \param bool   
	 * \param bool   
	*/

   wxGridRangeSelectEvent(int  id , wxEventType  type , wxObject*  obj , const wxGridCellCoords&  topLeft , const wxGridCellCoords&  bottomRight , bool  sel = true, bool  control = false, bool  shift = false, bool  alt = false, bool  meta = false) ;
	/**
	 * \brief Returns true if the Alt key was down at the time of the event. 
	*/

  bool AltDown() ;
	/**
	 * \brief Returns true if the Control key was down at the time of the event. 
	*/

  bool ControlDown() ;
	/**
	 * \brief Top left corner of the rectangular area that was (de)selected. 
	*/

  wxGridCellCoords GetBottomRightCoords() ;
	/**
	 * \brief Bottom row of the rectangular area that was (de)selected. 
	*/

  int GetBottomRow() ;
	/**
	 * \brief Left column of the rectangular area that was (de)selected. 
	*/

  int GetLeftCol() ;
	/**
	 * \brief Right column of the rectangular area that was (de)selected. 
	*/

  int GetRightCol() ;
	/**
	 * \brief Top left corner of the rectangular area that was (de)selected. 
	*/

  wxGridCellCoords GetTopLeftCoords() ;
	/**
	 * \brief Top row of the rectangular area that was (de)selected. 
	*/

  int GetTopRow() ;
	/**
	 * \brief Returns true if the Meta key was down at the time of the event. 
	*/

  bool MetaDown() ;
	/**
	 * \brief Returns true if the area was selected, false otherwise. 
	*/

  bool Selecting() ;
	/**
	 * \brief Returns true if the Shift key was down at the time of the event. 
	*/

  bool ShiftDown() ;
};


#endif
