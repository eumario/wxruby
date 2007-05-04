// Copyright 2007 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxAuiNotebook_h_)
#define _wxAuiNotebook_h_


class wxAuiNotebook : public wxControl
{

public:

    wxAuiNotebook();

    wxAuiNotebook(wxWindow* parent,
                  wxWindowID id = wxID_ANY,
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxAUI_NB_DEFAULT_STYLE);

    virtual ~wxAuiNotebook();

    bool Create(wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0);
                
    void SetWindowStyleFlag(long style);
    void SetArtProvider(wxAuiTabArt* art);
    wxAuiTabArt* GetArtProvider() const;
    
    virtual void SetUniformBitmapSize(const wxSize& size);
    virtual void SetTabCtrlHeight(int height);
 
    bool AddPage(wxWindow* page,
                 const wxString& caption,
                 bool select = false,
                 const wxBitmap& bitmap = wxNullBitmap);

    bool InsertPage(size_t page_idx,
                    wxWindow* page,
                    const wxString& caption,
                    bool select = false,
                    const wxBitmap& bitmap = wxNullBitmap);

    bool DeletePage(size_t page);
    bool RemovePage(size_t page);
    
    size_t GetPageCount() const;
    wxWindow* GetPage(size_t page_idx) const;
    int GetPageIndex(wxWindow* page_wnd) const;

    bool SetPageText(size_t page, const wxString& text);
    wxString GetPageText(size_t page_idx) const;

    bool SetPageBitmap(size_t page, const wxBitmap& bitmap);
    wxBitmap GetPageBitmap(size_t page_idx) const;

    size_t SetSelection(size_t new_page);
    int GetSelection() const;

    virtual void Split(size_t page, int direction);

#if wxABI_VERSION >= 20801
    const wxAuiManager& GetAuiManager() const { return m_mgr; }
#endif

protected:

    // these can be overridden
	// NB - made non-virtual so that base class works
    void UpdateTabCtrlHeight();
    int CalculateTabCtrlHeight();
    wxSize CalculateNewSplitSize();
    
protected:

    void DoSizing();
    void InitNotebook(long style);
    wxAuiTabCtrl* GetTabCtrlFromPoint(const wxPoint& pt);
    wxWindow* GetTabFrameFromTabCtrl(wxWindow* tab_ctrl);
    wxAuiTabCtrl* GetActiveTabCtrl();
    bool FindTab(wxWindow* page, wxAuiTabCtrl** ctrl, int* idx);
    void RemoveEmptyTabFrames();
    void UpdateHintWindowSize();
    
protected:

    void OnChildFocus(wxChildFocusEvent& evt);
    void OnRender(wxAuiManagerEvent& evt);
    void OnSize(wxSizeEvent& evt);
    void OnTabClicked(wxCommandEvent& evt);
    void OnTabBeginDrag(wxCommandEvent& evt);
    void OnTabDragMotion(wxCommandEvent& evt);
    void OnTabEndDrag(wxCommandEvent& evt);
    void OnTabButton(wxCommandEvent& evt);
    
protected:

    wxAuiManager m_mgr;
    wxAuiTabContainer m_tabs;
    int m_curpage;
    int m_tab_id_counter;
    wxWindow* m_dummy_wnd;

    wxSize m_requested_bmp_size;
    int m_requested_tabctrl_height;
    wxFont m_selected_font;
    wxFont m_normal_font;
    int m_tab_ctrl_height;
        
    int m_last_drag_x;
    unsigned int m_flags;
};

#endif
