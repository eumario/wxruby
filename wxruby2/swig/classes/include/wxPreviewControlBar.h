// wxPreviewControlBar.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPreviewControlBar_h_)
#define _wxPreviewControlBar_h_
class wxPreviewControlBar : public wxPanel
{
public:
	/**
	 * \brief Constructor.

The buttons parameter may be a combination of the following, using the bitwise `or' operator. 
	 * \param wxPrintPreview*   
	 * \param long  
	 * \param wxWindow*   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

   wxPreviewControlbar(wxPrintPreview*  preview , long  buttons , wxWindow*  parent , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = "panel") ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxPreviewControlBar() ;
	/**
	 * \brief Creates buttons, according to value of the button style flags. 
	*/

  void CreateButtons() ;
	/**
	 * \brief Gets the print preview object associated with the control bar. 
	*/

  wxPrintPreview * GetPrintPreview() ;
	/**
	 * \brief Gets the current zoom setting in percent. 
	*/

  int GetZoomControl() ;
	/**
	 * \brief Sets the zoom control. 
	 * \param int   
	*/

  void SetZoomControl(int  percent ) ;
};


#endif
