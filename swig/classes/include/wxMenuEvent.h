// wxMenuEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMenuEvent_h_)
#define _wxMenuEvent_h_
class wxMenuEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param WXTYPE   
	 * \param int   
	 * \param wxDC*   
	*/

   wxMenuEvent(WXTYPE  id = 0, int  id = 0, wxDC*  dc = NULL) ;
	/**
	 * \brief Returns the menu identifier associated with the event. This method should be
only used with the   events. 
	*/

  int GetMenuId() const;
	/**
	 * \brief Returns   if the menu which is being opened or closed is a popup menu, 
  if it is a normal one.

This method should be only used with the   and   events. 
	*/

  bool IsPopup() const;
};


#endif
