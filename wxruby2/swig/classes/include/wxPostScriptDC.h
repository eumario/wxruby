// wxPostScriptDC.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPostScriptDC_h_)
#define _wxPostScriptDC_h_
class wxPostScriptDC : public wxDC
{
public:
	/**
	 * \brief Constructs a PostScript printer device context from a   object. 
	 * \param const wxPrintData&  
	*/

   wxPostScriptDC(const wxPrintData&  printData ) ;
	/**
	 * \brief Constructor.   is an optional file for printing to, and if
  is true a dialog box will be displayed for adjusting
various parameters.   is the parent of the printer dialog box.

Use the   member to test whether the constructor was successful
in creating a usable device context.

See   for functions to set and
get PostScript printing settings.

This constructor and the global printer settings are now deprecated;
use the wxPrintData constructor instead. 
	 * \param const wxString&   
	 * \param bool   
	 * \param wxWindow *  
	*/

   wxPostScriptDC(const wxString&  output , bool  interactive = true, wxWindow * parent ) ;
	/**
	 * \brief Set resolution (in pixels per inch) that will be used in PostScript
output. Default is 720ppi. 
	 * \param int  
	*/

  static void SetResolution(int  ppi ) ;
	/**
	 * \brief Return resolution used in PostScript output. See 
 . 
	*/

  static int GetResolution() ;
};


#endif
