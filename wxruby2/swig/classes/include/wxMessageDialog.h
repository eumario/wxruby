// wxMessageDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMessageDialog_h_)
#define _wxMessageDialog_h_
class wxMessageDialog : public wxDialog
{
public:
	/**
	 * \brief Constructor. Use   to show the dialog. 
	 * \param wxWindow*   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param long   
	 * \param const wxPoint&   
	*/

   wxMessageDialog(wxWindow*  parent , const wxString&  message , const wxString&  caption = wxT("Message"), long  style = wxOK, const wxPoint&  pos = wxDefaultPosition) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxMessageDialog() ;
	/**
	 * \brief Shows the dialog, returning one of wxID_OK, wxID_CANCEL, wxID_YES, wxID_NO. 
	*/

  int ShowModal() ;
};


#endif
