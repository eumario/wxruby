// wxHelpProvider.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHelpProvider_h_)
#define _wxHelpProvider_h_
class wxHelpProvider
{
public:
	/**
	 * \brief Virtual destructor for any base class. 
	*/

  virtual  ~wxHelpProvider() ;
	/**
	 * \brief Get/set the current, application-wide help provider. Returns
the previous one. 
	 * \param wxHelpProvider*   
	*/

  wxHelpProvider* Set(wxHelpProvider*  helpProvider ) ;
	/**
	 * \brief Unlike some other classes, the help provider is not created on demand.
This must be explicitly done by the application. 
	*/

  wxHelpProvider* Get() ;
	/**
	 * \brief Gets the help string for this window. Its interpretation is dependent on the help provider
except that empty string always means that no help is associated with
the window. 
	 * \param const wxWindowBase*   
	*/

  wxString GetHelp(const wxWindowBase*  window ) ;
	/**
	 * \brief Shows help for the given window. Uses   internally if
applicable.

Returns true if it was done, or false if no help was available
for this window. 
	 * \param wxWindowBase*   
	*/

  bool ShowHelp(wxWindowBase*  window ) ;
	/**
	 * \brief Associates the text with the given window or id. Although all help
providers have these functions to allow making   
work, not all of them implement the functions. 
	 * \param wxWindowBase*   
	 * \param const wxString&   
	*/

  void AddHelp(wxWindowBase*  window , const wxString&  text ) ;
	/**
	 * \brief This version associates the given text with all windows with this id.
May be used to set the same help string for all Cancel buttons in
the application, for example. 
	 * \param wxWindowID   
	 * \param const wxString&   
	*/

  void AddHelp(wxWindowID  id , const wxString&  text ) ;
	/**
	 * \brief Removes the association between the window pointer and the help text. This is
called by the wxWindow destructor. Without this, the table of help strings will fill up
and when window pointers are reused, the wrong help string will be found. 
	 * \param wxWindowBase*   
	*/

  void RemoveHelp(wxWindowBase*  window ) ;
};


#endif
