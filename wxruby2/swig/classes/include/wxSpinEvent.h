// wxSpinEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSpinEvent_h_)
#define _wxSpinEvent_h_
class wxSpinEvent : public wxNotifyEvent
{
public:
	/**
	 * \brief The constructor is not normally used by the user code. 
	 * \param wxEventType   
	 * \param int   
	*/

   wxSpinEvent(wxEventType  commandType = wxEVT_NULL, int  id = 0) ;
	/**
	 * \brief Retrieve the current spin button or control value. 
	*/

  int GetPosition() const;
	/**
	 * \brief Set the value associated with the event. 
	 * \param int   
	*/

  void SetPosition(int  pos ) ;
};


#endif
