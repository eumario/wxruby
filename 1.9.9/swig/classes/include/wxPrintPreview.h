// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPrintPreview_h_)
#define _wxPrintPreview_h_
class wxPrintPreview : public wxObject
{
public:
    wxPrintPreview(wxPrintout *printout,
                   wxPrintout *printoutForPrinting = (wxPrintout *) NULL,
                   wxPrintDialogData *data = (wxPrintDialogData *) NULL);
    wxPrintPreview(wxPrintout *printout,
                   wxPrintout *printoutForPrinting,
                   wxPrintData *data);
    virtual ~wxPrintPreview();

    virtual bool SetCurrentPage(int pageNum);
    virtual int GetCurrentPage() const;
    virtual void SetPrintout(wxPrintout *printout);
    virtual wxPrintout *GetPrintout() const;
    virtual wxPrintout *GetPrintoutForPrinting() const;
    virtual void SetFrame(wxFrame *frame);
    virtual void SetCanvas(wxPreviewCanvas *canvas);

    virtual wxFrame *GetFrame() const;
    virtual wxPreviewCanvas *GetCanvas() const;
    virtual bool PaintPage(wxPreviewCanvas *canvas, wxDC& dc);
    virtual bool DrawBlankPage(wxPreviewCanvas *canvas, wxDC& dc);
    virtual void AdjustScrollbars(wxPreviewCanvas *canvas);
    virtual bool RenderPage(int pageNum);
    virtual void SetZoom(int percent);

    virtual bool Print(bool interactive);
    virtual void DetermineScaling();

    virtual wxPrintDialogData& GetPrintDialogData();

    virtual int GetMaxPage() const;
    virtual int GetMinPage() const;

    virtual bool IsOk() const;
    virtual void SetOk(bool ok);
};


#endif
