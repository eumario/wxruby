// wxCheckBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCheckBox_h_)
#define _wxCheckBox_h_
class wxCheckBox : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxCheckBox() ;
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

  wxCheckBox(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val = wxDefaultValidator, const wxString&  name = "checkBox");
	/**
	 * \brief Destructor, destroying the checkbox. 
	*/

  virtual  ~wxCheckBox() ;
	/**
	 * \brief Creates the checkbox for two-step construction. See  
for details. 
	 * \param wxWindow*   
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val = wxDefaultValidator, const wxString&  name = "checkBox");
	/**
	 * \brief Gets the state of the checkbox. 
	*/

  bool GetValue() const;
	/**
	 * \brief This is just a maybe more readable synonym for 
 : just as the latter, it returns 
  if the checkbox is checked and   otherwise. 
	*/

  bool IsChecked() const;
	/**
	 * \brief Sets the checkbox to the given state. This does not cause a
wxEVT_COMMAND_CHECKBOX_CLICKED event to get emitted. 
	 * \param const bool  
	*/

  void SetValue(const bool  state ) ;
};


#endif
