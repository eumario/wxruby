// wxRadioButton.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxRadioButton_h_)
#define _wxRadioButton_h_
class wxRadioButton : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxRadioButton() ;
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

   wxRadioButton(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("radioButton")) ;
	/**
	 * \brief Destructor, destroying the radio button item. 
	*/

  virtual  ~wxRadioButton() ;
	/**
	 * \brief Creates the choice for two-step construction. See   for
further details. 
	 * \param wxWindow*  
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("radioButton")) ;
	/**
	 * \brief Returns true if the radio button is depressed, false otherwise. 
	*/

  bool GetValue() const;
	/**
	 * \brief Sets the radio button to selected or deselected status. This does not cause a
wxEVT_COMMAND_RADIOBUTTON_SELECTED event to get emitted. 
	 * \param const bool  
	*/

  void SetValue(const bool  value ) ;
};


#endif
