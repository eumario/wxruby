// wxActivateEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxActivateEvent_h_)
#define _wxActivateEvent_h_
class wxActivateEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param WXTYPE   
	 * \param bool  
	 * \param int   
	*/

   wxActivateEvent(WXTYPE  eventType = 0, bool active = true, int  id = 0) ;
	/**
	 * \brief Returns true if the application or window is being activated, false otherwise. 
	*/

  bool GetActive() const;
};


#endif
