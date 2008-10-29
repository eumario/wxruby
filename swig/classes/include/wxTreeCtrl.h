// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxTreeCtrl_h_)
#define _wxTreeCtrl_h_

#if defined(__WXMSW__)
class wxTreeCtrl : public wxControl
#else
class wxTreeCtrl : public wxScrolledWindow
#endif
{
public:

    wxTreeCtrl();

    wxTreeCtrl(wxWindow *parent, wxWindowID id,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = 0,
               const wxValidator &validator = wxDefaultValidator,
							 const wxString& name = wxTreeCtrlNameStr);

    virtual ~wxTreeCtrl();

    bool Create(wxWindow *parent, wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTR_DEFAULT_STYLE,
                const wxValidator &validator = wxDefaultValidator,
                const wxString& name = wxTreeCtrlNameStr);

    // accessors
    // ---------

        // get the total number of items in the control
    size_t GetCount() const;

        // indent is the number of pixels the children are indented relative to
        // the parents position. SetIndent() also redraws the control
        // immediately.
    unsigned int GetIndent() const;
    void SetIndent(unsigned int indent);

        // spacing is the number of pixels between the start and the Text
    unsigned int GetSpacing() const;
    void SetSpacing(unsigned int spacing);

        // image list: these functions allow to associate an image list with
        // the control and retrieve it. Note that when assigned with
        // SetImageList, the control does _not_ delete
        // the associated image list when it's deleted in order to allow image
        // lists to be shared between different controls. If you use
        // AssignImageList, the control _does_ delete the image list.
        //
        // The normal image list is for the icons which correspond to the
        // normal tree item state (whether it is selected or not).
        // Additionally, the application might choose to show a state icon
        // which corresponds to an app-defined item state (for example,
        // checked/unchecked) which are taken from the state image list.
    virtual wxImageList *GetImageList() const;
    virtual wxImageList *GetStateImageList() const;
    

    virtual void SetImageList(wxImageList *imageList);
    virtual void SetStateImageList(wxImageList *imageList);
    
    virtual void AssignImageList(wxImageList *imageList);
    virtual void AssignStateImageList(wxImageList *imageList);


    
    

    // Functions to work with tree ctrl items.

    // accessors
    // ---------

        // retrieve item's label
    wxString GetItemText(const wxTreeItemId& item) const;
        // get one of the images associated with the item (normal by default)
    virtual int GetItemImage(const wxTreeItemId& item,
                     wxTreeItemIcon which = wxTreeItemIcon_Normal) const;
        // get the data associated with the item
    wxTreeItemData *GetItemData(const wxTreeItemId& item) const;

        // get the item's text colour
    wxColour GetItemTextColour(const wxTreeItemId& item) const;

        // get the item's background colour
    wxColour GetItemBackgroundColour(const wxTreeItemId& item) const;

        // get the item's font
    wxFont GetItemFont(const wxTreeItemId& item) const;

    // modifiers
    // ---------

        // set item's label
    void SetItemText(const wxTreeItemId& item, const wxString& text);
        // get one of the images associated with the item (normal by default)
    virtual void SetItemImage(const wxTreeItemId& item, int image,
                      wxTreeItemIcon which = wxTreeItemIcon_Normal);
        // associate some data with the item
    void SetItemData(const wxTreeItemId& item, wxTreeItemData *data);

        // force appearance of [+] button near the item. This is useful to
        // allow the user to expand the items which don't have any children now
        // - but instead add them only when needed, thus minimizing memory
        // usage and loading time.
    void SetItemHasChildren(const wxTreeItemId& item, bool has = true);

        // the item will be shown in bold
    void SetItemBold(const wxTreeItemId& item, bool bold = true);

        // the item will be shown with a drop highlight
    void SetItemDropHighlight(const wxTreeItemId& item, bool highlight = true);

        // set the item's text colour
    void SetItemTextColour(const wxTreeItemId& item, const wxColour& col);

        // set the item's background colour
    void SetItemBackgroundColour(const wxTreeItemId& item, const wxColour& col);

        // set the item's font (should be of the same height for all items)
    void SetItemFont(const wxTreeItemId& item, const wxFont& font);

        // set the window font
    virtual bool SetFont( const wxFont &font );

       // set the styles.  No need to specify a GetWindowStyle here since
       // the base wxWindow member function will do it for us
    void SetWindowStyle(const long styles);

    // item status inquiries
    // ---------------------

        // is the item visible (it might be outside the view or not expanded)?
    bool IsVisible(const wxTreeItemId& item) const;
        // does the item has any children?
    
    bool ItemHasChildren(const wxTreeItemId& item) const;
        // is the item expanded (only makes sense if HasChildren())?
    bool IsExpanded(const wxTreeItemId& item) const;
        // is this item currently selected (the same as has focus)?
    bool IsSelected(const wxTreeItemId& item) const;
        // is item text in bold font?
    bool IsBold(const wxTreeItemId& item) const;
        // does the layout include space for a button?
	bool IsEmpty() const;

    // number of children
    // ------------------

        // if 'recursively' is false, only immediate children count, otherwise
        // the returned number is the number of all items in this branch
    size_t GetChildrenCount(const wxTreeItemId& item,
                            bool recursively = true) const;

    // navigation
    // ----------

    // wxTreeItemId.IsOk() will return false if there is no such item

        // get the root tree item
    wxTreeItemId GetRootItem() const;

        // get the item currently selected (may return NULL if no selection)
    wxTreeItemId GetSelection() const;

        // get the items currently selected, return the number of such item
    size_t GetSelections(wxArrayTreeItemIds&) const;

        // get the parent of this item (may return NULL if root)
    wxTreeItemId GetItemParent(const wxTreeItemId& item) const;


        // for this enumeration function you must pass in a "cookie" parameter
        // which is opaque for the application but is necessary for the library
        // to make these functions reentrant (i.e. allow more than one
        // enumeration on one and the same object simultaneously). Of course,
        // the "cookie" passed to GetFirstChild() and GetNextChild() should be
        // the same!

		// NOTE! - GetFirstChild and GetNextChild are implemented in the .i file, they are special
        // get the first child of this item
    //wxTreeItemId GetFirstChild(const wxTreeItemId& item,
    //                           wxTreeItemIdValue& cookie) const;
        // get the next child
    //wxTreeItemId GetNextChild(const wxTreeItemId& item,
    //                          wxTreeItemIdValue& cookie) const;
        // get the last child of this item - this method doesn't use cookies
    wxTreeItemId GetLastChild(const wxTreeItemId& item) const;

        // get the next sibling of this item
    wxTreeItemId GetNextSibling(const wxTreeItemId& item) const;
        // get the previous sibling
    wxTreeItemId GetPrevSibling(const wxTreeItemId& item) const;

        // get first visible item
    wxTreeItemId GetFirstVisibleItem() const;
        // get the next visible item: item must be visible itself!
        // see IsVisible() and wxTreeCtrl::GetFirstVisibleItem()
    wxTreeItemId GetNextVisible(const wxTreeItemId& item) const;
        // get the previous visible item: item must be visible itself!
    wxTreeItemId GetPrevVisible(const wxTreeItemId& item) const;


    // operations
    // ----------

        // add the root node to the tree
    virtual wxTreeItemId AddRoot(const wxString& text,
                         int image = -1, int selectedImage = -1,
                         wxTreeItemData *data = NULL);

        // insert a new item in as the first child of the parent
    virtual wxTreeItemId PrependItem(const wxTreeItemId& parent,
                             const wxString& text,
                             int image = -1, int selectedImage = -1,
                             wxTreeItemData *data = NULL);

        // insert a new item after a given one
    virtual wxTreeItemId InsertItem(const wxTreeItemId& parent,
                            const wxTreeItemId& idPrevious,
                            const wxString& text,
                            int image = -1, int selectedImage = -1,
                            wxTreeItemData *data = NULL);

		// NOTE! - This version of InsertItem is implemented in the .i file, as insert_item_before
        // insert a new item before the one with the given index
    //virtual wxTreeItemId InsertItem(const wxTreeItemId& parent,
    //                        size_t index,
    //                        const wxString& text,
    //                        int image = -1, int selectedImage = -1,
    //                        wxTreeItemData *data = NULL);

        // insert a new item in as the last child of the parent
    virtual wxTreeItemId AppendItem(const wxTreeItemId& parent,
                            const wxString& text,
                            int image = -1, int selectedImage = -1,
                            wxTreeItemData *data = NULL);

        // delete this item and associated data if any
    void Delete(const wxTreeItemId& item);
        // delete all children (but don't delete the item itself)
        // NB: this won't send wxEVT_COMMAND_TREE_ITEM_DELETED events
    void DeleteChildren(const wxTreeItemId& item);
        // delete all items from the tree
        // NB: this won't send wxEVT_COMMAND_TREE_ITEM_DELETED events
    void DeleteAllItems();

    void Expand(const wxTreeItemId& item);
	void ExpandAll();
	void ExpandAllChildren(const wxTreeItemId& item);


    void Collapse(const wxTreeItemId& item);
	void CollapseAll();
	void CollapseAllChildren(const wxTreeItemId& item);

        // collapse the item and remove all children
    void CollapseAndReset(const wxTreeItemId& item);
        // toggles the current state
    void Toggle(const wxTreeItemId& item);

        // remove the selection from currently selected item (if any)
    void Unselect();
        // or from the given one (multiselect mode only)
    void UnselectItem(const wxTreeItemId& item);
        // or from all
    void UnselectAll();
        // select this item
    void SelectItem(const wxTreeItemId& item, bool select = true);
        // toggle the item selection
    void ToggleItemSelection(const wxTreeItemId& item);

        // make sure this item is visible (expanding the parent item and/or
        // scrolling to this item if necessary)
    void EnsureVisible(const wxTreeItemId& item);
        // scroll to this item (but don't expand its parent)
    void ScrollTo(const wxTreeItemId& item);


        // The first function is more portable (because easier to implement
        // on other platforms), but the second one returns some extra info.
    wxTreeItemId HitTest(const wxPoint& point);
    wxTreeItemId HitTest(const wxPoint& point, int& flags);

        // get the bounding rectangle of the item (or of its label only)
    bool GetBoundingRect(const wxTreeItemId& item,
                         wxRect& rect,
                         bool textOnly = false) const;

        // Start editing the item label: this (temporarily) replaces the item
        // with a one line edit control. The item will be selected if it hadn't
        // been before.
    void EditLabel( const wxTreeItemId& item );

    // This method's signature is different on OS X / Linux - accepts
    // two arguments, the first being the tree item id whose editing
    // should be cancelled. Dealt with in SWIG file
    void EndEditLabel(const wxTreeItemId& item, bool cancel);

        // returns a pointer to the text edit control if the item is being
        // edited, NULL otherwise (it's assumed that no more than one item may
        // be edited simultaneously)
    wxTextCtrl* GetEditControl() const;

	bool GetQuickBestSize() const;
	void SetQuickBestSize(bool quickBestSize);

    // sorting
        // this function is called to compare 2 items and should return -1, 0
        // or +1 if the first item is less than, equal to or greater than the
        // second one. The base class version performs alphabetic comparaison
        // of item labels (GetText)
    virtual int OnCompareItems(const wxTreeItemId& item1,
                               const wxTreeItemId& item2);
        // sort the children of this item using OnCompareItems
        //
        // NB: this function is not reentrant and not MT-safe (FIXME)!
    void SortChildren(const wxTreeItemId& item);

#if WXWIN_COMPATIBILITY_2_4
    // deprecated functions: use Set/GetItemImage directly
    int GetItemSelectedImage(const wxTreeItemId& item) const;
    void SetItemSelectedImage(const wxTreeItemId& item, int image);

    // use the versions taking wxTreeItemIdValue cookies (note that
    // GetNextChild() is not inside wxDEPRECATED on purpose, as otherwise we
    // get twice as many warnings without any added benefit: it is always used
    // with GetFirstChild() anyhow)
    wxTreeItemId GetFirstChild(const wxTreeItemId& item,
                                             long& cookie) const;
    wxTreeItemId GetNextChild(const wxTreeItemId& item,
                              long& cookie) const;
#endif // WXWIN_COMPATIBILITY_2_4

    virtual bool ShouldInheritColours() const;

    // implementation only from now on

    // overridden base class virtuals
    virtual bool SetBackgroundColour(const wxColour& colour);
    virtual bool SetForegroundColour(const wxColour& colour);

    virtual void Freeze();
    virtual void Thaw();

    // callbacks
    void OnPaint( wxPaintEvent &event );

    void OnInternalIdle( );



    virtual wxVisualAttributes GetDefaultAttributes() const;

    static wxVisualAttributes
    GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL);

#if !defined(__WXMSW__)
	//Windows does not support these
	
	virtual void SetButtonsImageList(wxImageList *imageList);
    virtual void AssignButtonsImageList(wxImageList *imageList);	
	virtual wxImageList *GetButtonsImageList() const;
	virtual bool GetDropEffectAboveItem() const;
	virtual void SetDropEffectAboveItem( bool above = false );
        // Only for internal use right now, but should probably be public
    wxTreeItemId GetNext(const wxTreeItemId& item) const;
	bool HasChildren(const wxTreeItemId& item) const;

    void AdjustMyScrollbars();
    void Edit( const wxTreeItemId& item );
    void OnSetFocus( wxFocusEvent &event );
    void OnKillFocus( wxFocusEvent &event );
    void OnChar( wxKeyEvent &event );
    void OnMouse( wxMouseEvent &event );
    void OnGetToolTip( wxTreeEvent &event );
    // virtual wxSize DoGetBestSize() const;
#endif
};

#endif
