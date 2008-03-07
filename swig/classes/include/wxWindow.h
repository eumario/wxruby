// wxWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWindow_h_)
#define _wxWindow_h_

class wxWindow : public wxEvtHandler
{
public:
   wxWindow() ;
   wxWindow(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = 0, const wxString&  name = wxPanelNameStr) ;
  virtual  ~wxWindow() ;
  // FIXME? AcceptFocus causes problems because it is public here and protected
  //         in some derived classes.  Do not uncomment unless you also
  //         make sure to fix it in derived classes else things like
  //         StaticText will take the focus when tabbing
  // virtual bool AcceptsFocus() const;

  virtual void AddChild(wxWindow* child);
  void AssociateHandle(WXWidget handle);
  void CaptureMouse();

  void Center(int  direction );
  void Centre(int direction = wxBOTH);

  void CenterOnParent(int  direction );
  void CentreOnParent(int direction = wxBOTH) ;

  void ClientToScreen(int*  x_INOUT , int*  y_INOUT ) const;
  wxPoint ClientToScreen(const wxPoint&  pt ) const;
  bool Close(bool force = false) ;
  wxPoint ConvertDialogToPixels(const wxPoint&  pt ) ;
  wxSize ConvertDialogToPixels(const wxSize&  sz ) ;
  wxPoint ConvertPixelsToDialog(const wxPoint&  pt ) ;
  wxSize ConvertPixelsToDialog(const wxSize&  sz ) ;
  virtual bool Destroy() ;
  void DestroyChildren() ;
  void Disable() ;
  void DissociateHandle();
  virtual bool Enable(bool enable = true) ;
  static wxWindow* FindFocus() ;
  wxWindow* FindWindow(long  id ) const;
  wxWindow* FindWindow(const wxString&  name ) const;
  static wxWindow* FindWindowById(long  id , wxWindow* parent = NULL) ;
  static wxWindow* FindWindowByName(const wxString&  name , wxWindow* parent = NULL) ;
  static wxWindow* FindWindowByLabel(const wxString&  label , wxWindow* parent = NULL) ;
  virtual void Fit() ;
  virtual void FitInside() ;
  virtual void Freeze() ;
  //wxAccessible* GetAccessible();
  wxSize GetEffectiveMinSize() const;
  wxColour GetBackgroundColour() const;
  wxSize GetBestSize() const;
  wxCaret * GetCaret() const;
  static wxWindow * GetCapture() ;
  virtual int GetCharHeight() const;
  virtual int GetCharWidth() const;
  wxWindowList& GetChildren() ;
  void GetClientSize(int*  width , int*  height ) const;
  wxSize GetClientSize() const;
  wxRect GetClientRect() const;
  wxLayoutConstraints* GetConstraints() const;
  const wxSizer * GetContainingSizer() const;
  wxDropTarget* GetDropTarget() const;
  wxEvtHandler* GetEventHandler() const;
  long GetExtraStyle() const;
  wxFont GetFont() const;
  wxColour GetForegroundColour() ;
  wxWindow* GetGrandParent() const;
  void* GetHandle() const;
  virtual wxString GetHelpTextAtPoint(const wxPoint point, 
									  wxHelpEvent::Origin origin) const;
  wxString GetHelpText() const;
  int GetId() const;
  virtual wxString  GetLabel() const;
  virtual wxString  GetName() const;
  wxWindow* GetParent() const;
  void GetPosition(int*  x , int*  y ) const;
  wxPoint GetPosition() const;
  wxRect GetRect() const;
  virtual int GetScrollThumb(int  orientation ) ;
  virtual int GetScrollPos(int  orientation ) ;
  virtual int GetScrollRange(int  orientation ) ;
  virtual void GetScreenPosition(int* x, int* y) const;
  wxPoint GetScreenPosition() const;
  virtual wxRect GetScreenRect() const;
  void GetSize(int*  width , int*  height ) const;
  wxSize GetSize() const;
  wxSizer * GetSizer() const;
  virtual void GetTextExtent(const wxString&  string , int * x , int * y , int * descent = NULL, int * externalLeading = NULL, wxFont * font = NULL) const;
  wxToolTip* GetToolTip() const;
  wxRegion GetUpdateRegion() const;
  wxValidator* GetValidator();
  void GetVirtualSize(int*  width , int*  height ) const;
  wxSize GetVirtualSize() const;
  wxSize GetWindowBorderSize() const;
  long GetWindowStyleFlag() const;
  virtual bool HasCapture() const;
  bool HasFlag(int flag) const;
  virtual bool HasMultiplePages() const;
  bool Hide() ;
  void InitDialog() ;
  virtual bool IsDoubleBuffered() const;
  virtual bool IsEnabled() const;
  virtual bool IsFrozen() const;
  virtual bool IsRetained() const;
  virtual bool IsShown() const;
  virtual bool IsShownOnScreen() const;
  bool IsTopLevel() const;
  void Layout() ;
  void Lower() ;
  virtual void MakeModal(bool  flag ) ;
  void Move(int  x , int  y ) ;
  void Move(const wxPoint&  pt ) ;
  wxEvtHandler* PopEventHandler(bool  deleteHandler = false);
  bool PopupMenu(wxMenu*  menu , const wxPoint&  pos = wxDefaultPosition) ;
  bool PopupMenu(wxMenu*  menu , int  x , int  y ) ;
  void PushEventHandler(wxEvtHandler*  handler ) ;
  void Raise() ;
  virtual void Refresh(bool eraseBackground = true, const wxRect*  rect = NULL) ;
  virtual void RefreshRect(const wxRect&  rect, bool eraseBackground = true) ;
//#ifdef __WXMSW__
#ifdef wxUSE_HOTKEY 
  bool RegisterHotKey(int hotkeyId, int modifiers, int virtualKeyCode);
	virtual bool UnregisterHotKey(int hotkeyId);
#endif

  virtual void ReleaseMouse() ;
  virtual void RemoveChild(wxWindow*  child ) ;
  bool RemoveEventHandler(wxEvtHandler * handler ) ;
  virtual bool Reparent(wxWindow*  newParent ) ;
  void ScreenToClient(int*  x_INOUT , int*  y_INOUT ) const;
  wxPoint ScreenToClient(const wxPoint&  pt ) const;
  virtual bool ScrollLines(int  lines ) ;
  virtual bool ScrollPages(int  pages ) ;
  virtual void ScrollWindow(int  dx , int  dy , const wxRect* rect = NULL) ;
  virtual void SetAcceleratorTable(const wxAcceleratorTable&  accel ) ;
  //void SetAccessible(wxAccessible*  accessible );
  void SetAutoLayout(bool  autoLayout ) ;
  virtual bool SetBackgroundColour(const wxColour&  colour );
  void SetCaret(wxCaret * caret );
  virtual void SetClientSize(int  width , int  height ) ;
  virtual void SetClientSize(const wxSize&  size ) ;
  void SetContainingSizer(wxSizer*  sizer ) ;
  virtual bool SetCursor(const wxCursor& cursor );
  void SetConstraints(wxLayoutConstraints*  constraints ) ;
  void SetDropTarget(wxDropTarget*  target ) ;
  void SetEventHandler(wxEvtHandler*  handler ) ;
  void SetExtraStyle(long  exStyle ) ;
  virtual void SetFocus() ;
  virtual void SetFocusFromKbd() ;
  void SetFont(const wxFont&  font ) ;
  virtual bool SetForegroundColour(const wxColour&  colour );

  virtual void SetHelpText(const wxString&  helpText ) ;
  void SetId(int  id );
  void SetInitialSize(const wxSize& size = wxDefaultSize);
  virtual void SetName(const wxString&  name ) ;
#if 0 // deprecated
  virtual void SetPalette(const wxPalette*  palette );
#endif
  virtual void SetScrollbar(int  orientation , int  position , int  thumbSize , int  range , bool  refresh = true) ;

#if __WXMICROWIN___
  virtual void SetScrollPage(int  orientation , int  pageSize , bool  refresh = true) ;
#endif

  virtual void SetScrollPos(int  orientation , int  pos , bool  refresh = true) ;

#if __WXMICROWIN___
  virtual void SetScrollRange(int  orientation , int  range , bool  refresh = true) ;
#endif

  virtual void SetSize(int  x , int  y , int  width , int  height , int sizeFlags = wxSIZE_AUTO) ;
  virtual void SetSize(const wxRect&  rect ) ;
  virtual void SetSize(int  width , int  height ) ;
  virtual void SetSize(const wxSize&  size ) ;
  virtual void SetSizeHints( int minW, int minH,
							 int maxW = wxDefaultCoord, int maxH = wxDefaultCoord,
							 int incW = wxDefaultCoord, int incH = wxDefaultCoord );

    void SetSizeHints( const wxSize& minSize,
                       const wxSize& maxSize=wxDefaultSize,
                       const wxSize& incSize=wxDefaultSize);
  void SetSizer(wxSizer*  sizer , bool  deleteOld = true) ;
  void SetSizerAndFit(wxSizer*  sizer , bool  deleteOld = true) ;
  virtual void SetThemeEnabled(bool  enable ) ;
  virtual void SetValidator(const wxValidator&  validator ) ;
  void SetToolTip(const wxString&  tip ) ;
  void SetToolTip(wxToolTip*  tip ) ;
  void SetVirtualSize(int  width , int  height ) ;
  void SetVirtualSize(const wxSize&  size ) ;
  virtual void SetVirtualSizeHints(int  minW , int  minH , int maxW = wxDefaultCoord, int maxH = wxDefaultCoord) ;

	void SetVirtualSizeHints( const wxSize& minSize, const wxSize& maxSize=wxDefaultSize);
  void SetWindowStyle(long  style ) ;
  virtual void SetWindowStyleFlag(long  style ) ;
  virtual bool Show(bool show = true) ;
  virtual void Thaw() ;
  virtual bool TransferDataFromWindow() ;
  virtual bool TransferDataToWindow() ;
  virtual void Update() ;
  virtual bool Validate() ;
  void WarpPointer(int  x , int  y ) ;
  void SetWindowVariant( wxWindowVariant variant ) ;
  wxWindowVariant GetWindowVariant() const;
	void InvalidateBestSize();
	void CacheBestSize(const wxSize& size) const;
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
	bool ToggleWindowStyle(int flag);
};


#endif
