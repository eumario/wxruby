// wxHtmlPrintout.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlPrintout_h_)
#define _wxHtmlPrintout_h_
class wxHtmlPrintout : public wxPrintout
{
public:
	/**
	 * \brief Constructor. 
	 * \param const wxString&   
	*/

   wxHtmlPrintout(const wxString&  title = wxT("Printout")) ;
	/**
	 * \brief Sets fonts. See   for
detailed description. 
	 * \param wxString   
	 * \param wxString   
	 * \param const int   
	*/

  void SetFonts(wxString  normal_face , wxString  fixed_face , const int  *sizes = NULL) ;
	/**
	 * \brief Sets page footer. 
	 * \param const wxString&   
	 * \param int   
	*/

  void SetFooter(const wxString&  footer , int  pg = wxPAGE_ALL) ;
	/**
	 * \brief Sets page header. 
	 * \param const wxString&   
	 * \param int   
	*/

  void SetHeader(const wxString&  header , int  pg = wxPAGE_ALL) ;
	/**
	 * \brief Prepare the class for printing this HTML  . The file may be located on 
any virtual file system or it may be normal file. 
	 * \param const wxString&   
	*/

  void SetHtmlFile(const wxString&  htmlfile ) ;
	/**
	 * \brief Prepare the class for printing this HTML text. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param bool   
	*/

  void SetHtmlText(const wxString&  html , const wxString&  basepath = wxEmptyString, bool  isdir = true) ;
	/**
	 * \brief Sets margins in millimeters. Defaults to 1 inch for margins and 0.5cm for space
between text and header and/or footer 
	 * \param float   
	 * \param float   
	 * \param float   
	 * \param float   
	 * \param float   
	*/

  void SetMargins(float  top = 25.2, float  bottom = 25.2, float  left = 25.2, float  right = 25.2, float  spaces = 5) ;
};


#endif
