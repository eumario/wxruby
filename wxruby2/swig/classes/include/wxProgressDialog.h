// wxProgressDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxProgressDialog_h_)
#define _wxProgressDialog_h_
class wxProgressDialog : public wxFrame
{
public:
	/**
	 * \brief Constructor. Creates the dialog, displays it and disables user input
for other windows, or, if wxPD_APP_MODAL flag is not given, for its parent
window only. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param int   
	 * \param wxWindow *   
	 * \param int   
	*/

   wxProgressDialog(const wxString&  title , const wxString&  message , int  maximum = 100, wxWindow *  parent = NULL, int  style = wxPD_AUTO_HIDE) ;
	/**
	 * \brief Destructor. Deletes the dialog and enables all top level windows. 
	*/

  virtual  ~wxProgressDialog() ;
	/**
	 * \brief Can be used to continue with the dialog, after the user had chosen
ABORT. 
	*/

  void Resume() ;
	/**
	 * \brief Updates the dialog, setting the progress bar to the new value and, if
given changes the message above it. Returns true unless the Cancel button
has been pressed.

If false is returned, the application can either immediately destroy the dialog
or ask the user for the confirmation and if the abort is not confirmed the
dialog may be resumed with   function. 
	 * \param int   
	 * \param const wxString&   
	*/

  bool Update(int  value , const wxString&  newmsg = "") ;
};


#endif
