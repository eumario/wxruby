// wxWindowDisabler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWindowDisabler_h_)
#define _wxWindowDisabler_h_
class wxWindowDisabler
{
public:
	/**
	 * \brief Disables all top level windows of the applications with the exception of 
  if it is not  . 
	 * \param wxWindow *  
	*/

   wxWindowDisabler(wxWindow * winToSkip = NULL) ;
	/**
	 * \brief Reenables back the windows disabled by the constructor. 
	*/

  virtual  ~wxWindowDisabler() ;
};


#endif
