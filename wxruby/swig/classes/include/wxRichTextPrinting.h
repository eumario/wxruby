// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRichTextPrinting_h_)
#define _wxRichTextPrinting_h_

class wxRichTextPrinting : public wxObject
{
public:
    wxRichTextPrinting(const wxString& name = wxT("Printing"), 
                       wxWindow *parentWindow = NULL);
    virtual ~wxRichTextPrinting();

    /// Preview the file or buffer
    bool PreviewFile(const wxString& richTextFile);
    bool PreviewBuffer(const wxRichTextBuffer& buffer);

    /// Print the file or buffer
    bool PrintFile(const wxString& richTextFile);
    bool PrintBuffer(const wxRichTextBuffer& buffer);

    /// Shows page setup dialog
    void PageSetup();

    /// Set/get header/footer data
    void SetHeaderFooterData(const wxRichTextHeaderFooterData& data);
    const wxRichTextHeaderFooterData& GetHeaderFooterData() const;

    void SetHeaderText(const wxString& text, 
                       wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL, 
                       wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE);
    wxString GetHeaderText(wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN, 
                           wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE) const;

    void SetFooterText(const wxString& text, 
                       wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_ALL, 
                       wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE);
    wxString GetFooterText(wxRichTextOddEvenPage page = wxRICHTEXT_PAGE_EVEN, 
                           wxRichTextPageLocation location = wxRICHTEXT_PAGE_CENTRE) const;

    void SetShowOnFirstPage(bool show);

    void SetHeaderFooterFont(const wxFont& font);
    void SetHeaderFooterTextColour(const wxColour& font);

    wxPrintData *GetPrintData();
    wxPageSetupDialogData *GetPageSetupData();

    void SetPrintData(const wxPrintData& printData);
    void SetPageSetupData(const wxPageSetupData& pageSetupData);

    void SetRichTextBufferPreview(wxRichTextBuffer* buf);
    wxRichTextBuffer* GetRichTextBufferPreview() const;

    void SetRichTextBufferPrinting(wxRichTextBuffer* buf);
    wxRichTextBuffer* GetRichTextBufferPrinting() const;

    void SetParentWindow(wxWindow* parent);
    wxWindow* GetParentWindow() const;

    void SetTitle(const wxString& title);
    const wxString& GetTitle() const;

    void SetPreviewRect(const wxRect& rect);
    const wxRect& GetPreviewRect() const;
};


#endif
