// wxDocMDIParentFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDocMDIParentFrame_h_)
#define _wxDocMDIParentFrame_h_
class wxDocMDIParentFrame : public wxMDIParentFrame
{
public:
	/**
	 * \brief Constructor. 
	 * \param wxDocManager*  
	 * \param wxFrame *  
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	*/

   wxDocMDIParentFrame(wxDocManager*  manager , wxFrame * parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = wxT("frame")) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxDocMDIParentFrame() ;
	/**
	 * \brief Deletes all views and documents. If no user input cancelled the
operation, the frame will be destroyed and the application will exit.

Since understanding how document/view clean-up takes place can be difficult,
the implementation of this function is shown below. 
	 * \param wxCloseEvent&  
	*/

  virtual void OnCloseWindow(wxCloseEvent&  event ) ;
};


#endif
