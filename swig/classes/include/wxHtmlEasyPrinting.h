// wxHtmlEasyPrinting.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlEasyPrinting_h_)
#define _wxHtmlEasyPrinting_h_
class wxHtmlEasyPrinting : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	 * \param const wxString&   
	 * \param wxWindow*   
	*/

   wxHtmlEasyPrinting(const wxString&  name = "Printing", wxWindow*  parentWindow = NULL) ;
	/**
	 * \brief Preview HTML file. 

Returns false in case of error -- call
  to get detailed
information about the kind of the error. 
	 * \param const wxString&   
	*/

  bool PreviewFile(const wxString&  htmlfile ) ;
	/**
	 * \brief Preview HTML text (not file!). 

Returns false in case of error -- call
  to get detailed
information about the kind of the error. 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  bool PreviewText(const wxString&  htmltext , const wxString&  basepath = wxEmptyString) ;
	/**
	 * \brief Print HTML file.

Returns false in case of error -- call
  to get detailed
information about the kind of the error. 
	 * \param const wxString&   
	*/

  bool PrintFile(const wxString&  htmlfile ) ;
	/**
	 * \brief Print HTML text (not file!). 

Returns false in case of error -- call
  to get detailed
information about the kind of the error. 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  bool PrintText(const wxString&  htmltext , const wxString&  basepath = wxEmptyString) ;
	/**
	 * \brief Display printer setup dialog and allows the user to modify settings. 
	*/

  void PrinterSetup() ;
	/**
	 * \brief Display page setup dialog and allows the user to modify settings. 
	*/

  void PageSetup() ;
	/**
	 * \brief Sets fonts. See   for
detailed description. 
	 * \param wxString   
	 * \param wxString   
	 * \param const int   
	*/

  void SetFonts(wxString  normal_face , wxString  fixed_face , const int  *sizes = NULL) ;
	/**
	 * \brief Set page header. 
	 * \param const wxString&   
	 * \param int   
	*/

  void SetHeader(const wxString&  header , int  pg = wxPAGE_ALL) ;
	/**
	 * \brief Set page footer. 
	 * \param const wxString&   
	 * \param int   
	*/

  void SetFooter(const wxString&  footer , int  pg = wxPAGE_ALL) ;
	/**
	 * \brief Returns pointer to   instance used by this class. You can
set its parameters (via SetXXXX methods). 
	*/

  wxPrintData* GetPrintData() ;
	/**
	 * \brief Returns a pointer to   instance used by 
this class. You can set its parameters (via SetXXXX methods). 
	*/

  wxPageSetupDialogData* GetPageSetupData() ;
};


#endif
