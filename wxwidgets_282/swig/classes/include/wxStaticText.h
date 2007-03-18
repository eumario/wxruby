// Copyright 2006 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxStaticText_h_)
#define _wxStaticText_h_
class wxStaticText : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxStaticText() ;
	/**
	 * \brief Constructor, creating and showing a text control. 
	 * \param wxWindow*   
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

   wxStaticText(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = wxT("staticText")) ;
	/**
	 * \brief Creation function, for two-step construction. For details see  . 
	 * \param wxWindow*   
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = wxT("staticText")) ;
	/**
	 * \brief Returns the contents of the control. 
	*/

  virtual wxString GetLabel() const;
	/**
	 * \brief Sets the static text label and updates the controls size to exactly fit the
label unless the control has wxST_NO_AUTORESIZE flag. 
	 * \param const wxString&   
	*/

  virtual void SetLabel(const wxString&   label ) ;
  // the following were missing from the xml
  virtual ~wxStaticText();
};


#endif