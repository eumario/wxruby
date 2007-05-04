// wxTopLevelWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTopLevelWindow_h_)
#define _wxTopLevelWindow_h_
class wxTopLevelWindow : public wxWindow
{
public:
    // construction
    wxTopLevelWindow();
    virtual ~wxTopLevelWindow();

    // top level wnd state
    // --------------------
    // maximize = true => maximize, otherwise - restore
    virtual void Maximize(bool maximize = true);

    // undo Maximize() or Iconize()
    virtual void Restore();

    // iconize = true => iconize, otherwise - restore
    virtual void Iconize(bool iconize = true);

    // return true if the frame is maximized
    virtual bool IsMaximized() const;
	virtual bool IsAlwaysMaximized() const;
    // return true if the frame is iconized
    virtual bool IsIconized() const;

    // get the frame icon
    const wxIcon& GetIcon() const;

    // get the frame icons
    const wxIconBundle& GetIcons() const;
	
    // set the frame icon
    virtual void SetIcon(const wxIcon& icon);

    // set the frame icons
    virtual void SetIcons(const wxIconBundle& icons );

    // maximize the window to cover entire screen
    virtual bool ShowFullScreen(bool show, long style = wxFULLSCREEN_ALL);

    // return true if the frame is in fullscreen mode
    virtual bool IsFullScreen() const;

	// frame title
    virtual wxString GetTitle() const;
    virtual void SetTitle(const wxString&  title ) ;
	
	// switch on or off close button
	virtual bool EnableCloseButton(bool enable = true);

    // Set the shape of the window to the given region.
    virtual bool SetShape(const wxRegion& region);

    // Attracts the users attention to this window if the application is
    // inactive (should be called when a background event occurs)
    virtual void RequestUserAttention(int flags = wxUSER_ATTENTION_INFO);

	virtual bool ShouldPreventAppExit() const { return true };

    // Is this the active frame (highlighted in the taskbar)?
    virtual bool IsActive();

    // centre the window on screen: this is just a shortcut
    void CentreOnScreen(int dir = wxBOTH) { DoCentre(dir | wxCENTRE_ON_SCREEN); }
    void CenterOnScreen(int dir = wxBOTH) { CentreOnScreen(dir); }

    // used to reset default if pointing to removed child
    virtual void RemoveChild(wxWindowBase *child);

	wxWindow* GetDefaultItem() const;
    void SetDefaultItem(wxWindow *btn ) ;

	virtual bool CanSetTransparent();
	virtual bool SetTransparent(int alpha);

#if defined(__SMARTPHONE__)
    virtual void SetLeftMenu(int id = wxID_ANY, const wxString& label = wxEmptyString, wxMenu *subMenu = NULL) = 0;
    virtual void SetRightMenu(int id = wxID_ANY, const wxString& label = wxEmptyString, wxMenu *subMenu = NULL) = 0;
#endif // __SMARTPHONE__

    // implementation only from now on
    // -------------------------------

    // override some base class virtuals
    virtual bool Destroy();
    virtual bool IsTopLevel() const { return true; }
    virtual bool IsVisible() const { return IsShown(); }

    // event handlers
    void OnCloseWindow(wxCloseEvent& event);
    void OnSize(wxSizeEvent& event);

    // Get rect to be used to center top-level children
    virtual void GetRectForTopLevelChildren(int *x, int *y, int *w, int *h);

    // this should go away, but for now it's called from docview.cpp,
    // so should be there for all platforms
    void OnActivate(wxActivateEvent& event);

    // do the window-specific processing after processing the update event
    virtual void DoUpdateWindowUI(wxUpdateUIEvent& event) ;

    // a different API for SetSizeHints
	virtual void SetMaxSize(const wxSize& size);
	virtual void SetMinSize(const wxSize& size);

    // set size hints for "window manager"
    virtual void DoSetSizeHints( int minW, int minH,
                                 int maxW = wxDefaultCoord, int maxH = wxDefaultCoord,
                                 int incW = wxDefaultCoord, int incH = wxDefaultCoord );

	// only for Win CE
	//	virtual bool HandleSettingChange(WXWPARAM wParam, WXLPARAM lParam);

	// only for wx UNIVERSAL
	// bool IsUsingNativeDecorations() const;
	// void UseNativeDecorations(bool native = true);
	// void UseNativeDecorationsByDefault(bool native = true);
};


#endif
