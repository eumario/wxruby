// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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

// New methods from 2.8.1 onwards
// #if wxABI_VERSION >= 20801
    const wxAuiManager& GetAuiManager() const { return m_mgr; }
// #endif

// New methods from 2.8.5 onwards
// #if wxABI_VERSION >= 20805
    // Sets the normal font
    void SetNormalFont(const wxFont& font);

    // Sets the selected tab font
    void SetSelectedFont(const wxFont& font);

    // Sets the measuring font
    void SetMeasuringFont(const wxFont& font);

    // Sets the tab font
    virtual bool SetFont(const wxFont& font);

    // Gets the tab control height
    int GetTabCtrlHeight() const;

    // Gets the height of the notebook for a given page height
    int GetHeightForPageHeight(int pageHeight);

    // Advances the selection, generation page selection events
    void AdvanceSelection(bool forward = true);

    // Shows the window menu
    bool ShowWindowMenu();
// #endif

};

#endif
