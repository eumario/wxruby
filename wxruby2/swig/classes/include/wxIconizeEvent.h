// wxIconizeEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxIconizeEvent_h_)
#define _wxIconizeEvent_h_
class wxIconizeEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param int   
	 * \param bool   
	*/

   wxIconizeEvent(int  id = 0, bool  iconized = true) ;
	/**
	 * \brief Returns   if the frame has been iconized,   if it has been
restored. 
	*/

  bool Iconized() const;
};


#endif
