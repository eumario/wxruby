// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxTreebook_h_)
#define _wxTreebook_h_

class wxTreebook : public wxBookCtrlBase
{
public:
  wxTreebook();
    // This ctor creates the tree book control
    wxTreebook(wxWindow *parent,
               wxWindowID id,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxBK_DEFAULT,
               const wxString& name = wxEmptyString);
    // Really creates the control
    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxBK_DEFAULT,
                const wxString& name = wxEmptyString);


    // Page insertion operations
    // -------------------------
    virtual bool InsertPage(size_t pos,
                            wxWindow *page,
                            const wxString& text,
                            bool bSelect = false,
                            int imageId = wxNOT_FOUND);

    // Inserts a new sub-page to the end of children of the page at given pos.
    virtual bool InsertSubPage(size_t pos,
                               wxWindow *page,
                               const wxString& text,
                               bool bSelect = false,
                               int imageId = wxNOT_FOUND);

    // Adds a new page at top level after all other pages.
    virtual bool AddPage(wxWindow *page,
                         const wxString& text,
                         bool bSelect = false,
                         int imageId = wxNOT_FOUND);

    // Adds a new child-page to the last top-level page inserted.
    // Useful when constructing 1 level tree structure.
    virtual bool AddSubPage(wxWindow *page,
                            const wxString& text,
                            bool bSelect = false,
                            int imageId = wxNOT_FOUND);



    // Deletes the page and ALL its children. Could trigger page selection
    // change in a case when selected page is removed. In that case its parent
    // is selected (or the next page if no parent).
    virtual bool DeletePage(size_t pos);

    // Gets the page node state -- node is expanded or collapsed
    virtual bool IsNodeExpanded(size_t pos) const;

    // Expands or collapses the page node. Returns the previous state.
    // May generate page changing events (if selected page
    // is under the collapsed branch, then parent is autoselected).
    virtual bool ExpandNode(size_t pos, bool expand = true);

    // shortcut for ExpandNode(pos, false)
    bool CollapseNode(size_t pos);

    // get the parent page or wxNOT_FOUND if this is a top level page
    int GetPageParent(size_t pos) const;

    // the tree control we use for showing the pages index tree
    wxTreeCtrl* GetTreeCtrl() const;


    // Standard operations inherited from wxBookCtrlBase
    // -------------------------------------------------

    virtual int GetSelection() const;
    int GetPageCount() const;
    virtual bool SetPageText(size_t n, const wxString& strText);
    virtual wxString GetPageText(size_t n) const;
    virtual int GetPageImage(size_t n) const;
    virtual bool SetPageImage(size_t n, int imageId);
    virtual wxSize CalcSizeFromPage(const wxSize& sizePage) const;
    virtual int SetSelection(size_t n);
    virtual int ChangeSelection(size_t n);
    virtual int HitTest(const wxPoint& pt, long *flags = NULL) const;
    virtual void SetImageList(wxImageList *imageList);
    virtual void AssignImageList(wxImageList *imageList);
    bool RemovePage(int page);
    virtual bool DeleteAllPages();

};

#endif
