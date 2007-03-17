// wxContextHelp.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxContextHelp_h_)
#define _wxContextHelp_h_
class wxContextHelp : public wxObject
{
public:
	/**
	 * \brief Constructs a context help object, calling   if
  is true (the default).

If   is NULL, the top window is used. 
	 * \param wxWindow*  
	 * \param bool  
	*/

   wxContextHelp(wxWindow* window = NULL, bool doNow = true) ;
	/**
	 * \brief Destroys the context help object. 
	*/

  virtual  ~wxContextHelp() ;
	/**
	 * \brief Puts the application into context-sensitive help mode.   is the window
which will be used to catch events; if NULL, the top window will be used.

Returns true if the application was successfully put into context-sensitive help mode.
This function only returns when the event loop has finished. 
	 * \param wxWindow*  
	*/

  bool BeginContextHelp(wxWindow* window = NULL) ;
	/**
	 * \brief Ends context-sensitive help mode. Not normally called by the application. 
	*/

  bool EndContextHelp() ;
};


#endif
