// wxPrintDialogData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrintDialogData_h_)
#define _wxPrintDialogData_h_
class wxPrintDialogData : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxPrintDialogData() ;
	/**
	 * \brief Copy constructor. 
	 * \param wxPrintDialogData&  
	*/

   wxPrintDialogData(wxPrintDialogData&  dialogData ) ;
	/**
	 * \brief Construct an object from a print dialog data object. 
	 * \param wxPrintData&  
	*/

   wxPrintDialogData(wxPrintData&  printData ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxprintdialogdata() ;
	/**
	 * \brief Enables or disables the `Help' button. 
	 * \param bool   
	*/

  void EnableHelp(bool  flag ) ;
	/**
	 * \brief Enables or disables the `Page numbers' controls. 
	 * \param bool   
	*/

  void EnablePageNumbers(bool  flag ) ;
	/**
	 * \brief Enables or disables the `Print to file' checkbox. 
	 * \param bool   
	*/

  void EnablePrintToFile(bool  flag ) ;
	/**
	 * \brief Enables or disables the `Selection' radio button. 
	 * \param bool   
	*/

  void EnableSelection(bool  flag ) ;
	/**
	 * \brief Returns true if the user requested that all pages be printed. 
	*/

  bool GetAllPages() const;
	/**
	 * \brief Returns true if the user requested that the document(s) be collated. 
	*/

  bool GetCollate() const;
	/**
	 * \brief Returns the   page number, as entered by the user. 
	*/

  int GetFromPage() const;
	/**
	 * \brief Returns the   page number. 
	*/

  int GetMaxPage() const;
	/**
	 * \brief Returns the   page number. 
	*/

  int GetMinPage() const;
	/**
	 * \brief Returns the number of copies requested by the user. 
	*/

  int GetNoCopies() const;
	/**
	 * \brief Returns a reference to the internal wxPrintData object. 
	*/

  wxPrintData& GetPrintData() ;
	/**
	 * \brief Returns true if the user has selected printing to a file. 
	*/

  bool GetPrintToFile() const;
	/**
	 * \brief Returns true if the user requested that the selection be printed (where 'selection' is
a concept specific to the application). 
	*/

  bool GetSelection() const;
	/**
	 * \brief Returns the   page number, as entered by the user. 
	*/

  int GetToPage() const;
	/**
	 * \brief Returns true if the print data is valid for using in print dialogs.
This can return false on Windows if the current printer is not set, for example.
On all other platforms, it returns true. 
	*/

  bool Ok() const;
	/**
	 * \brief Sets the 'Collate' checkbox to true or false. 
	 * \param bool   
	*/

  void SetCollate(bool  flag ) ;
	/**
	 * \brief Sets the   page number. 
	 * \param int   
	*/

  void SetFromPage(int  page ) ;
	/**
	 * \brief Sets the   page number. 
	 * \param int   
	*/

  void SetMaxPage(int  page ) ;
	/**
	 * \brief Sets the   page number. 
	 * \param int   
	*/

  void SetMinPage(int  page ) ;
	/**
	 * \brief Sets the default number of copies the user has requested to be printed out. 
	 * \param int   
	*/

  void SetNoCopies(int  n ) ;
	/**
	 * \brief Sets the internal wxPrintData. 
	 * \param const wxPrintData&   
	*/

  void SetPrintData(const wxPrintData&  printData ) ;
	/**
	 * \brief Sets the 'Print to file' checkbox to true or false. 
	 * \param bool   
	*/

  void SetPrintToFile(bool  flag ) ;
	/**
	 * \brief Selects the 'Selection' radio button. The effect of printing the selection depends on how the application
implements this command, if at all. 
	 * \param bool  
	*/

  void SetSelection(bool  flag ) ;
	/**
	 * \brief Determines whether the dialog to be shown will be the Print dialog
(pass false) or Print Setup dialog (pass true).

Note that the setup dialog is (according to Microsoft) obsolete from
Windows 95, though retained for backward compatibility. 
	 * \param bool   
	*/

  void SetSetupDialog(bool  flag ) ;
	/**
	 * \brief Sets the   page number. 
	 * \param int   
	*/

  void SetToPage(int  page ) ;
};


#endif
