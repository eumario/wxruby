// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGridCellAttr_h_)
#define _wxGridCellAttr_h_
class wxGridCellAttr
{
public:

    enum wxAttrKind
    {
        Any,
        Default,
        Cell,
        Row,
        Col,
        Merged
    };

    wxGridCellAttr();
    wxGridCellAttr(const wxColour& colText,
                   const wxColour& colBack,
                   const wxFont& font,
                   int hAlign,
                   int vAlign);

    // creates a new copy of this object
    wxGridCellAttr *Clone() const;
    void MergeWith(wxGridCellAttr *mergefrom);

    // this class is ref counted: it is created with ref count of 1, so
    // calling DecRef() once will delete it. Calling IncRef() allows to lock
    // it until the matching DecRef() is called
    void IncRef();
    void DecRef();

    // setters
    void SetTextColour(const wxColour& colText);
    void SetBackgroundColour(const wxColour& colBack);
    void SetFont(const wxFont& font);
    void SetAlignment(int hAlign, int vAlign);
    void SetSize(int num_rows, int num_cols);
    void SetOverflow(bool allow = true);
    void SetReadOnly(bool isReadOnly = true);

    // takes ownership of the pointer
    void SetRenderer(wxGridCellRenderer *renderer);
    void SetEditor(wxGridCellEditor* editor);

    void SetKind(wxAttrKind kind);

    // accessors
    bool HasTextColour() const;
    bool HasBackgroundColour() const;
    bool HasFont() const;
    bool HasAlignment() const;
    bool HasRenderer() const;
    bool HasEditor() const;
    bool HasReadWriteMode() const;
    bool HasOverflowMode() const;
    bool HasSize() const;

    const wxColour& GetTextColour() const;
    const wxColour& GetBackgroundColour() const;
    const wxFont& GetFont() const;
    void GetAlignment(int *hAlign, int *vAlign) const;
    void GetSize(int *num_rows, int *num_cols) const;
    bool GetOverflow() const;
    wxGridCellRenderer *GetRenderer(wxGrid* grid, int row, int col) const;
    wxGridCellEditor *GetEditor(wxGrid* grid, int row, int col) const;

    bool IsReadOnly() const;

    wxAttrKind GetKind();

    void SetDefAttr(wxGridCellAttr* defAttr);

};


#endif
