// wxSplitterWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSplitterWindow_h_)
#define _wxSplitterWindow_h_
class wxSplitterWindow : public wxWindow
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxSplitterWindow() ;
	/**
	 * \brief  
	 * \param wxWindow*  
	 * \param wxWindowID  
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&  
	*/

   wxSplitterWindow(wxWindow*  parent , wxWindowID  id , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxSP_3D, const wxString& name = wxT("splitterWindow")) ;
	/**
	 * \brief Destroys the wxSplitterWindow and its children. 
	*/

  virtual  ~wxSplitterWindow() ;
	/**
	 * \brief Creation function, for two-step construction. See   for
details. 
	 * \param wxWindow*  
	 * \param wxWindowID  
	 * \param int   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&  
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxSP_3D, const wxString& name = wxT("splitterWindow")) ;
	/**
	 * \brief Returns the current minimum pane size (defaults to zero). 
	*/

  int GetMinimumPaneSize() const;

    // Gets the sash gravity
    double GetSashGravity() const;

	/**
	 * \brief Returns the current sash position. 
	*/

  int GetSashPosition() ;
	/**
	 * \brief  
	*/

    // Gets the sash size
    int GetSashSize() const;

  int GetSplitMode() const;
	/**
	 * \brief Returns the left/top or only pane. 
	*/

  wxWindow* GetWindow1() const;
	/**
	 * \brief Returns the right/bottom pane. 
	*/

  wxWindow* GetWindow2() const;
	/**
	 * \brief Initializes the splitter window to have one pane. 
	 * \param wxWindow*   
	*/

  void Initialize(wxWindow*  window ) ;
	/**
	 * \brief Returns true if the window is split, false otherwise. 
	*/

  bool IsSplit() const;
	/**
	 * \brief Application-overridable function called when the sash is double-clicked with
the left mouse button. 
	 * \param int   
	 * \param int   
	*/

  virtual void OnDoubleClickSash(int  x , int  y ) ;
	/**
	 * \brief Application-overridable function called when the window is unsplit, either
programmatically or using the wxSplitterWindow user interface. 
	 * \param wxWindow*   
	*/

  virtual void OnUnsplit(wxWindow*  removed ) ;
	/**
	 * \brief Application-overridable function called when the sash position is changed by 
user. It may return false to prevent the change or true to allow it. 
	 * \param int   
	*/

  virtual bool OnSashPositionChange(int  newSashPosition ) ;
	/**
	 * \brief This function replaces one of the windows managed by the wxSplitterWindow with
another one. It is in general better to use it instead of calling Unsplit()
and then resplitting the window back because it will provoke much less flicker
(if any). It is valid to call this function whether the splitter has two
windows or only one.

Both parameters should be non-NULL and   must specify one of the
windows managed by the splitter. If the parameters are incorrect or the window
couldn't be replaced, false is returned. Otherwise the function will return
true, but please notice that it will not delete the replaced window and you
may wish to do it yourself.

\wxheading{See also} 
	 * \param wxWindow *   
	 * \param wxWindow *   
	*/

  bool ReplaceWindow(wxWindow *  winOld , wxWindow *  winNew ) ;

    // Set the sash gravity
    void SetSashGravity(double gravity);

	/**
	 * \brief Sets the sash position. 
	 * \param int   
	 * \param const bool  
	*/

  void SetSashPosition(int  position , const bool redraw = true) ;
	/**
	 * \brief Sets the minimum pane size. 
	 * \param int   
	*/

    // Sets the sash size
  void SetSashSize(int width) ;

  void SetMinimumPaneSize(int  paneSize ) ;
	/**
	 * \brief  
	 * \param int   
	*/

  void SetSplitMode(int  mode ) ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param wxWindow*   
	 * \param int  
	*/

  bool SplitHorizontally(wxWindow*  window1 , wxWindow*  window2 , int sashPosition = 0) ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param wxWindow*   
	 * \param int  
	*/

  bool SplitVertically(wxWindow*  window1 , wxWindow*  window2 , int sashPosition = 0) ;
	/**
	 * \brief  
	 * \param wxWindow*   
	*/

  bool Unsplit(wxWindow*  toRemove = NULL) ;

    // Make sure the child window sizes are updated. This is useful
    // for reducing flicker by updating the sizes before a
    // window is shown, if you know the overall size is correct.
    void UpdateSize();

};


#endif
