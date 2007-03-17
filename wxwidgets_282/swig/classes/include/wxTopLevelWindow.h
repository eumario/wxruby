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
    virtual void Maximize(bool maximize = true) = 0;

    // undo Maximize() or Iconize()
    virtual void Restore() = 0;

    // iconize = true => iconize, otherwise - restore
    virtual void Iconize(bool iconize = true) = 0;

    // return true if the frame is maximized
    virtual bool IsMaximized() const = 0;

    // return true if the frame is iconized
    virtual bool IsIconized() const = 0;

    // get the frame icon
    const wxIcon& GetIcon() const;

    // get the frame icons
    const wxIconBundle& GetIcons() const;

    // set the frame icon
    virtual void SetIcon(const wxIcon& icon);

    // set the frame icons
    virtual void SetIcons(const wxIconBundle& icons );

    // maximize the window to cover entire screen
    virtual bool ShowFullScreen(bool show, long style = wxFULLSCREEN_ALL) = 0;

    // return true if the frame is in fullscreen mode
    virtual bool IsFullScreen() const = 0;

    /*
       for now we already have them in wxWindow, but this is wrong: these
       methods really only make sense for wxTopLevelWindow!

    virtual void SetTitle(const wxString& title) = 0;
    virtual wxString GetTitle() const = 0;
     */

    // Set the shape of the window to the given region.
    // Returns true if the platform supports this feature (and the
    // operation is successful.)
    virtual bool SetShape(const wxRegion& region);

    // Attracts the users attention to this window if the application is
    // inactive (should be called when a background event occurs)
    virtual void RequestUserAttention(int flags = wxUSER_ATTENTION_INFO);

    // Is this the active frame (highlighted in the taskbar)?
    virtual bool IsActive();

#if defined(__SMARTPHONE__)
    virtual void SetLeftMenu(int id = wxID_ANY, const wxString& label = wxEmptyString, wxMenu *subMenu = NULL) = 0;
    virtual void SetRightMenu(int id = wxID_ANY, const wxString& label = wxEmptyString, wxMenu *subMenu = NULL) = 0;
#endif // __SMARTPHONE__

    // implementation only from now on
    // -------------------------------

    // override some base class virtuals
    virtual bool Destroy();
    virtual bool IsTopLevel() const;
    virtual wxSize GetMaxSize() const;

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

};


#endif
