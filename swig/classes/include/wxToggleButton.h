// wxToggleButton.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxToggleButton_h_)
#define _wxToggleButton_h_
class wxToggleButton : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxToggleButton() ;
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

  wxToggleButton(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val = wxDefaultValidator, const wxString&  name = wxT("checkBox"));
	/**
	 * \brief Destructor, destroying the toggle button. 
	*/

  virtual  ~wxToggleButton() ;
	/**
	 * \brief Creates the toggle button for two-step construction. See  
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

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  val = wxDefaultValidator, const wxString&  name = wxT("checkBox"));
	/**
	 * \brief Gets the state of the toggle button. 
	*/

  bool GetValue() const;
	/**
	 * \brief Sets the toggle button to the given state. This does not cause a 
  event to be emitted. 
	 * \param const bool  
	*/

  void SetValue(const bool  state ) ;
};


#endif
