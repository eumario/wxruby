// wxGridEditorCreatedEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridEditorCreatedEvent_h_)
#define _wxGridEditorCreatedEvent_h_
class wxGridEditorCreatedEvent : public wxCommandEvent
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxGridEditorCreatedEvent() ;
	/**
	 * \brief  
	 * \param int   
	 * \param wxEventType   
	 * \param wxObject*   
	 * \param int   
	 * \param int   
	 * \param wxControl*   
	*/

   wxGridEditorCreatedEvent(int  id , wxEventType  type , wxObject*  obj , int  row , int  col , wxControl*  ctrl ) ;
	/**
	 * \brief Returns the column at which the event occurred. 
	*/

  int GetCol() ;
	/**
	 * \brief Returns the edit control. 
	*/

  wxControl* GetControl() ;
	/**
	 * \brief Returns the row at which the event occurred. 
	*/

  int GetRow() ;
	/**
	 * \brief Sets the column at which the event occurred. 
	 * \param int   
	*/

  void SetCol(int  col ) ;
	/**
	 * \brief Sets the edit control. 
	 * \param wxControl*   
	*/

  void SetControl(wxControl*  ctrl ) ;
	/**
	 * \brief Sets the row at which the event occurred. 
	 * \param int   
	*/

  void SetRow(int  row ) ;
};


#endif
