// wxMoveEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMoveEvent_h_)
#define _wxMoveEvent_h_
class wxMoveEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param const wxPoint&   
	 * \param int   
	*/

   wxMoveEvent(const wxPoint&  pt , int  id = 0) ;
	/**
	 * \brief Returns the position of the window generating the move change event. 
	*/

  wxPoint GetPosition() const;
};


#endif
