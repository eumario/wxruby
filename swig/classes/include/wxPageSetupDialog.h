// wxPageSetupDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPageSetupDialog_h_)
#define _wxPageSetupDialog_h_
class wxPageSetupDialog : public wxDialog
{
public:
	/**
	 * \brief Constructor. Pass a parent window, and optionally a pointer to a block of page setup
data, which will be copied to the print dialog's internal data. 
	 * \param wxWindow*   
	 * \param wxPageSetupDialogData*   
	*/

   wxPageSetupDialog(wxWindow*  parent , wxPageSetupDialogData*  data = NULL) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxPageSetupDialog() ;
	/**
	 * \brief Returns the   associated with the dialog. 
	*/

  wxPageSetupDialogData& GetPageSetupData() ;
	/**
	 * \brief Shows the dialog, returning wxID_OK if the user pressed OK, and wxID_CANCEL
otherwise. 
	*/

  int ShowModal() ;
};


#endif
