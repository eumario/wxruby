// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDisplay_h_)
#define _wxDisplay_h_

class wxDisplay
{
public:
    wxDisplay(size_t index = 0);
    static size_t GetCount();
    static int GetFromPoint(const wxPoint& pt);
    static int GetFromWindow(wxWindow *window);
    bool IsOk() const;
    wxRect GetClientArea() const;
    // int GetDepth() const;
    wxRect GetGeometry() const;
    wxString GetName() const;
    bool IsPrimary() const;
    wxArrayVideoModes GetModes(const wxVideoMode& mode = wxDefaultVideoMode) const;
    wxVideoMode GetCurrentMode() const;
    bool ChangeMode(const wxVideoMode& mode = wxDefaultVideoMode);
    void ResetMode();
    virtual ~wxDisplay();
};

#endif
