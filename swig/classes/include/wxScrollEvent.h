// wxScrollEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScrollEvent_h_)
#define _wxScrollEvent_h_
class wxScrollEvent : public wxCommandEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param WXTYPE   
	 * \param int   
	 * \param int  
	 * \param int  
	*/

   wxScrollEvent(WXTYPE  commandType = 0, int  id = 0, int pos = 0, int orientation = 0) ;
	/**
	 * \brief Returns wxHORIZONTAL or wxVERTICAL, depending on the orientation of the scrollbar. 
	*/

  int GetOrientation() const;
	/**
	 * \brief Returns the position of the scrollbar. 
	*/

  int GetPosition() const;
};


#endif
