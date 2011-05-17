
class wxGBSizerItem : public wxSizerItem
{
public:
    // spacer
    wxGBSizerItem( int width,
                   int height,
                   const wxGBPosition& pos,
                   const wxGBSpan& span,
                   int flag,
                   int border,
                   wxObject* userData);

    // window
    wxGBSizerItem( wxWindow *window,
                   const wxGBPosition& pos,
                   const wxGBSpan& span,
                   int flag,
                   int border,
                   wxObject* userData );

    // subsizer
    wxGBSizerItem( wxSizer *sizer,
                   const wxGBPosition& pos,
                   const wxGBSpan& span,
                   int flag,
                   int border,
                   wxObject* userData );

    // default ctor
    wxGBSizerItem();


    // Get the grid position of the item
    wxGBPosition GetPos() const { return m_pos; }
    void GetPos(int& row, int& col) const;

    // Get the row and column spanning of the item
    wxGBSpan GetSpan() const { return m_span; }
    void GetSpan(int& rowspan, int& colspan) const;

    // If the item is already a member of a sizer then first ensure that there
    // is no other item that would intersect with this one at the new
    // position, then set the new position.  Returns true if the change is
    // successful and after the next Layout the item will be moved.
    bool SetPos( const wxGBPosition& pos );

    // If the item is already a member of a sizer then first ensure that there
    // is no other item that would intersect with this one with its new
    // spanning size, then set the new spanning.  Returns true if the change
    // is successful and after the next Layout the item will be resized.
    bool SetSpan( const wxGBSpan& span );

    // Returns true if this item and the other item instersect
    bool Intersects(const wxGBSizerItem& other);

    // Returns true if the given pos/span would intersect with this item.
    bool Intersects(const wxGBPosition& pos, const wxGBSpan& span);

    // Get the row and column of the endpoint of this item
    void GetEndPos(int& row, int& col);


    wxGridBagSizer* GetGBSizer() const { return m_gbsizer; }
    void SetGBSizer(wxGridBagSizer* sizer) { m_gbsizer = sizer; }
};
