// wxScrollWinEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScrollWinEvent_h_)
#define _wxScrollWinEvent_h_
class wxScrollWinEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param WXTYPE   
	 * \param int   
	 * \param int  
	 * \param int  
	*/

  wxScrollWinEvent(WXTYPE commandType = 0, int pos = 0, int orientation = 0) ;
	/**
	 * \brief Returns wxHORIZONTAL or wxVERTICAL, depending on the orientation of the scrollbar. 
	*/

  int GetOrientation() const;
	/**
	 * \brief Returns the position of the scrollbar for the thumb track and release events.
Note that this field can't be used for the other events, you need to query
the window itself for the current position in that case. 
	*/

  int GetPosition() const;
};


#endif
