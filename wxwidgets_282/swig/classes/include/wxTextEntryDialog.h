// wxTextEntryDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextEntryDialog_h_)
#define _wxTextEntryDialog_h_
class wxTextEntryDialog : public wxDialog
{
public:
	/**
	 * \brief Constructor. Use   to show the dialog. 
	 * \param wxWindow*   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param long   
	 * \param const wxPoint&   
	*/

   wxTextEntryDialog(wxWindow*  parent , const wxString&  message , const wxString&  caption = wxT("Please"), const wxString&  defaultValue = wxT(""), long  style = wxOK, const wxPoint&  pos = wxDefaultPosition) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxTextEntryDialog() ;
	/**
	 * \brief Returns the text that the user has entered if the user has pressed OK, or the original value
if the user has pressed Cancel. 
	*/

  wxString GetValue() const;
	/**
	 * \brief Sets the default text value. 
	 * \param const wxString&   
	*/

  void SetValue(const wxString&  value ) ;
	/**
	 * \brief Shows the dialog, returning wxID_OK if the user pressed OK, and wxOK_CANCEL
otherwise. 
	*/

  int ShowModal() ;
};


#endif
