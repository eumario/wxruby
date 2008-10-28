// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextPrintout_h_)
#define _wxRichTextPrintout_h_

class wxRichTextPrintout : public wxPrintout
{
public:
    wxRichTextPrintout(const wxString& title = wxT("Printout"));
    virtual ~wxRichTextPrintout();

    /// The buffer to print
    void SetRichTextBuffer(wxRichTextBuffer* buffer);
    wxRichTextBuffer* GetRichTextBuffer() const;

    /// Set/get header/footer data
    void SetHeaderFooterData(const wxRichTextHeaderFooterData& data);
    const wxRichTextHeaderFooterData& GetHeaderFooterData() const;

    void SetMargins(int top = 254, int bottom = 254, 
                    int left = 254, int right = 254);

    void CalculateScaling(wxDC* dc, wxRect& textRect,
                          wxRect& headerRect, wxRect& footerRect);

    virtual bool OnPrintPage(int page);
    virtual bool HasPage(int page);
    virtual void GetPageInfo(int *minPage, int *maxPage, 
                             int *selPageFrom, int *selPageTo);
    virtual bool OnBeginDocument(int startPage, int endPage);
    virtual void OnPreparePrinting();
};

#endif
