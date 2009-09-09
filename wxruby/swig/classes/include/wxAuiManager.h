// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxAuiManager_h_)
#define _wxAuiManager_h_

class wxAuiManager : public wxEvtHandler
{
friend class wxAuiFloatingFrame;

public:

    wxAuiManager(wxWindow* managed_wnd = NULL,
                   unsigned int flags = wxAUI_MGR_DEFAULT);
    virtual ~wxAuiManager();
    void UnInit();

    void SetFlags(unsigned int flags);
    unsigned int GetFlags() const;

    void SetManagedWindow(wxWindow* managed_wnd);
    wxWindow* GetManagedWindow() const;

    static wxAuiManager* GetManager(wxWindow* window);

    void SetArtProvider(wxAuiDockArt* art_provider);
    wxAuiDockArt* GetArtProvider() const;

    wxAuiPaneInfo& GetPane(wxWindow* window);
    wxAuiPaneInfo& GetPane(const wxString& name);
    wxAuiPaneInfoArray& GetAllPanes();

    bool AddPane(wxWindow* window,
                 const wxAuiPaneInfo& pane_info);
                 
    bool AddPane(wxWindow* window,
                 const wxAuiPaneInfo& pane_info,
                 const wxPoint& drop_pos);

    bool AddPane(wxWindow* window,
                 int direction = wxLEFT,
                 const wxString& caption = wxEmptyString);

    bool InsertPane(wxWindow* window,
                 const wxAuiPaneInfo& insert_location,
                 int insert_level = wxAUI_INSERT_PANE);

    bool DetachPane(wxWindow* window);
    
    void Update();

    wxString SavePaneInfo(wxAuiPaneInfo& pane);
    void LoadPaneInfo(wxString& pane_part, wxAuiPaneInfo &pane);
    wxString SavePerspective();
    bool LoadPerspective(const wxString& perspective, bool update = true);

    void SetDockSizeConstraint(double width_pct, double height_pct);
    void GetDockSizeConstraint(double* width_pct, double* height_pct) const;
    
    void ClosePane(wxAuiPaneInfo& pane_info);
    void MaximizePane(wxAuiPaneInfo& pane_info);
    void RestorePane(wxAuiPaneInfo& pane_info);
    void RestoreMaximizedPane();

public:

    virtual wxAuiFloatingFrame* CreateFloatingFrame(wxWindow* parent, const wxAuiPaneInfo& p);

    void StartPaneDrag(
                 wxWindow* pane_window,
                 const wxPoint& offset);

    wxRect CalculateHintRect(
                 wxWindow* pane_window,
                 const wxPoint& pt,
                 const wxPoint& offset);
                      
    void DrawHintRect(
                 wxWindow* pane_window,
                 const wxPoint& pt,
                 const wxPoint& offset);
                      
    virtual void ShowHint(const wxRect& rect);
    virtual void HideHint();

protected:

    void UpdateHintWindowConfig();
    
    void DoFrameLayout();

    void LayoutAddPane(wxSizer* container,
                       wxAuiDockInfo& dock,
                       wxAuiPaneInfo& pane,
                       wxAuiDockUIPartArray& uiparts,
                       bool spacer_only);

    void LayoutAddDock(wxSizer* container,
                       wxAuiDockInfo& dock,
                       wxAuiDockUIPartArray& uiparts,
                       bool spacer_only);

    wxSizer* LayoutAll(wxAuiPaneInfoArray& panes,
                       wxAuiDockInfoArray& docks,
                       wxAuiDockUIPartArray& uiparts,
                       bool spacer_only = false);

    /* virtual bool ProcessDockResult(wxAuiPaneInfo& target,
	   const wxAuiPaneInfo& new_pos); */
	bool ProcessDockResult(wxAuiPaneInfo& target,
                                   const wxAuiPaneInfo& new_pos);

    bool DoDrop(wxAuiDockInfoArray& docks,
                wxAuiPaneInfoArray& panes,
                wxAuiPaneInfo& drop,
                const wxPoint& pt,
                const wxPoint& action_offset = wxPoint(0,0));

    wxAuiDockUIPart* HitTest(int x, int y);
    wxAuiDockUIPart* GetPanePart(wxWindow* pane);
    int GetDockPixelOffset(wxAuiPaneInfo& test);
    void OnFloatingPaneMoveStart(wxWindow* window);
    void OnFloatingPaneMoving(wxWindow* window, wxDirection dir );
    void OnFloatingPaneMoved(wxWindow* window, wxDirection dir);
    void OnFloatingPaneActivated(wxWindow* window);
    void OnFloatingPaneClosed(wxWindow* window, wxCloseEvent& evt);
    void OnFloatingPaneResized(wxWindow* window, const wxSize& size);
    void Render(wxDC* dc);
    void Repaint(wxDC* dc = NULL);
    void ProcessMgrEvent(wxAuiManagerEvent& event);
    void UpdateButtonOnScreen(wxAuiDockUIPart* button_ui_part,
                              const wxMouseEvent& event);
    void GetPanePositionsAndSizes(wxAuiDockInfo& dock,
                              wxArrayInt& positions,
                              wxArrayInt& sizes);


public:

    // public events (which can be invoked externally)
    void OnRender(wxAuiManagerEvent& evt);
    void OnPaneButton(wxAuiManagerEvent& evt);

protected:

    // protected events
    void OnPaint(wxPaintEvent& evt);
    void OnEraseBackground(wxEraseEvent& evt);
    void OnSize(wxSizeEvent& evt);
    void OnSetCursor(wxSetCursorEvent& evt);
    void OnLeftDown(wxMouseEvent& evt);
    void OnLeftUp(wxMouseEvent& evt);
    void OnMotion(wxMouseEvent& evt);
    void OnLeaveWindow(wxMouseEvent& evt);
    void OnChildFocus(wxChildFocusEvent& evt);
    void OnHintFadeTimer(wxTimerEvent& evt);
    void OnFindManager(wxAuiManagerEvent& evt);

protected:

    enum
    {
        actionNone = 0,
        actionResize,
        actionClickButton,
        actionClickCaption,
        actionDragToolbarPane,
        actionDragFloatingPane
    };

protected:

    wxWindow* m_frame;           // the window being managed
    wxAuiDockArt* m_art;            // dock art object which does all drawing
    unsigned int m_flags;        // manager flags wxAUI_MGR_*

    wxAuiPaneInfoArray m_panes;     // array of panes structures
    wxAuiDockInfoArray m_docks;     // array of docks structures
    wxAuiDockUIPartArray m_uiparts; // array of UI parts (captions, buttons, etc)

    int m_action;                // current mouse action
    wxPoint m_action_start;      // position where the action click started
    wxPoint m_action_offset;     // offset from upper left of the item clicked
    wxAuiDockUIPart* m_action_part; // ptr to the part the action happened to
    wxWindow* m_action_window;   // action frame or window (NULL if none)
    wxRect m_action_hintrect;    // hint rectangle for the action
    wxRect m_last_rect;
    wxAuiDockUIPart* m_hover_button;// button uipart being hovered over
    wxRect m_last_hint;          // last hint rectangle
    wxPoint m_last_mouse_move;   // last mouse move position (see OnMotion)
    bool m_skipping;
    bool m_has_maximized;

    double m_dock_constraint_x;  // 0.0 .. 1.0; max pct of window width a dock can consume
    double m_dock_constraint_y;  // 0.0 .. 1.0; max pct of window height a dock can consume

    wxFrame* m_hint_wnd;         // transparent hint window, if supported by platform
    wxTimer m_hint_fadetimer;    // transparent fade timer
    wxByte m_hint_fadeamt;       // transparent fade amount
    wxByte m_hint_fademax;       // maximum value of hint fade
    
    void* m_reserved;

};

#endif
