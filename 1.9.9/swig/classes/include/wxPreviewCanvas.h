// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPreviewCanvas_h_)
#define _wxPreviewCanvas_h_
class wxPreviewCanvas : public wxScrolledWindow
{
public:
    wxPreviewCanvas(wxPrintPreview *preview,
                    wxWindow *parent,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = 0,
                    const wxString& name = wxT("canvas"));
    ~wxPreviewCanvas();

    void OnPaint(wxPaintEvent& event);
    void OnChar(wxKeyEvent &event);
    // Responds to colour changes
    void OnSysColourChanged(wxSysColourChangedEvent& event);
};


#endif
