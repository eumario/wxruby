// wxPrintout.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrintout_h_)
#define _wxPrintout_h_
class wxPrintout : public wxObject
{
public:
	/**
	 * \brief Constructor. Pass an optional title argument - the current filename would be a good idea. This will appear in the printing list
(at least in MSW) 
	 * \param const wxString&   
	*/

   wxPrintout(const wxString&  title = "Printout") ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxPrintout() ;
	/**
	 * \brief Returns the device context associated with the printout (given to the printout at start of
printing or previewing). This will be a wxPrinterDC if printing under Windows,
a wxPostScriptDC if printing on other platforms, and a wxMemoryDC if previewing. 
	*/

  wxDC * GetDC() ;
	/**
	 * \brief Called by the framework to obtain information from the application about minimum and maximum page values that
the user can select, and the required page range to be printed. By default this
returns 1, 32000 for the page minimum and maximum values, and 1, 1 for the required page range.

If   is zero, the page number controls in the print dialog will be disabled.

\pythonnote{When this method is implemented in a derived Python class,
it should be designed to take no parameters (other than the self
reference) and to return a tuple of four integers.
}

\perlnote{When this method is overridden in a derived class,
it must not take any parameters, an return a 4-element list.
} 
	 * \param int *  
	 * \param int *  
	 * \param int *  
	 * \param int *  
	*/

  void GetPageInfo(int * minPage , int * maxPage , int * pageFrom , int * pageTo ) ;
	/**
	 * \brief Returns the size of the printer page in millimetres.

\pythonnote{This method returns the output-only parameters as a tuple.}

\perlnote{In wxPerl this method takes no arguments and returns a
2-element list  } 
	 * \param int *  
	 * \param int *  
	*/

  void GetPageSizeMM(int * w , int * h ) ;
	/**
	 * \brief Returns the size of the printer page in pixels. These may not be the
same as the values returned from   if
the printout is being used for previewing, since in this case, a
memory device context is used, using a bitmap size reflecting the current
preview zoom. The application must take this discrepancy into account if
previewing is to be supported.

\pythonnote{This method returns the output-only parameters as a tuple.}

\perlnote{In wxPerl this method takes no arguments and returns a
2-element list  } 
	 * \param int *  
	 * \param int *  
	*/

  void GetPageSizePixels(int * w , int * h ) ;
	/**
	 * \brief Returns the number of pixels per logical inch of the printer device context.
Dividing the printer PPI by the screen PPI can give a suitable scaling
factor for drawing text onto the printer. Remember to multiply
this by a scaling factor to take the preview DC size into account.

\pythonnote{This method returns the output-only parameters as a tuple.}

\perlnote{In wxPerl this method takes no arguments and returns a
2-element list  } 
	 * \param int *  
	 * \param int *  
	*/

  void GetPPIPrinter(int * w , int * h ) ;
	/**
	 * \brief Returns the number of pixels per logical inch of the screen device context.
Dividing the printer PPI by the screen PPI can give a suitable scaling
factor for drawing text onto the printer. Remember to multiply
this by a scaling factor to take the preview DC size into account. 
	 * \param int *  
	 * \param int *  
	*/

  void GetPPIScreen(int * w , int * h ) ;
	/**
	 * \brief Returns the title of the printout

\pythonnote{This method returns the output-only parameters as a tuple.}

\perlnote{In wxPerl this method takes no arguments and returns a
2-element list  } 
	*/

  wxString GetTitle() ;
	/**
	 * \brief Should be overridden to return true if the document has this page, or false
if not. Returning false signifies the end of the document. By default,
HasPage behaves as if the document has only one page. 
	 * \param int  
	*/

  bool HasPage(int  pageNum ) ;
	/**
	 * \brief Returns true if the printout is currently being used for previewing. 
	*/

  bool IsPreview() ;
	/**
	 * \brief Called by the framework at the start of document printing. Return false from
this function cancels the print job. OnBeginDocument is called once for every
copy printed.

The base wxPrintout::OnBeginDocument   be called (and the return value
checked) from within the overridden function, since it calls wxDC::StartDoc.

\pythonnote{If this method is overridden in a Python class then the
base class version can be called by using the method
 . } 
	 * \param int  
	 * \param int  
	*/

  virtual bool OnBeginDocument(int  startPage , int  endPage ) ;
	/**
	 * \brief Called by the framework at the end of document printing. OnEndDocument
is called once for every copy printed.

The base wxPrintout::OnEndDocument   be called
from within the overridden function, since it calls wxDC::EndDoc. 
	*/

  virtual void OnEndDocument() ;
	/**
	 * \brief Called by the framework at the start of printing. OnBeginPrinting is called once for every
print job (regardless of how many copies are being printed). 
	*/

  virtual void OnBeginPrinting() ;
	/**
	 * \brief Called by the framework at the end of printing. OnEndPrinting
is called once for every print job (regardless of how many copies are being printed). 
	*/

  virtual void OnEndPrinting() ;
	/**
	 * \brief Called once by the framework before any other demands are made of the
wxPrintout object. This gives the object an opportunity to calculate the
number of pages in the document, for example. 
	*/

  virtual void OnPreparePrinting() ;
	/**
	 * \brief Called by the framework when a page should be printed. Returning false cancels
the print job. The application can use wxPrintout::GetDC to obtain a device
context to draw on. 
	 * \param int  
	*/

  virtual bool OnPrintPage(int  pageNum ) ;
};


#endif
