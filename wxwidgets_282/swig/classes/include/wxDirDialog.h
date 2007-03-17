// wxDirDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDirDialog_h_)
#define _wxDirDialog_h_
class wxDirDialog : public wxDialog
{
public:
	/**
	 * \brief Constructor. Use   to show
the dialog. 
	 * \param wxWindow*   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param long   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param const wxString&   
	*/

   wxDirDialog(wxWindow*  parent , const wxString&  message = wxT("Choose"), const wxString&  defaultPath = wxT(""), long  style = 0, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, const wxString&  name = wxT("wxDirCtrl")) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxDirDialog() ;
	/**
	 * \brief Returns the default or user-selected path. 
	*/

  wxString GetPath() const;
	/**
	 * \brief Returns the message that will be displayed on the dialog. 
	*/

  wxString GetMessage() const;

  void SetMessage(const wxString&  message ) ;
	/**
	 * \brief Sets the default path. 
	 * \param const wxString&   
	*/

  void SetPath(const wxString&  path ) ;
	/**
	 * \brief Shows the dialog, returning wxID_OK if the user pressed OK, and wxOK_CANCEL
otherwise. 
	*/

  int ShowModal() ;
};


#endif
