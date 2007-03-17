// wxHelpEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHelpEvent_h_)
#define _wxHelpEvent_h_
class wxHelpEvent : public wxCommandEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param WXTYPE   
	 * \param bool  
	 * \param wxWindowID   
	 * \param const wxPoint&   
	*/

   wxHelpEvent(WXTYPE  eventType = 0, bool active = true, wxWindowID  id = 0, const wxPoint&  point ) ;
	/**
	 * \brief Returns the left-click position of the mouse, in screen coordinates. This allows
the application to position the help appropriately. 
	*/

  const wxPoint& GetPosition() const;
	/**
	 * \brief Sets the left-click position of the mouse, in screen coordinates. 
	 * \param const wxPoint&  
	*/

  void SetPosition(const wxPoint&  pt ) ;
};


#endif
