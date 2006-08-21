// Copyright 2006 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxTreeItemId_h_)
#define _wxwxTreeItemId_h_
class wxTreeItemId
{
    friend bool operator==(const wxTreeItemId&, const wxTreeItemId&);
public:
    // ctors
        // 0 is invalid value for HTREEITEM
    wxTreeItemId();

        // construct wxTreeItemId from the native item id
    wxTreeItemId(void *pItem);

        // default copy ctor/assignment operator are ok for us

    // accessors
        // is this a valid tree item?
    bool IsOk() const;
        // return true if this item is not valid
    bool operator!() const;

    // operations
        // invalidate the item
    void Unset();

#if WXWIN_COMPATIBILITY_2_4
    // deprecated: only for compatibility, don't work on 64 bit archs
    wxTreeItemId(long item);
    operator long() const;
#else // !WXWIN_COMPATIBILITY_2_4
    operator bool() const;
#endif // WXWIN_COMPATIBILITY_2_4/!WXWIN_COMPATIBILITY_2_4

    wxTreeItemIdValue m_pItem;
};

/*
inline bool operator==(const wxTreeItemId& i1, const wxTreeItemId& i2)
{
    return i1.m_pItem == i2.m_pItem;
}

inline bool operator!=(const wxTreeItemId& i1, const wxTreeItemId& i2)
{
    return i1.m_pItem != i2.m_pItem;
}
*/
#endif
