// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPreviewControlBar_h_)
#define _wxPreviewControlBar_h_
class wxPreviewControlBar : public wxPanel
{
public:
    wxPreviewControlBar(wxPrintPreview *preview,
                        long buttons,
                        wxWindow *parent,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        long style = wxTAB_TRAVERSAL,
                        const wxString& name = wxT("panel"));
    ~wxPreviewControlBar();

    virtual void CreateButtons();
    virtual void SetZoomControl(int zoom);
    virtual int GetZoomControl();
    virtual wxPrintPreviewBase *GetPrintPreview() const;

    void OnWindowClose(wxCommandEvent& event);
    void OnNext();
    void OnPrevious();
    void OnFirst();
    void OnLast();
    void OnGoto();
    void OnPrint();
    void OnPrintButton(wxCommandEvent& event);
    void OnNextButton(wxCommandEvent & event);
    void OnPreviousButton(wxCommandEvent & event);
    void OnFirstButton(wxCommandEvent & event);
    void OnLastButton(wxCommandEvent & event);
    void OnGotoButton(wxCommandEvent & event);
    void OnZoom(wxCommandEvent& event);
    void OnPaint(wxPaintEvent& event);
};


#endif
