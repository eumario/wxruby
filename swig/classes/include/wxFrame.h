// wxFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFrame_h_)
#define _wxFrame_h_
class wxFrame : public wxWindow
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxFrame() ;
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

   wxFrame(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame") ;
	/**
	 * \brief Destructor. Destroys all child windows and menu bar if present. 
	*/

  virtual  ~wxFrame() ;
	/**
	 * \brief Centres the frame on the display. 
	 * \param int  
	*/

  void Centre(int direction = wxBOTH) ;
	/**
	 * \brief Simulate a menu command. 
	 * \param int   
	*/

  void Command(int  id ) ;
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

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame") ;
	/**
	 * \brief Creates a status bar at the bottom of the frame. 
	 * \param int  
	 * \param long  
	 * \param wxWindowID  
	 * \param const wxString&  
	*/

  virtual wxStatusBar* CreateStatusBar(int number = 1, long style = 0, wxWindowID id = -1, const wxString& name = "statusBar") ;
	/**
	 * \brief Creates a toolbar at the top or left of the frame. 
	 * \param long  
	 * \param wxWindowID  
	 * \param const wxString&  
	*/

  virtual wxToolBar* CreateToolBar(long style = wxNO_BORDER, wxWindowID id = -1, const wxString& name = "toolBar") ;
	/**
	 * \brief Returns the origin of the frame client area (in client coordinates). It may be
different from (0, 0) if the frame has a toolbar. 
	*/

  wxPoint GetClientAreaOrigin() const;
	/**
	 * \brief  
	*/

  wxMenuBar* GetMenuBar() const;
	/**
	 * \brief  
	*/

  wxStatusBar* GetStatusBar() const;
	/**
	 * \brief Returns the status bar pane used to display menu and toolbar help. 
	*/

  int GetStatusBarPane() ;
	/**
	 * \brief Gets a string containing the frame title. See  . 
	*/

  wxString GetTitle() const;
	/**
	 * \brief  
	*/

  wxToolBar* GetToolBar() const;
	/**
	 * \brief  
	 * \param bool  
	*/

  void Iconize(bool  iconize ) ;
	/**
	 * \brief Returns true if the frame is in fullscreen mode. 
	*/

  bool IsFullScreen() ;
	/**
	 * \brief Returns true if the frame is iconized. 
	*/

  bool IsIconized() const;
	/**
	 * \brief Returns true if the frame is maximized. 
	*/

  bool IsMaximized() const;
	/**
	 * \brief Maximizes or restores the frame. 
	 * \param bool   
	*/

  void Maximize(bool  maximize ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param long  
	 * \param wxWindowID  
	 * \param const wxString&  
	*/

  virtual wxStatusBar* OnCreateStatusBar(int  number , long  style , wxWindowID  id , const wxString&  name ) ;
	/**
	 * \brief  
	 * \param long  
	 * \param wxWindowID  
	 * \param const wxString&  
	*/

  virtual wxToolBar* OnCreateToolBar(long  style , wxWindowID  id , const wxString&  name ) ;
	/**
	 * \brief This function sends a dummy   to the frame
forcing it to reevaluate its children positions. It is sometimes useful to call
this function after adding or deleting a children after the frame creation or
if a child size changes.

Note that if the frame is using either sizers or constraints for the children
layout, it is enough to call   directly and
this function should not be used in this case. 
	*/

  void SendSizeEvent() ;
	/**
	 * \brief Sets the icon for this frame. 
	 * \param const wxIcon&   
	*/

  void SetIcon(const wxIcon&  icon ) ;
	/**
	 * \brief Sets the icons for this frame.





See also  . 
	 * \param const wxIconBundle&   
	*/

  void SetIcons(const wxIconBundle&  icons ) ;
	/**
	 * \brief  
	 * \param wxMenuBar*   
	*/

  void SetMenuBar(wxMenuBar*  menuBar ) ;
	/**
	 * \brief If the platform supports it, sets the shape of the window to that
depicted by \it{region}.  The system will not display or
respond to any mouse event for the pixels that lie outside of the
region.  To reset the window to the normal rectangular shape simply
call \it{SetShape} again with an empty region.  Returns TRUE if the
operation is successful. 
	 * \param const wxRegion&  
	*/

  bool SetShape(const wxRegion&  region ) ;
	/**
	 * \brief  
	 * \param wxStatusBar*  
	*/

  void SetStatusBar(wxStatusBar*  statusBar ) ;
	/**
	 * \brief Set the status bar pane used to display menu and toolbar help.
Using -1 disables help display. 
	 * \param int  
	*/

  void SetStatusBarPane(int  n ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param int  
	*/

  virtual void SetStatusText(const wxString&   text , int number = 0) ;
	/**
	 * \brief Sets the widths of the fields in the status bar.



\wxheading{n}{The number of fields in the status bar. It must be the
same used in  .} 
	 * \param int  
	 * \param int *  
	*/

  virtual void SetStatusWidths(int  n , int * widths ) ;
	/**
	 * \brief  
	 * \param wxToolBar*  
	*/

  void SetToolBar(wxToolBar*  toolBar ) ;
	/**
	 * \brief Sets the frame title. 
	 * \param const wxString&   
	*/

  virtual void SetTitle(const wxString&   title ) ;
	/**
	 * \brief Depending on the value of   parameter the frame is either shown full
screen or restored to its normal state.   is a bit list containing
some or all of the following values, which indicate what elements of the frame
to hide in full-screen mode:

 

This function has not been tested with MDI frames.

Note that showing a frame full screen also actually
  if it hadn't been shown yet. 
	 * \param bool  
	 * \param long  
	*/

  bool ShowFullScreen(bool  show , long style = wxFULLSCREEN_ALL) ;
};


#endif
