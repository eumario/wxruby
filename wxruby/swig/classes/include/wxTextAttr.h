// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxTextAttr_h_)
#define _wxTextAttr_h_
class wxTextAttr
{
public:
    wxTextAttr();
    wxTextAttr(const wxColour& colText,
               const wxColour& colBack = wxNullColour,
               const wxFont& font = wxNullFont,
               wxTextAttrAlignment alignment = wxTEXT_ALIGNMENT_DEFAULT);

    // operations
    void Init();

    // operators
    void operator= (const wxTextAttr& attr);

    // setters
    void SetTextColour(const wxColour& colText);
    void SetBackgroundColour(const wxColour& colBack);
    void SetFont(const wxFont& font, long flags = wxTEXT_ATTR_FONT);
    void SetAlignment(wxTextAttrAlignment alignment);
    void SetTabs(const wxArrayInt& tabs);
    void SetLeftIndent(int indent, int subIndent = 0);
    void SetRightIndent(int indent);
    void SetFlags(long flags);

    // accessors
    bool HasTextColour() const;
    bool HasBackgroundColour() const;
    bool HasFont() const;
    bool HasAlignment() const;
    bool HasTabs() const;
    bool HasLeftIndent() const;
    bool HasRightIndent() const;
    bool HasFlag(long flag) const;

    const wxColour& GetTextColour() const;
    const wxColour& GetBackgroundColour() const;
    const wxFont& GetFont() const;
    wxTextAttrAlignment GetAlignment() const;
    const wxArrayInt& GetTabs() const;
    long GetLeftIndent() const;
    long GetLeftSubIndent() const;
    long GetRightIndent() const;
    long GetFlags() const;

    // returns false if we have any attributes set, true otherwise
    bool IsDefault() const;

    // return the attribute having the valid font and colours: it uses the
    // attributes set in attr and falls back first to attrDefault and then to
    // the text control font/colours for those attributes which are not set
    static wxTextAttr Combine(const wxTextAttr& attr,
                              const wxTextAttr& attrDef,
                              const wxTextCtrlBase *text);
};


#endif
