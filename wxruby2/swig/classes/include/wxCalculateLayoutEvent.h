// wxCalculateLayoutEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCalculateLayoutEvent_h_)
#define _wxCalculateLayoutEvent_h_
class wxCalculateLayoutEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param wxWindowID   
	*/

   wxCalculateLayoutEvent(wxWindowID  id = 0) ;
	/**
	 * \brief Returns the flags associated with this event. Not currently used. 
	*/

  int GetFlags() const;
	/**
	 * \brief Before the event handler is entered, returns the remaining parent client area that the window
could occupy. When the event handler returns, this should contain the remaining parent client rectangle,
after the event handler has subtracted the area that its window occupies. 
	*/

  wxRect GetRect() const;
	/**
	 * \brief Sets the flags associated with this event. Not currently used. 
	 * \param int   
	*/

  void SetFlags(int  flags ) ;
	/**
	 * \brief Call this to specify the new remaining parent client area, after the space occupied by the
window has been subtracted. 
	 * \param const wxRect&   
	*/

  void SetRect(const wxRect&  rect ) ;
};


#endif
