// wxPrintPreview.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrintPreview_h_)
#define _wxPrintPreview_h_
class wxPrintPreview : public wxObject
{
public:
	/**
	 * \brief Constructor. Pass a printout object, an optional printout object to be
used for actual printing, and the address of an optional
block of printer data, which will be copied to the print preview object's
print data.

If   is non-NULL, a   button will be placed on the
preview frame so that the user can print directly from the preview interface.

Do not explicitly delete the printout objects once this destructor has been
called, since they will be deleted in the wxPrintPreview constructor.
The same does not apply to the   argument.

Test the Ok member to check whether the wxPrintPreview object was created correctly.
Ok could return false if there was a problem initializing the printer device context
(current printer not set, for example). 
	 * \param wxPrintout*   
	 * \param wxPrintout*   
	 * \param wxPrintData*   
	*/

   wxPrintPreview(wxPrintout*  printout , wxPrintout*  printoutForPrinting , wxPrintData*  data = NULL) ;
	/**
	 * \brief Destructor. Deletes both print preview objects, so do not destroy these objects
in your application. 
	*/

  virtual  ~wxPrintPreview() ;
	/**
	 * \brief Draws a representation of the blank page into the preview window. Used
internally. 
	 * \param wxWindow*   
	*/

  bool DrawBlankPage(wxWindow*  window ) ;
	/**
	 * \brief Gets the preview window used for displaying the print preview image. 
	*/

  wxWindow*  GetCanvas() ;
	/**
	 * \brief Gets the page currently being previewed. 
	*/

  int GetCurrentPage() ;
	/**
	 * \brief Gets the frame used for displaying the print preview canvas
and control bar. 
	*/

  wxFrame * GetFrame() ;
	/**
	 * \brief Returns the maximum page number. 
	*/

  int GetMaxPage() ;
	/**
	 * \brief Returns the minimum page number. 
	*/

  int GetMinPage() ;
	/**
	 * \brief Returns a reference to the internal print data. 
	*/

  wxPrintData& GetPrintData() ;
	/**
	 * \brief Gets the preview printout object associated with the wxPrintPreview object. 
	*/

  wxPrintout * GetPrintout() ;
	/**
	 * \brief Gets the printout object to be used for printing from within the preview interface,
or NULL if none exists. 
	*/

  wxPrintout * GetPrintoutForPrinting() ;
	/**
	 * \brief Returns true if the wxPrintPreview is valid, false otherwise. It could return false if there was a
problem initializing the printer device context (current printer not set, for example). 
	*/

  bool Ok() ;
	/**
	 * \brief This refreshes the preview window with the preview image.
It must be called from the preview window's OnPaint member.

The implementation simply blits the preview bitmap onto
the canvas, creating a new preview bitmap if none exists. 
	 * \param wxWindow*   
	*/

  bool PaintPage(wxWindow*  window ) ;
	/**
	 * \brief Invokes the print process using the second wxPrintout object
supplied in the wxPrintPreview constructor.
Will normally be called by the   panel item on the
preview frame's control bar.

Returns false in case of error -- call
  to get detailed
information about the kind of the error. 
	 * \param bool   
	*/

  bool Print(bool  prompt ) ;
	/**
	 * \brief Renders a page into a wxMemoryDC. Used internally by wxPrintPreview. 
	 * \param int   
	*/

  bool RenderPage(int  pageNum ) ;
	/**
	 * \brief Sets the window to be used for displaying the print preview image. 
	 * \param wxWindow*   
	*/

  void SetCanvas(wxWindow*  window ) ;
	/**
	 * \brief Sets the current page to be previewed. 
	 * \param int  
	*/

  void SetCurrentPage(int  pageNum ) ;
	/**
	 * \brief Sets the frame to be used for displaying the print preview canvas
and control bar. 
	 * \param wxFrame *  
	*/

  void SetFrame(wxFrame * frame ) ;
	/**
	 * \brief Associates a printout object with the wxPrintPreview object. 
	 * \param wxPrintout *  
	*/

  void SetPrintout(wxPrintout * printout ) ;
	/**
	 * \brief Sets the percentage preview zoom, and refreshes the preview canvas
accordingly. 
	 * \param int  
	*/

  void SetZoom(int  percent ) ;
};


#endif
