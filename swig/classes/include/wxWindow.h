// wxWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWindow_h_)
#define _wxWindow_h_
class wxWindow : public wxEvtHandler
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxWindow() ;
	/**
	 * \brief Constructs a window, which can be a child of a frame, dialog or any other non-control window. 
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	*/

   wxWindow(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = 0, const wxString&  name = wxPanelNameStr) ;
	/**
	 * \brief Destructor. Deletes all subwindows, then deletes itself. Instead of using
the   operator explicitly, you should normally
use   so that wxWindows
can delete a window only when it is safe to do so, in idle time. 
	*/

  virtual  ~wxWindow() ;
	/**
	 * \brief Adds a child window.  This is called automatically by window creation
functions so should not be required by the application programmer. 
	 * \param wxWindow*   
	*/

  // FIXME? AcceptFocus causes problems because it is public here and protected
  //         in some derived classes.  Do not uncomment unless you also
  //         make sure to fix it in derived classes else things like
  //         StaticText will take the focus when tabbing
  // virtual bool AcceptsFocus() const;

  virtual void AddChild(wxWindow*  child ) ;
	/**
	 * \brief Directs all mouse input to this window. Call   to
release the capture.

Note that wxWindows maintains the stack of windows having captured the mouse
and when the mouse is released the capture returns to the window which had had
captured it previously and it is only really released if there were no previous
window. In particular, this means that you must release the mouse as many times
as you capture it. 
	*/

  virtual void CaptureMouse() ;
	/**
	 * \brief A synonym for  . 
	 * \param int  
	*/

  void Center(int  direction ) ;
	/**
	 * \brief A synonym for  . 
	 * \param int  
	*/

  void CenterOnParent(int  direction ) ;
	/**
	 * \brief A synonym for  . 
	 * \param int  
	*/

  void CenterOnScreen(int  direction ) ;
	/**
	 * \brief Centres the window.





The flag   is obsolete and should not be used any longer
(it has no effect). 
	 * \param int  
	*/

  void Centre(int direction = wxBOTH) ;
	/**
	 * \brief Centres the window on its parent. This is a more readable synonym for
 . 
	 * \param int  
	*/

  void CentreOnParent(int direction = wxBOTH) ;
	/**
	 * \brief Centres the window on screen. This only works for top level windows -
otherwise, the window will still be centered on its parent. 
	 * \param int  
	*/

  void CentreOnScreen(int direction = wxBOTH) ;

	/**
	 * \brief \perlnote{In wxPerl this method returns a 2-element list instead of
modifying its parameters.} 
	 * \param int*   
	 * \param int*   
	*/

  virtual void ClientToScreen(int*  x , int*  y ) const;
	/**
	 * \brief Converts to screen coordinates from coordinates relative to this window.







\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
} 
	 * \param const wxPoint&  
	*/

  virtual wxPoint ClientToScreen(const wxPoint&  pt ) const;
	/**
	 * \brief This function simply generates a   whose
handler usually tries to close the window. It doesn't close the window itself,
however. 
	 * \param bool  
	*/

  bool Close(bool force = false) ;
	/**
	 * \brief  
	 * \param const wxPoint&  
	*/

  wxPoint ConvertDialogToPixels(const wxPoint&  pt ) ;
	/**
	 * \brief  
	 * \param const wxSize&  
	*/

  wxSize ConvertDialogToPixels(const wxSize&  sz ) ;
	/**
	 * \brief  
	 * \param const wxPoint&  
	*/

  wxPoint ConvertPixelsToDialog(const wxPoint&  pt ) ;
	/**
	 * \brief  
	 * \param const wxSize&  
	*/

  wxSize ConvertPixelsToDialog(const wxSize&  sz ) ;
	/**
	 * \brief Destroys the window safely. Use this function instead of the delete operator, since
different window classes can be destroyed differently. Frames and dialogs
are not destroyed immediately when this function is called -- they are added
to a list of windows to be deleted on idle time, when all the window's events
have been processed. This prevents problems with events being sent to non-existent
windows. 
	*/

  virtual bool Destroy() ;
	/**
	 * \brief Destroys all children of a window.  Called automatically by the destructor. 
	*/

  virtual void DestroyChildren() ;
	/**
	 * \brief Disables the window, same as  . 
	*/

  void Disable() ;
	/**
	 * \brief Enables or disables eligibility for drop file events (OnDropFiles). 
	 * \param bool  
	*/

  ;
	/**
	 * \brief Enable or disable the window for user input. Note that when a parent window is
disabled, all of its children are disabled as well and they are reenabled again
when the parent is. 
	 * \param bool  
	*/

  virtual bool Enable(bool enable = true) ;
	/**
	 * \brief Finds the window or control which currently has the keyboard focus. 
	*/

  static wxWindow* FindFocus() ;
	/**
	 * \brief Find a child of this window, by identifier. 
	 * \param long  
	*/

  wxWindow* FindWindow(long  id ) const;
	/**
	 * \brief Find a child of this window, by name.

\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
} 
	 * \param const wxString&  
	*/

  wxWindow* FindWindow(const wxString&  name ) const;
	/**
	 * \brief Find the first window with the given  .

If   is NULL, the search will start from all top-level
frames and dialog boxes; if non-NULL, the search will be limited to the given window hierarchy.
The search is recursive in both cases. 
	 * \param long  
	 * \param wxWindow*  
	*/

  static wxWindow* FindWindowById(long  id , wxWindow* parent = NULL) ;
	/**
	 * \brief Find a window by its name (as given in a window constructor or   function call).
If   is NULL, the search will start from all top-level
frames and dialog boxes; if non-NULL, the search will be limited to the given window hierarchy.
The search is recursive in both cases.

If no window with such name is found, 
  is called. 
	 * \param const wxString&  
	 * \param wxWindow*  
	*/

  static wxWindow* FindWindowByName(const wxString&  name , wxWindow* parent = NULL) ;
	/**
	 * \brief Find a window by its label. Depending on the type of window, the label may be a window title
or panel item label. If   is NULL, the search will start from all top-level
frames and dialog boxes; if non-NULL, the search will be limited to the given window hierarchy.
The search is recursive in both cases. 
	 * \param const wxString&  
	 * \param wxWindow*  
	*/

  static wxWindow* FindWindowByLabel(const wxString&  label , wxWindow* parent = NULL) ;
	/**
	 * \brief Sizes the window so that it fits around its subwindows. This function won't do
anything if there are no subwindows. 
	*/

  virtual void Fit() ;
	/**
	 * \brief Similar to  , but sizes the interior (virtual) size
of a window.  Mainly useful with scrolled windows to reset scrollbars after
sizing changes that do not trigger a size event, and/or scrolled windows without
an interior sizer.  This function similarly won't do anything if there are no
subwindows. 
	*/

  virtual void FitInside() ;
	/**
	 * \brief Freezes the window or, in other words, prevents any updates from taking place
on screen, the window is not redrawn at all.   must
be called to reenable window redrawing.

This method is useful for visual appearance optimization (for example, it
is a good idea to use it before inserting large amount of text into a
wxTextCtrl under wxGTK) but is not implemented on all platforms nor for all
controls so it is mostly just a hint to wxWindows and not a mandatory
directive. 
	*/

  virtual void Freeze() ;
	/**
	 * \brief Returns the accessible object for this window, if any.

See also  . 
	*/

  //wxAccessible* GetAccessible();
	/**
	 * \brief This method is similar to  , except
in one thing.  GetBestSize should return the minimum untruncated size of the
window, while this method will return the largest of BestSize and any user
specified minimum size.  ie. it is the minimum size the window should currently
be drawn at, not the minimal size it can possibly tolerate. 
	*/

  wxSize GetAdjustedBestSize() const;
	/**
	 * \brief Returns the background colour of the window. 
	*/

  virtual wxColour GetBackgroundColour() const;
	/**
	 * \brief This functions returns the best acceptable minimal size for the window. For
example, for a static control, it will be the minimal size such that the
control label is not truncated. For windows containing subwindows (typically
 ), the size returned by this function will be the
same as the size the window would have had after calling
 . 
	*/

  virtual wxSize GetBestSize() const;

	void GetBestSize(int *w, int *h) const;
	/**
	 * \brief Returns the   associated with the window. 
	*/

  wxCaret * GetCaret() const;
	/**
	 * \brief  
	*/

  static wxWindow * GetCapture() ;
	/**
	 * \brief Returns the character height for this window. 
	*/

  virtual int GetCharHeight() const;
	/**
	 * \brief Returns the average character width for this window. 
	*/

  virtual int GetCharWidth() const;
	/**
	 * \brief Returns a reference to the list of the window's children. 
	*/

  wxList& GetChildren() ;
	/**
	 * \brief \perlnote{In wxPerl this method takes no parameter and returns
a 2-element list  .} 
	 * \param int*   
	 * \param int*   
	*/

  virtual void GetClientSize(int*  width , int*  height ) const;
	/**
	 * \brief This gets the size of the window `client area' in pixels.
The client area is the area which may be drawn on by the programmer,
excluding title bar, border, scrollbars, etc.







\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
} 
	*/

  virtual wxSize GetClientSize() const;
	/**
	 * \brief Returns a pointer to the window's layout constraints, or NULL if there are none. 
	*/

  wxLayoutConstraints* GetConstraints() const;
	/**
	 * \brief Return the sizer that this window is a member of, if any, otherwise
 . 
	*/

  const wxSizer * GetContainingSizer() const;
	/**
	 * \brief Returns the associated drop target, which may be NULL. 
	*/

  wxDropTarget* GetDropTarget() const;
	/**
	 * \brief Returns the event handler for this window. By default, the window is its
own event handler. 
	*/

  wxEvtHandler* GetEventHandler() const;
	/**
	 * \brief Returns the extra style bits for the window. 
	*/

  long GetExtraStyle() const;
	/**
	 * \brief Returns a reference to the font for this window. 
	*/

  wxFont GetFont() const;
	/**
	 * \brief Returns the foreground colour of the window. 
	*/

  virtual wxColour GetForegroundColour() ;
	/**
	 * \brief Returns the grandparent of a window, or NULL if there isn't one. 
	*/

  wxWindow* GetGrandParent() const;
	/**
	 * \brief Returns the platform-specific handle of the physical window. Cast it to an appropriate
handle, such as   for Windows,   for Motif or   for GTK.

\pythonnote{This method will return an integer in wxPython.}

\perlnote{This method will return an integer in wxPerl.} 
	*/

  void* GetHandle() const;
	/**
	 * \brief  
	*/

  virtual wxString GetHelpText() const;
	/**
	 * \brief Returns the identifier of the window. 
	*/

  int GetId() const;
	/**
	 * \brief Generic way of getting a label from any window, for
identification purposes. 
	*/

  virtual wxString  GetLabel() const;
	/**
	 * \brief Returns the window's name. 
	*/

  virtual wxString  GetName() const;
	/**
	 * \brief Returns the parent of the window, or NULL if there is no parent. 
	*/

  virtual wxWindow* GetParent() const;
	/**
	 * \brief  
	 * \param int*   
	 * \param int*   
	*/

  void GetPosition(int*  x , int*  y ) const;
	/**
	 * \brief This gets the position of the window in pixels, relative to the parent window
for the child windows or relative to the display origin for the top level
windows.







\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
}

\perlnote{In wxPerl there are two methods instead of a single overloaded
method:\par
\indented{2cm}{ 
}} 
	*/

  wxPoint GetPosition() const;
	/**
	 * \brief Returns the size and position of the window as a   object. 
	*/

  virtual wxRect GetRect() const;
	/**
	 * \brief Returns the built-in scrollbar thumb size. 
	 * \param int   
	*/

  virtual int GetScrollThumb(int  orientation ) ;
	/**
	 * \brief Returns the built-in scrollbar position. 
	 * \param int   
	*/

  virtual int GetScrollPos(int  orientation ) ;
	/**
	 * \brief Returns the built-in scrollbar range. 
	 * \param int   
	*/

  virtual int GetScrollRange(int  orientation ) ;
	/**
	 * \brief  
	 * \param int*   
	 * \param int*   
	*/

  virtual void GetSize(int*  width , int*  height ) const;
	/**
	 * \brief This gets the size of the entire window in pixels,
including title bar, border, scrollbars, etc.







\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
}

\perlnote{In wxPerl there are two methods instead of a single overloaded
method:\par
\indented{2cm}{ 
}} 
	*/

  virtual wxSize GetSize() const;
	/**
	 * \brief Return the sizer associated with the window by a previous call to
  or  . 
	*/

  wxSizer * GetSizer() const;
	/**
	 * \brief Gets the dimensions of the string as it would be drawn on the
window with the currently selected font.


















\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
}

\perlnote{In wxPerl this method takes only the   and optionally
   parameters, and returns a 4-element list
  .} 
	 * \param const wxString&   
	 * \param int*   
	 * \param int*   
	 * \param int*   
	 * \param int*   
	 * \param const wxFont*   
	 * \param bool  
	*/

  virtual void GetTextExtent(const wxString&  string , int * x , int * y , int * descent = NULL, int * externalLeading = NULL, wxFont * font = NULL) const;
	/**
	 * \brief Gets the window's title. Applicable only to frames and dialogs. 
	*/

  virtual wxString GetTitle() ;
	/**
	 * \brief Get the associated tooltip or NULL if none. 
	*/

  wxToolTip* GetToolTip() const;
	/**
	 * \brief Returns the region specifying which parts of the window have been damaged. Should
only be called within an   handler. 
	*/

  virtual wxRegion GetUpdateRegion() const;
	/**
	 * \brief Returns a pointer to the current validator for the window, or NULL if there is none. 
	*/

  wxValidator* GetValidator();
	/**
	 * \brief  
	 * \param int*   
	 * \param int*   
	*/

  void GetVirtualSize(int*  width , int*  height ) const;
	/**
	 * \brief This gets the virtual size of the window in pixels.







 , 
	*/

  wxSize GetVirtualSize() const;
	/**
	 * \brief Gets the window style that was passed to the constructor or  
method.   is another name for the same function. 
	*/

  long GetWindowStyleFlag() const;
	/**
	 * \brief  
	*/

  virtual bool HasCapture() const;
	/**
	 * \brief Equivalent to calling  ( ). 
	*/

  bool Hide() ;
	/**
	 * \brief Sends an   event, whose handler usually transfers data
to the dialog via validators. 
	*/

  void InitDialog() ;
	/**
	 * \brief Returns   if the window is enabled for input,   otherwise. 
	*/

  virtual bool IsEnabled() const;
	/**
	 * \brief Returns   if the window is retained,   otherwise. 
	*/

  virtual bool IsRetained() const;
	/**
	 * \brief Returns   if the window is shown,   if it has been hidden. 
	*/

  virtual bool IsShown() const;
	/**
	 * \brief Returns   if the given window is a top-level one. Currently all frames and
dialogs are considered to be top-level windows (even if they have a parent
window). 
	*/

  bool IsTopLevel() const;
	/**
	 * \brief Invokes the constraint-based layout algorithm or the sizer-based algorithm
for this window.

See  : when auto
layout is on, this function gets called automatically when the window is resized. 
	*/

  void Layout() ;
	/**
	 * \brief Lowers the window to the bottom of the window hierarchy if it is a managed window (dialog
or frame). 
	*/

  void Lower() ;
	/**
	 * \brief Disables all other windows in the application so that
the user can only interact with this window. (This function
is not implemented anywhere). 
	 * \param bool   
	*/

  virtual void MakeModal(bool  flag ) ;
	/**
	 * \brief  
	 * \param int  
	 * \param int  
	*/

  void Move(int  x , int  y ) ;
	/**
	 * \brief  
	 * \param const wxPoint&  
	*/

  void Move(const wxPoint&  pt ) ;
	/**
	 * \brief Removes and returns the top-most event handler on the event handler stack. 
	 * \param bool   
	*/

  wxEvtHandler* PopEventHandler(bool  deleteHandler = false);
	/**
	 * \brief  
	 * \param wxMenu*   
	 * \param const wxPoint&   
	*/

  bool PopupMenu(wxMenu*  menu , const wxPoint&  pos = wxDefaultPosition) ;
	/**
	 * \brief  
	 * \param wxMenu*   
	 * \param int   
	 * \param int   
	*/

  bool PopupMenu(wxMenu*  menu , int  x , int  y ) ;
	/**
	 * \brief Pushes this event handler onto the event stack for the window. 
	 * \param wxEvtHandler*   
	*/

  void PushEventHandler(wxEvtHandler*  handler ) ;
	/**
	 * \brief Raises the window to the top of the window hierarchy if it is a managed window (dialog
or frame). 
	*/

  void Raise() ;
	/**
	 * \brief Causes a message or event to be generated to repaint the
window. 
	 * \param bool  
	 * \param const wxRect*   
	*/

  virtual void Refresh(bool eraseBackground = true, const wxRect*  rect = NULL) ;
	/**
	 * \brief Redraws the contents of the given rectangle: the area inside it will be
repainted.

This is the same as   but has a nicer syntax. 
	 * \param const wxRect&   
	*/

  virtual void RefreshRect(const wxRect&  rect, bool eraseBackground = true) ;
	/**
	 * \brief  
	*/

//#ifdef __WXMSW__
#ifdef wxUSE_HOTKEY 
  bool RegisterHotKey(int hotkeyId, int modifiers, int virtualKeyCode);
	virtual bool UnregisterHotKey(int hotkeyId);
#endif

  virtual void ReleaseMouse() ;
	/**
	 * \brief Removes a child window.  This is called automatically by window deletion
functions so should not be required by the application programmer. 
	 * \param wxWindow*   
	*/

  virtual void RemoveChild(wxWindow*  child ) ;
	/**
	 * \brief Find the given   in the windows event handler chain and remove (but
not delete) it from it. 
	 * \param wxEvtHandler *  
	*/

  bool RemoveEventHandler(wxEvtHandler * handler ) ;
	/**
	 * \brief Reparents the window, i.e the window will be removed from its
current parent window (e.g. a non-standard toolbar in a wxFrame)
and then re-inserted into another. Available on Windows and GTK. 
	 * \param wxWindow*   
	*/

  virtual bool Reparent(wxWindow*  newParent ) ;
	/**
	 * \brief  
	 * \param int*   
	 * \param int*   
	*/

  virtual void ScreenToClient(int*  x , int*  y ) const;
	/**
	 * \brief Converts from screen to client window coordinates.









\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
} 
	 * \param const wxPoint&   
	*/

  virtual wxPoint ScreenToClient(const wxPoint&  pt ) const;
	/**
	 * \brief Scrolls the window by the given number of lines down (if   is
positive) or up. 
	 * \param int   
	*/

  virtual bool ScrollLines(int  lines ) ;
	/**
	 * \brief Scrolls the window by the given number of pages down (if   is
positive) or up. 
	 * \param int   
	*/

  virtual bool ScrollPages(int  pages ) ;
	/**
	 * \brief Physically scrolls the pixels in the window and move child windows accordingly. 
	 * \param int   
	 * \param int   
	 * \param const wxRect*  
	*/

  virtual void ScrollWindow(int  dx , int  dy , const wxRect* rect = NULL) ;
	/**
	 * \brief Sets the accelerator table for this window. See  . 
	 * \param const wxAcceleratorTable&  
	*/

  virtual void SetAcceleratorTable(const wxAcceleratorTable&  accel ) ;
	/**
	 * \brief Sets the accessible for this window. Any existing accessible for this window
will be deleted first, if not identical to  .

See also  . 
	 * \param wxAccessibile*  
	*/

  //void SetAccessible(wxAccessible*  accessible );
	/**
	 * \brief Determines whether the   function will
be called automatically when the window is resized. It is called implicitly by 
  but if you use 
  you should call it
manually or otherwise the window layout won't be correctly updated when its
size changes. 
	 * \param bool  
	*/

  void SetAutoLayout(bool  autoLayout ) ;
	/**
	 * \brief Sets the background colour of the window. 
	 * \param const wxColour&   
	*/

  virtual bool SetBackgroundColour(const wxColour&  colour );
	/**
	 * \brief Sets the   associated with the window. 
	 * \param wxCaret *  
	*/

  void SetCaret(wxCaret * caret );
	/**
	 * \brief  
	 * \param int  
	 * \param int  
	*/

  virtual void SetClientSize(int  width , int  height ) ;
	/**
	 * \brief This sets the size of the window client area in pixels. Using this function to size a window
tends to be more device-independent than  , since the application need not
worry about what dimensions the border or title bar have when trying to fit the window
around panel items, for example.









\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
} 
	 * \param const wxSize&  
	*/

  virtual void SetClientSize(const wxSize&  size ) ;
	/**
	 * \brief This normally does not need to be called by user code.  It is called
when a window is added to a sizer, and is used so the window can
remove itself from the sizer when it is destroyed. 
	 * \param wxSizer*   
	*/

  void SetContainingSizer(wxSizer*  sizer ) ;
	/**
	 * \brief  
	 * \param const wxCursor&  
	*/

  virtual bool SetCursor(const wxCursor& cursor );
	/**
	 * \brief Sets the window to have the given layout constraints. The window
will then own the object, and will take care of its deletion.
If an existing layout constraints object is already owned by the
window, it will be deleted. 
	 * \param wxLayoutConstraints*   
	*/

  void SetConstraints(wxLayoutConstraints*  constraints ) ;
	/**
	 * \brief Associates a drop target with this window.

If the window already has a drop target, it is deleted. 
	 * \param wxDropTarget*  
	*/

  void SetDropTarget(wxDropTarget*  target ) ;
	/**
	 * \brief Sets the event handler for this window. 
	 * \param wxEvtHandler*   
	*/

  void SetEventHandler(wxEvtHandler*  handler ) ;
	/**
	 * \brief Sets the extra style bits for the window. The currently defined extra style
bits are:

\twocolwidtha{5cm} 
	 * \param long   
	*/

  void SetExtraStyle(long  exStyle ) ;
	/**
	 * \brief This sets the window to receive keyboard input. 
	*/

  virtual void SetFocus() ;
	/**
	 * \brief This function is called by wxWindows keyboard navigation code when the user
gives the focus to this window from keyboard (e.g. using   key).
By default this method simply calls   but
can be overridden to do something in addition to this in the derived classes. 
	*/

  virtual void SetFocusFromKbd() ;
	/**
	 * \brief Sets the font for this window. 
	 * \param const wxFont&   
	*/

  void SetFont(const wxFont&  font ) ;
	/**
	 * \brief Sets the foreground colour of the window. 
	 * \param const wxColour&   
	*/

  virtual bool SetForegroundColour(const wxColour&  colour );
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  virtual void SetHelpText(const wxString&  helpText ) ;
	/**
	 * \brief Sets the identifier of the window. 
	 * \param int  
	*/

  void SetId(int  id ) ;
	/**
	 * \brief Sets the window's name. 
	 * \param const wxString&   
	*/

  virtual void SetName(const wxString&  name ) ;
	/**
	 * \brief Obsolete - use   instead. 
	 * \param wxPalette*   
	*/

#if 0 // deprecated
  virtual void SetPalette(const wxPalette*  palette );
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param bool   
	*/
#endif

  virtual void SetScrollbar(int  orientation , int  position , int  thumbSize , int  range , bool  refresh = true) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param bool   
	*/

#if __WXMICROWIN___
  virtual void SetScrollPage(int  orientation , int  pageSize , bool  refresh = true) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param bool   
	*/
#endif

  virtual void SetScrollPos(int  orientation , int  pos , bool  refresh = true) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param bool   
	*/

#if __WXMICROWIN___
  virtual void SetScrollRange(int  orientation , int  range , bool  refresh = true) ;
	/**
	 * \brief  
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	*/
#endif

  virtual void SetSize(int  x , int  y , int  width , int  height , int sizeFlags = wxSIZE_AUTO) ;
	/**
	 * \brief Sets the size and position of the window in pixels. 
	 * \param const wxRect&  
	*/

  virtual void SetSize(const wxRect&  rect ) ;
	/**
	 * \brief  
	 * \param int  
	 * \param int  
	*/

  virtual void SetSize(int  width , int  height ) ;
	/**
	 * \brief  
	 * \param const wxSize&  
	*/

  virtual void SetSize(const wxSize&  size ) ;
	/**
	 * \brief Allows specification of minimum and maximum window sizes, and window size increments.
If a pair of values is not set (or set to -1), the default values will be used. 
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	*/
    virtual void SetSizeHints( int minW, int minH,
                               int maxW = wxDefaultCoord, int maxH = wxDefaultCoord,
                               int incW = wxDefaultCoord, int incH = wxDefaultCoord );

    void SetSizeHints( const wxSize& minSize,
                       const wxSize& maxSize=wxDefaultSize,
                       const wxSize& incSize=wxDefaultSize);

	/**
	 * \brief Sets the window to have the given layout sizer. The window
will then own the object, and will take care of its deletion.
If an existing layout constraints object is already owned by the
window, it will be deleted if the deleteOld parameter is true.

Note that this function will also call 
  implicitly with  
parameter if the  \/ is non-NULL and   otherwise. 
	 * \param wxSizer*   
	 * \param bool   
	*/

  void SetSizer(wxSizer*  sizer , bool  deleteOld = true) ;

	/**
	 * \brief The same as  , except it also sets the size hints
for the window based on the sizer's minimum size. 
	 * \param wxSizer*   
	 * \param bool   
	*/

  void SetSizerAndFit(wxSizer*  sizer , bool  deleteOld = true) ;
	/**
	 * \brief Sets the window's title. Applicable only to frames and dialogs. 
	 * \param const wxString&   
	*/

  virtual void SetTitle(const wxString&  title ) ;
	/**
	 * \brief This function tells a window if it should use the system's &quot;theme&quot; code
to draw the windows' background instead if its own background drawing
code. This does not always have any effect since the underlying platform
obviously needs to support the notion of themes in user defined windows.
One such platform is GTK+ where windows can have (very colourful) backgrounds
defined by a user's selected theme.

Dialogs, notebook pages and the status bar have this flag set to true
by default so that the default look and feel is simulated best. 
	 * \param bool   
	*/

  virtual void SetThemeEnabled(bool  enable ) ;
	/**
	 * \brief Deletes the current validator (if any) and sets the window validator, having called wxValidator::Clone to
create a new validator of this type. 
	 * \param const wxValidator&  
	*/

  virtual void SetValidator(const wxValidator&  validator ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  void SetToolTip(const wxString&  tip ) ;
	/**
	 * \brief Attach a tooltip to the window.

See also:  , 
	 * \param wxToolTip*   
	*/

  void SetToolTip(wxToolTip*  tip ) ;
	/**
	 * \brief  
	 * \param int  
	 * \param int  
	*/

  void SetVirtualSize(int  width , int  height ) ;
	/**
	 * \brief Sets the virtual size of the window in pixels. 
	 * \param const wxSize&  
	*/

  void SetVirtualSize(const wxSize&  size ) ;
	/**
	 * \brief Allows specification of minimum and maximum virtual window sizes.
If a pair of values is not set (or set to -1), the default values
will be used. 
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	*/

  virtual void SetVirtualSizeHints(int  minW , int  minH , int maxW = wxDefaultCoord, int maxH = wxDefaultCoord) ;

	void SetVirtualSizeHints( const wxSize& minSize, const wxSize& maxSize=wxDefaultSize);
	/**
	 * \brief Identical to  . 
	 * \param long  
	*/

  void SetWindowStyle(long  style ) ;
	/**
	 * \brief Sets the style of the window. Please note that some styles cannot be changed
after the window creation and that   might
be called after changing the others for the change to take place immediately.

See   for more information about flags. 
	 * \param long  
	*/

  virtual void SetWindowStyleFlag(long  style ) ;
	/**
	 * \brief Shows or hides the window. You may need to call  
for a top level window if you want to bring it to top, although this is not
needed if Show() is called immediately after the frame creation. 
	 * \param bool  
	*/

  virtual bool Show(bool show = true) ;
	/**
	 * \brief Reenables window updating after a previous call to
 . 
	*/

  virtual void Thaw() ;
	/**
	 * \brief  
	*/

  virtual bool TransferDataFromWindow() ;
	/**
	 * \brief  
	*/

  virtual bool TransferDataToWindow() ;
	/**
	 * \brief Calling this method immediately repaints the invalidated area of the window
while this would usually only happen when the flow of control returns to the
event loop. Notice that this function doesn't refresh the window and does
nothing if the window hadn't been already repainted. Use 
  first if you want to immediately redraw the
window unconditionally. 
	*/

  virtual void Update() ;
	/**
	 * \brief Validates the current values of the child controls using their validators.

If the window has   extra style flag set,
the method will also call Validate() of all child windows. 
	*/

  virtual bool Validate() ;
	/**
	 * \brief Moves the pointer to the given position on the window.

  This function is not supported under Mac because Apple Human
Interface Guidelines forbid moving the mouse cursor programmatically. 
	 * \param int  
	 * \param int  
	*/

  void WarpPointer(int  x , int  y ) ;

  void SetWindowVariant( wxWindowVariant variant ) ;
  wxWindowVariant GetWindowVariant() const;
	void InvalidateBestSize();
	void CacheBestSize(const wxSize& size) const;
	wxSize GetBestFittingSize() const;
	void SetBestFittingSize(const wxSize& size=wxDefaultSize);
  virtual wxSize GetMaxSize() const;
  virtual wxSize GetMinSize() const;
  void SetMinSize(const wxSize& minSize);
  void SetMaxSize(const wxSize& maxSize);
	long GetWindowStyle() const;
	virtual bool Navigate(int flags = wxNavigationKeyEvent::IsForward);
	void MoveBeforeInTabOrder(wxWindow *win);
  void MoveAfterInTabOrder(wxWindow *win);
	virtual void ClearBackground();
  bool IsExposed( int x, int y ) const;
  bool IsExposed( int x, int y, int w, int h ) const;
  bool IsExposed( const wxPoint& pt ) const;
  bool IsExposed( const wxRect& rect ) const;
  // FIXME? GetDefaultAttributes causes problems (at least on MSWindows)
  //         with the layout and background of some controls (Such as
  //         TextCtrl).
  //	virtual wxVisualAttributes GetDefaultAttributes() const;
	static wxVisualAttributes GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL);
	void SetOwnBackgroundColour(const wxColour& colour);
	void SetOwnForegroundColour(const wxColour& colour);
	virtual bool SetBackgroundStyle(wxBackgroundStyle style);
	virtual wxBackgroundStyle GetBackgroundStyle() const;
  // FIXME? HasTransparentBackground causes problems (at least on MSWindows)
  //         with the background of some controls (Such as StaticText).
  //         It is overridden in a lot of child classes
  //    virtual bool HasTransparentBackground();
	void SetOwnFont(const wxFont& font);
	const wxCursor& GetCursor() const;
	virtual void UpdateWindowUI(long flags = wxUPDATE_UI_NONE);
	bool HasScrollbar(int orient) const;
  bool LineUp();
  bool LineDown();
  bool PageUp();
  bool PageDown();
	virtual void SetLabel(const wxString& label);
	wxAcceleratorTable *GetAcceleratorTable();
};


#endif
