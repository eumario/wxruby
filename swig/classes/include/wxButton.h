// wxButton.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxButton_h_)
#define _wxButton_h_
class wxButton : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxButton() ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  wxButton(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "button");
	/**
	 * \brief Destructor, destroying the button. 
	*/

  virtual  ~wxButton() ;
	/**
	 * \brief Button creation function for two-step creation. For more details, see  . 
	 * \param wxWindow*   
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "button");
	/**
	 * \brief Returns the string label for the button. 
	*/

  wxString GetLabel() const;
	/**
	 * \brief Returns the default size for the buttons. It is advised to make all the dialog
buttons of the same size and this function allows to retrieve the (platform and
current font dependent size) which should be the best suited for this. 
	*/

  wxSize GetDefaultSize() ;
	/**
	 * \brief This sets the button to be the default item for the panel or dialog
box. 
	*/

  void SetDefault() ;
	/**
	 * \brief Sets the string label for the button. 
	 * \param const wxString&   
	*/

  void SetLabel(const wxString&  label ) ;
};


#endif
