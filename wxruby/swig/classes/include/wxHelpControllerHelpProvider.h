// wxHelpControllerHelpProvider.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHelpControllerHelpProvider_h_)
#define _wxHelpControllerHelpProvider_h_
class wxHelpControllerHelpProvider : public wxSimpleHelpProvider
{
public:
	/**
	 * \brief Note that the instance doesn't own the help controller. The help controller
should be deleted separately. 
	 * \param wxHelpControllerBase*   
	*/

   wxHelpControllerHelpProvider(wxHelpControllerBase*  hc = NULL) ;
	/**
	 * \brief Sets the help controller associated with this help provider. 
	 * \param wxHelpControllerBase*   
	*/

  void SetHelpController(wxHelpControllerBase*  hc ) ;
	/**
	 * \brief Returns the help controller associated with this help provider. 
	*/

  wxHelpControllerBase* GetHelpController() const;
};


#endif
