// wxEraseEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxEraseEvent_h_)
#define _wxEraseEvent_h_
class wxEraseEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param int   
	 * \param wxDC*   
	*/

   wxEraseEvent(int  id = 0, wxDC*  dc = NULL) ;
	/**
	 * \brief Returns the device context to draw into. 
	*/

  wxDC* GetDC() const;
};


#endif
