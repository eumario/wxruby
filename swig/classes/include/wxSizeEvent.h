// wxSizeEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSizeEvent_h_)
#define _wxSizeEvent_h_
class wxSizeEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param const wxSize&   
	 * \param int   
	*/

   wxSizeEvent(const wxSize&  sz , int  id = 0) ;
	/**
	 * \brief Returns the entire size of the window generating the size change event. 
	*/

  wxSize GetSize() const;
};


#endif
