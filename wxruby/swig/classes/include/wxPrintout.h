// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPrintout_h_)
#define _wxPrintout_h_
class wxPrintout : public wxObject
{
public:
    wxPrintout(const wxString& title = wxT("Printout"));
    virtual ~wxPrintout();

    virtual bool OnBeginDocument(int startPage, int endPage);
    virtual void OnEndDocument();
    virtual void OnBeginPrinting();
    virtual void OnEndPrinting();

    // Guaranteed to be before any other functions are called
    virtual void OnPreparePrinting();

    virtual bool HasPage(int page);
    virtual bool OnPrintPage(int page) = 0;
    virtual void GetPageInfo(int *minPage, int *maxPage, int *pageFrom, int *pageTo);

    virtual wxString GetTitle() const;

    wxDC *GetDC() const;
    void SetDC(wxDC *dc);

    void FitThisSizeToPaper(const wxSize& imageSize);
    void FitThisSizeToPage(const wxSize& imageSize);
    void FitThisSizeToPageMargins(const wxSize& imageSize, const wxPageSetupDialogData& pageSetupData);
    void MapScreenSizeToPaper();
    void MapScreenSizeToPage();
    void MapScreenSizeToPageMargins(const wxPageSetupDialogData& pageSetupData);
    void MapScreenSizeToDevice();

    wxRect GetLogicalPaperRect() const;
    wxRect GetLogicalPageRect() const;
    wxRect GetLogicalPageMarginsRect(const wxPageSetupDialogData& pageSetupData) const;

    void SetPageSizePixels(int w, int  h);
    void GetPageSizePixels(int *w, int  *h) const;
    void SetPageSizeMM(int w, int  h);
    void GetPageSizeMM(int *w, int  *h) const;
    void SetPPIScreen(int x, int y);
    void GetPPIScreen(int *x, int *y) const;
    void SetPPIPrinter(int x, int y);
    void GetPPIPrinter(int *x, int *y) const;

    wxRect GetPaperRectPixels() const;
    void SetPaperRectPixels(const wxRect& paperRectPixels);

    virtual bool IsPreview() const;
    virtual void SetIsPreview(bool p);

};


#endif
