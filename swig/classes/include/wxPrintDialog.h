// wxPrintDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrintDialog_h_)
#define _wxPrintDialog_h_
class wxPrintDialog : public wxDialog
{
public:
	/**
	 * \brief Constructor. Pass a parent window, and optionally a pointer to a block of print
data, which will be copied to the print dialog's print data. 
	 * \param wxWindow*   
	 * \param wxPrintDialogData*   
	*/

   wxPrintDialog(wxWindow*  parent , wxPrintDialogData*  data = NULL) ;
	/**
	 * \brief Destructor. If wxPrintDialog::GetPrintDC has   been called,
the device context obtained by the dialog (if any) will be deleted. 
	*/

  virtual  ~wxPrintDialog() ;
	/**
	 * \brief Returns the   associated with the print dialog. 
	*/

  wxPrintDialogData& GetPrintDialogData() ;
	/**
	 * \brief Returns the device context created by the print dialog, if any.
When this function has been called, the ownership of the device context
is transferred to the application, so it must then be deleted
explicitly. 
	*/

  wxDC*  GetPrintDC() ;
	/**
	 * \brief Returns true if the print data associated with the dialog is valid.
This can return false on Windows if the current printer is not set, for example.
On all other platforms, it returns true. 
	*/

  bool Ok() const;
	/**
	 * \brief Shows the dialog, returning wxID_OK if the user pressed OK, and wxID_CANCEL
otherwise. After this function is called, a device context may
be retrievable using  . 
	*/

  int ShowModal() ;
};


#endif
