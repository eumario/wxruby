// wxPreviewFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPreviewFrame_h_)
#define _wxPreviewFrame_h_
class wxPreviewFrame : public wxFrame
{
public:
	/**
	 * \brief Constructor. Pass a print preview object plus other normal frame arguments.
The print preview object will be destroyed by the frame when it closes. 
	 * \param wxPrintPreview*   
	 * \param wxWindow*   
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize& size   
	 * \param long  
	 * \param const wxString&   
	*/

   wxPreviewFrame(wxPrintPreview*  preview , wxWindow*  parent , const wxString&  title , const wxPoint&  pos = wxDefaultPosition, const wxSize& size  size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame") ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxPreviewFrame() ;
	/**
	 * \brief Creates a wxPreviewControlBar. Override this function to allow
a user-defined preview control bar object to be created. 
	*/

  void CreateControlBar() ;
	/**
	 * \brief Creates a wxPreviewCanvas. Override this function to allow
a user-defined preview canvas object to be created. 
	*/

  void CreateCanvas() ;
	/**
	 * \brief Creates the preview canvas and control bar, and calls
wxWindow::MakeModal(true) to disable other top-level windows
in the application.

This function should be called by the application prior to
showing the frame. 
	*/

  void Initialize() ;
	/**
	 * \brief Enables the other frames in the application, and deletes the print preview
object, implicitly deleting any printout objects associated with the print
preview object. 
	 * \param wxCloseEvent&  
	*/

  virtual void OnCloseWindow(wxCloseEvent&  event ) ;
};


#endif
