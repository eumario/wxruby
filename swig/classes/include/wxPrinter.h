// wxPrinter.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrinter_h_)
#define _wxPrinter_h_
class wxPrinter : public wxObject
{
public:
	/**
	 * \brief Constructor. Pass an optional pointer to a block of print
dialog data, which will be copied to the printer object's local data. 
	 * \param wxPrintDialogData*   
	*/

   wxPrinter(wxPrintDialogData*  data = NULL) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxPrinter() ;
	/**
	 * \brief Returns true if the user has aborted the print job. 
	*/

  bool Abort() ;
	/**
	 * \brief Creates the default printing abort window, with a cancel button. 
	 * \param wxWindow*   
	 * \param wxPrintout*   
	*/

  void CreateAbortWindow(wxWindow*  parent , wxPrintout*  printout ) ;
	/**
	 * \brief Return last error. Valid after calling  ,
  or 
 . These functions 
set last error to   if no error happened.

Returned value is one of the following:

\twocolwidtha{7cm} 
	*/

  static wxPrinterError GetLastError() ;
	/**
	 * \brief Returns the   associated with the printer object. 
	*/

  wxPrintDialogData& GetPrintDialogData() ;
	/**
	 * \brief Starts the printing process. Provide a parent window, a user-defined wxPrintout object which controls
the printing of a document, and whether the print dialog should be invoked first.

Print could return false if there was a problem initializing the printer device context
(current printer not set, for example) or the user cancelled printing. Call
  to get detailed
information about the kind of the error. 
	 * \param wxWindow *  
	 * \param wxPrintout *  
	 * \param bool   
	*/

  bool Print(wxWindow * parent , wxPrintout * printout , bool  prompt = true) ;
	/**
	 * \brief Invokes the print dialog. If successful (the user did not press Cancel
and no error occurred), a suitable device context will be returned
(otherwise NULL is returned -- call
  to get detailed
information about the kind of the error).

The application must delete this device context to avoid a memory leak. 
	 * \param wxWindow *  
	*/

  wxDC* PrintDialog(wxWindow * parent ) ;
	/**
	 * \brief Default error-reporting function. 
	 * \param wxWindow *  
	 * \param wxPrintout *  
	 * \param const wxString&   
	*/

  void ReportError(wxWindow * parent , wxPrintout * printout , const wxString&  message ) ;
	/**
	 * \brief Invokes the print setup dialog. Note that the setup dialog is obsolete from
Windows 95, though retained for backward compatibility. 
	 * \param wxWindow *  
	*/

  bool Setup(wxWindow * parent ) ;
};


#endif
