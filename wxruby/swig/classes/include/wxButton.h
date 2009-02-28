// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxButton_h_)
#define _wxButton_h_
class wxButton : public wxControl
{
public:
   wxButton() ;
   wxButton(wxWindow* parent, wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("button"));
  virtual  ~wxButton() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("button"));
	/**
	 * \brief Returns the string label for the button. 
	*/

  virtual wxString GetLabel() const;
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

  virtual void SetLabel(const wxString&  label ) ;
};


#endif
