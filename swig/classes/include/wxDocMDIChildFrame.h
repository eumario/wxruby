// wxDocMDIChildFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDocMDIChildFrame_h_)
#define _wxDocMDIChildFrame_h_
class wxDocMDIChildFrame : public wxMDIChildFrame
{
public:
	/**
	 * \brief Constructor. 
	 * \param wxDocument*   
	 * \param wxView*   
	 * \param wxFrame*   
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	*/

   wxDocMDIChildFrame(wxDocument*  doc , wxView*  view , wxFrame*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = wxT("frame")) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxDocMDIChildFrame() ;
	/**
	 * \brief Returns the document associated with this frame. 
	*/

  wxDocument* GetDocument() const;
	/**
	 * \brief Returns the view associated with this frame. 
	*/

  wxView* GetView() const;
	/**
	 * \brief Sets the currently active view to be the frame's view. You may need
to override (but still call) this function in order to set the keyboard
focus for your subwindow. 
	 * \param wxActivateEvent  
	*/

  virtual void OnActivate(wxActivateEvent  event ) ;
	/**
	 * \brief Closes and deletes the current view and document. 
	 * \param wxCloseEvent&  
	*/

  virtual void OnCloseWindow(wxCloseEvent&  event ) ;
	/**
	 * \brief Sets the document for this frame. 
	 * \param wxDocument *  
	*/

  void SetDocument(wxDocument * doc ) ;
	/**
	 * \brief Sets the view for this frame. 
	 * \param wxView *  
	*/

  void SetView(wxView * view ) ;
};


#endif
