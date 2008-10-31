// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextAttr_h_)
#define _wxRichTextAttr_h_

class wxRichTextAttr
{
public:
    // ctors
    wxRichTextAttr(const wxTextAttrEx& attr);
    wxRichTextAttr(const wxRichTextAttr& attr);
    wxRichTextAttr();
    wxRichTextAttr(const wxColour& colText,
                   const wxColour& colBack = wxNullColour,
                   wxTextAttrAlignment alignment = wxTEXT_ALIGNMENT_DEFAULT);

    // Initialise this object.
    void Init();

    // Copy
    void Copy(const wxRichTextAttr& attr);

    // Assignment from a wxRichTextAttr object.
    void operator= (const wxRichTextAttr& attr);

    // Assignment from a wxTextAttrEx object.
    void operator= (const wxTextAttrEx& attr);

    // Equality test
    bool operator== (const wxRichTextAttr& attr) const;

    // Making a wxTextAttrEx object.
    operator wxTextAttrEx () const ;

    // Create font from font attributes.
    wxFont CreateFont() const;

    // Get attributes from font.
    bool GetFontAttributes(const wxFont& font);

    // setters
    void SetTextColour(const wxColour& colText);
    void SetBackgroundColour(const wxColour& colBack);
    void SetAlignment(wxTextAttrAlignment alignment);
    void SetTabs(const wxArrayInt& tabs);
    void SetLeftIndent(int indent, int subIndent = 0);
    void SetRightIndent(int indent);

    void SetFontSize(int pointSize);
    void SetFontStyle(int fontStyle);
    void SetFontWeight(int fontWeight);
    void SetFontFaceName(const wxString& faceName);
    void SetFontUnderlined(bool underlined);

    void SetFlags(long flags);

    void SetCharacterStyleName(const wxString& name);
    void SetParagraphStyleName(const wxString& name);
    void SetListStyleName(const wxString& name);
    void SetParagraphSpacingAfter(int spacing);
    void SetParagraphSpacingBefore(int spacing);
    void SetLineSpacing(int spacing);
    void SetBulletStyle(int style);
    void SetBulletNumber(int n);
    void SetBulletText(const wxString& text);
    void SetBulletFont(const wxString& bulletFont);
    void SetBulletName(const wxString& name);
    void SetURL(const wxString& url);
    void SetPageBreak(bool pageBreak = true);
    void SetTextEffects(int effects);
    void SetTextEffectFlags(int effects);
    void SetOutlineLevel(int level);

    const wxColour& GetTextColour() const;
    const wxColour& GetBackgroundColour() const;
    wxTextAttrAlignment GetAlignment() const;
    const wxArrayInt& GetTabs() const;
    long GetLeftIndent() const;
    long GetLeftSubIndent() const;
    long GetRightIndent() const;
    long GetFlags() const;

    int GetFontSize() const;
    int GetFontStyle() const;
    int GetFontWeight() const;
    bool GetFontUnderlined() const;
    const wxString& GetFontFaceName() const;

    const wxString& GetCharacterStyleName() const;
    const wxString& GetParagraphStyleName() const;
    const wxString& GetListStyleName() const;
    int GetParagraphSpacingAfter() const;
    int GetParagraphSpacingBefore() const;
    int GetLineSpacing() const;
    int GetBulletStyle() const;
    int GetBulletNumber() const;
    const wxString& GetBulletText() const;
    const wxString& GetBulletFont() const;
    const wxString& GetBulletName() const;
    const wxString& GetURL() const;
    int GetTextEffects() const;
    int GetTextEffectFlags() const;
    int GetOutlineLevel() const;

    // accessors
    bool HasTextColour() const;
    bool HasBackgroundColour() const;
    bool HasAlignment() const;
    bool HasTabs() const;
    bool HasLeftIndent() const;
    bool HasRightIndent() const;
    bool HasFontWeight() const;
    bool HasFontSize() const;
    bool HasFontItalic() const;
    bool HasFontUnderlined() const;
    bool HasFontFaceName() const;
    bool HasFont() const;
    bool HasParagraphSpacingAfter() const;
    bool HasParagraphSpacingBefore() const;
    bool HasLineSpacing() const;
    bool HasCharacterStyleName() const;
    bool HasParagraphStyleName() const;
    bool HasListStyleName() const;
    bool HasBulletStyle() const;
    bool HasBulletNumber() const;
    bool HasBulletText() const;
    bool HasBulletName() const;
    bool HasURL() const;
    bool HasPageBreak() const;
    bool HasTextEffects() const;
    bool HasTextEffect(int effect) const;
    bool HasOutlineLevel() const;

    bool HasFlag(long flag) const;

    // Is this a character style?
    bool IsCharacterStyle() const;
    bool IsParagraphStyle() const;

    // returns false if we have any attributes set, true otherwise
    bool IsDefault() const;
    bool Apply(const wxRichTextAttr& style, 
               const wxRichTextAttr* compareWith = NULL);
    wxRichTextAttr Combine(const wxRichTextAttr& style, 
                           const wxRichTextAttr* compareWith = NULL) const;
};

#endif

