// wxPrinterDC.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrinterDC_h_)
#define _wxPrinterDC_h_
class wxPrinterDC : public wxDC
{
public:
	/**
	 * \brief Pass a   object with information
necessary for setting up a suitable printer device context. This
is the recommended way to construct a wxPrinterDC. 
	 * \param const wxPrintData&   
	*/

   wxPrinterDC(const wxPrintData&  printData ) ;
	/**
	 * \brief Constructor. With empty strings for the first three arguments, the default printer dialog is
displayed.   indicates the type of printer and  
is an optional file for printing to. The   parameter is
currently unused.  Use the   member to test whether the
constructor was successful in creating a usable device context.

This constructor is deprecated and retained only for backward compatibility. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const bool   
	 * \param int   
	*/

   wxPrinterDC(const wxString&  driver , const wxString&  device , const wxString&  output , const bool  interactive = true, int  orientation = wxPORTRAIT) ;
};


#endif
