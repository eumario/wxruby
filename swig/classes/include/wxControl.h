// wxControl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxControl_h_)
#define _wxControl_h_
class wxControl : public wxWindow
{
public:
	/**
	 * \brief Simulates the effect of the user issuing a command to the item. See  . 
	 * \param wxCommandEvent&   
	*/

  void Command(wxCommandEvent&  event ) ;
	/**
	 * \brief Returns the control's text. 
	*/

  wxString GetLabel();
	/**
	 * \brief Sets the item's text. 
	 * \param const wxString&   
	*/

  void SetLabel(const wxString&  label ) ;
  // the following were missing from the xml
  virtual ~wxControl();
};


#endif
