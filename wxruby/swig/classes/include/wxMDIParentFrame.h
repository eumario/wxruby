// wxMDIParentFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMDIParentFrame_h_)
#define _wxMDIParentFrame_h_
class wxMDIParentFrame : public wxFrame
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxMDIParentFrame() ;
	/**
	 * \brief Constructor, creating the window. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	*/

   wxMDIParentFrame(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = wxT("frame")) ;
	/**
	 * \brief Destructor. Destroys all child windows and menu bar if present. 
	*/

  virtual  ~wxMDIParentFrame() ;
	/**
	 * \brief Activates the MDI child following the currently active one. 
	*/

  void ActivateNext() ;
	/**
	 * \brief Activates the MDI child preceding the currently active one. 
	*/

  void ActivatePrevious() ;
	/**
	 * \brief Arranges any iconized (minimized) MDI child windows. 
	*/

  void ArrangeIcons() ;
	/**
	 * \brief Arranges the MDI child windows in a cascade. 
	*/

  void Cascade() ;
	/**
	 * \brief Used in two-step frame construction. See  
for further details. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = wxT("frame")) ;
	/**
	 * \brief This gets the size of the frame `client area' in pixels. 
	 * \param int*   
	 * \param int*   
	*/

  virtual void GetClientSize(int*  width , int*  height ) const;
	/**
	 * \brief Returns a pointer to the active MDI child, if there is one. 
	*/

  wxMDIChildFrame* GetActiveChild() const;
	/**
	 * \brief Returns a pointer to the client window. 
	*/

  wxMDIClientWindow* GetClientWindow() const;
	/**
	 * \brief Returns the window being used as the toolbar for this frame. 
	*/

  // TODO: Was virtual.  Causes a crash if left virtual.
  wxToolBar* GetToolBar() const;
	/**
	 * \brief Returns the current Window menu (added by wxWindows to the menubar). This function
is available under Windows only. 
	*/

  wxMenu* GetWindowMenu() const;
	/**
	 * \brief Override this to return a different kind of client window. If you override this function,
you must create your parent frame in two stages, or your function will never be called,
due to the way C++ treats virtual functions called from constructors. For example: 
	*/

  // TODO: Was virtual.  Causes a crash if left virtual.
  wxMDIClientWindow* OnCreateClient() ;
	/**
	 * \brief Sets the window to be used as a toolbar for this
MDI parent window. It saves the application having to manage the positioning
of the toolbar MDI client window. 
	 * \param wxWindow*  
	*/

  virtual void SetToolBar(wxToolBar*  toolbar );
	/**
	 * \brief Call this to change the current Window menu. Ownership of the menu object passes to
the frame when you call this function.

This call is available under Windows only.

To remove the window completely, use the wxFRAME_NO_WINDOW_MENU window style. 
	 * \param wxMenu*  
	*/

  void SetWindowMenu(wxMenu*  menu ) ;
	/**
	 * \brief Tiles the MDI child windows. 
	*/

  void Tile() ;
};


#endif
