// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

class wxGridBagSizer : public wxFlexGridSizer
{
public:
    wxGridBagSizer(int vgap = 0, int hgap = 0 );

    // The Add methods return true if the item was successfully placed at the
    // given position, false if something was already there.
    wxSizerItem* Add( wxWindow *window,
                      const wxGBPosition& pos,
                      const wxGBSpan& span = wxDefaultSpan,
                      int flag = 0,
                      int border = 0,
                      wxObject* userData = NULL );
    wxSizerItem* Add( wxSizer *sizer,
                      const wxGBPosition& pos,
                      const wxGBSpan& span = wxDefaultSpan,
                      int flag = 0,
                      int border = 0,
                      wxObject* userData = NULL );
    wxSizerItem* Add( int width,
                      int height,
                      const wxGBPosition& pos,
                      const wxGBSpan& span = wxDefaultSpan,
                      int flag = 0,
                      int border = 0,
                      wxObject* userData = NULL );
    wxSizerItem* Add( wxGBSizerItem *item );


    // Get/Set the size used for cells in the grid with no item.
    wxSize GetEmptyCellSize() const          { return m_emptyCellSize; }
    void SetEmptyCellSize(const wxSize& sz)  { m_emptyCellSize = sz; }

    // Get the size of the specified cell, including hgap and vgap.  Only
    // valid after a Layout.
    wxSize GetCellSize(int row, int col) const;

    // Get the grid position of the specified item (non-recursive)
    wxGBPosition GetItemPosition(wxWindow *window);
    wxGBPosition GetItemPosition(wxSizer *sizer);
    wxGBPosition GetItemPosition(size_t index);

    // Set the grid position of the specified item.  Returns true on success.
    // If the move is not allowed (because an item is already there) then
    // false is returned.   (non-recursive)
    bool SetItemPosition(wxWindow *window, const wxGBPosition& pos);
    bool SetItemPosition(wxSizer *sizer, const wxGBPosition& pos);
    bool SetItemPosition(size_t index, const wxGBPosition& pos);

    // Get the row/col spanning of the specified item (non-recursive)
    wxGBSpan GetItemSpan(wxWindow *window);
    wxGBSpan GetItemSpan(wxSizer *sizer);
    wxGBSpan GetItemSpan(size_t index);

    // Set the row/col spanning of the specified item. Returns true on
    // success.  If the move is not allowed (because an item is already there)
    // then false is returned. (non-recursive)
    bool SetItemSpan(wxWindow *window, const wxGBSpan& span);
    bool SetItemSpan(wxSizer *sizer, const wxGBSpan& span);
    bool SetItemSpan(size_t index, const wxGBSpan& span);


    // Find the sizer item for the given window or subsizer, returns NULL if
    // not found. (non-recursive)
    wxGBSizerItem* FindItem(wxWindow* window);
    wxGBSizerItem* FindItem(wxSizer* sizer);


    // Return the sizer item for the given grid cell, or NULL if there is no
    // item at that position. (non-recursive)
    wxGBSizerItem* FindItemAtPosition(const wxGBPosition& pos);


    // Return the sizer item located at the point given in pt, or NULL if
    // there is no item at that point. The (x,y) coordinates in pt correspond
    // to the client coordinates of the window using the sizer for
    // layout. (non-recursive)
    wxGBSizerItem* FindItemAtPoint(const wxPoint& pt);


    // Return the sizer item that has a matching user data (it only compares
    // pointer values) or NULL if not found. (non-recursive)
    wxGBSizerItem* FindItemWithData(const wxObject* userData);


    // These are what make the sizer do size calculations and layout
    virtual void RecalcSizes();
    virtual wxSize CalcMin();

    // Look at all items and see if any intersect (or would overlap) the given
    // item.  Returns true if so, false if there would be no overlap.  If an
    // excludeItem is given then it will not be checked for intersection, for
    // example it may be the item we are checking the position of.
    bool CheckForIntersection(wxGBSizerItem* item, wxGBSizerItem* excludeItem = NULL);
    bool CheckForIntersection(const wxGBPosition& pos, const wxGBSpan& span, wxGBSizerItem* excludeItem = NULL);


    // The Add base class virtuals should not be used with this class, but
    // we'll try to make them automatically select a location for the item
    // anyway.
    virtual wxSizerItem* Add( wxWindow *window, int proportion = 0, int flag = 0, int border = 0, wxObject* userData = NULL );
    virtual wxSizerItem* Add( wxSizer *sizer, int proportion = 0, int flag = 0, int border = 0, wxObject* userData = NULL );
    virtual wxSizerItem* Add( int width, int height, int proportion = 0, int flag = 0, int border = 0, wxObject* userData = NULL );

    // The Insert and Prepend base class virtuals that are not appropriate for
    // this class and should not be used.  Their implementation in this class
    // simply fails.
    virtual wxSizerItem* Add( wxSizerItem *item );
    virtual wxSizerItem* Insert( size_t index, wxWindow *window, int proportion = 0, int flag = 0, int border = 0, wxObject* userData = NULL );
    virtual wxSizerItem* Insert( size_t index, wxSizer *sizer, int proportion = 0, int flag = 0, int border = 0, wxObject* userData = NULL );
    virtual wxSizerItem* Insert( size_t index, int width, int height, int proportion = 0, int flag = 0, int border = 0, wxObject* userData = NULL );
    virtual wxSizerItem* Insert( size_t index, wxSizerItem *item );
    virtual wxSizerItem* Prepend( wxWindow *window, int proportion = 0, int flag = 0, int border = 0, wxObject* userData = NULL );
    virtual wxSizerItem* Prepend( wxSizer *sizer, int proportion = 0, int flag = 0, int border = 0, wxObject* userData = NULL );
    virtual wxSizerItem* Prepend( int width,  int height,  int proportion = 0,  int flag = 0,  int border = 0,  wxObject* userData = NULL );
    virtual wxSizerItem* Prepend( wxSizerItem *item );


protected:
    wxGBPosition FindEmptyCell();
    wxSize m_emptyCellSize;

};
