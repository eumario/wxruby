// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPreviewFrame_h_)
#define _wxPreviewFrame_h_
class wxPreviewFrame : public wxFrame
{
public:
    wxPreviewFrame(wxPrintPreview *preview,
                   wxWindow *parent,
                   const wxString& title = wxT("Print Preview"),
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = wxDEFAULT_FRAME_STYLE,
                   const wxString& name = wxT("frame"));
    ~wxPreviewFrame();

    void OnCloseWindow(wxCloseEvent& event);
    virtual void Initialize();
    virtual void CreateCanvas();
    virtual void CreateControlBar();

    inline wxPreviewControlBar* GetControlBar() const;
};


#endif
