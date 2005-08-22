// wxDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDialog_h_)
#define _wxDialog_h_
class wxDialog : public wxWindow
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxDialog() ;
	/**
	 * \brief Constructor. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

   wxDialog(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString&  name = wxT("dialogBox")) ;
	/**
	 * \brief Destructor. Deletes any child windows before deleting the physical window. 
	*/

  virtual  ~wxDialog() ;
	/**
	 * \brief Centres the dialog box on the display. 
	 * \param int  
	*/

  void Centre(int direction = wxBOTH) ;
	/**
	 * \brief Used for two-step dialog box construction. See  
for details. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString&  name = wxT("dialogBox")) ;
	/**
	 * \brief Ends a modal dialog, passing a value to be returned from the  
invocation. 
	 * \param int   
	*/

  virtual void EndModal(int  retCode ) ;
	/**
	 * \brief  
	*/

  int GetReturnCode() ;
	/**
	 * \brief Returns the title of the dialog box. 
	*/

  wxString GetTitle() const;
	/**
	 * \brief Iconizes or restores the dialog. Windows only. 
	 * \param const bool  
	*/

  void Iconize(const bool  iconize ) ;
	/**
	 * \brief Returns true if the dialog box is iconized. Windows only. 
	*/

  bool IsIconized() const;
	/**
	 * \brief Returns true if the dialog box is modal, false otherwise. 
	*/

  virtual bool IsModal() const;
	/**
	 * \brief This member is called to allow the window to intercept keyboard events
before they are processed by child windows. 
	 * \param wxKeyEvent&  
	*/

  //virtual void OnCharHook(wxKeyEvent&  event );
	/**
	 * \brief  
	 * \param wxCommandEvent&   
	*/

  virtual void OnApply(wxCommandEvent&  event ) ;
	/**
	 * \brief  
	 * \param wxCommandEvent&   
	*/

  virtual void OnCancel(wxCommandEvent&  event ) ;
	/**
	 * \brief  
	 * \param wxCommandEvent&   
	*/

  virtual void OnOK(wxCommandEvent&  event ) ;
	/**
	 * \brief The default handler for wxEVT_SYS_COLOUR_CHANGED. 
	 * \param wxSysColourChangedEvent&   
	*/

  virtual void OnSysColourChanged(wxSysColourChangedEvent&  event ) ;
	/**
	 * \brief Sets the icon for this dialog.





See also  . 
	 * \param const wxIcon&   
	*/

  void SetIcon(const wxIcon&  icon ) ;
	/**
	 * \brief Sets the icons for this dialog.





See also  . 
	 * \param const wxIconBundle&   
	*/

  void SetIcons(const wxIconBundle&  icons ) ;
	/**
	 * \brief This function is deprecated and doesn't work for all ports, just use 
  to show a modal dialog instead.

Allows the programmer to specify whether the dialog box is modal (wxDialog::Show blocks control
until the dialog is hidden) or modeless (control returns immediately). 
	 * \param const bool  
	*/

  void SetModal(const bool  flag ) ;
	/**
	 * \brief  
	 * \param int   
	*/

  void SetReturnCode(int  retCode ) ;
	/**
	 * \brief Sets the title of the dialog box. 
	 * \param const wxString&   
	*/

  void SetTitle(const wxString&   title ) ;
	/**
	 * \brief Hides or shows the dialog. 
	 * \param const bool  
	*/

  virtual bool Show(bool show = true ) ;
	/**
	 * \brief Shows a modal dialog. Program flow does not return until the dialog has been dismissed with
 . 
	*/

  virtual int ShowModal() ;
};


#endif
