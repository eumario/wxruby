// wxStreamToTextRedirector.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStreamToTextRedirector_h_)
#define _wxStreamToTextRedirector_h_
class wxStreamToTextRedirector
{
public:
	/**
	 * \brief The constructor starts redirecting output sent to   or   for
the default parameter value to the text control  . 
	 * \param wxTextCtrl   
	 * \param ostream *  
	*/

   wxStreamToTextRedirector(wxTextCtrl  *text , ostream * ostr = NULL) ;
	/**
	 * \brief When a wxStreamToTextRedirector object is destroyed, the redirection is ended
and any output sent to the C++ ostream which had been specified at the time of
the object construction will go to its original destination. 
	*/

  virtual  ~wxStreamToTextRedirector() ;
};


#endif
