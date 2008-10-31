// Copyright 2004-2007, wxRuby development team
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
    virtual bool IsOk() const { return true; }
    virtual wxRect GetGeometry() const = 0;
    virtual wxString GetName() const = 0;
    virtual bool IsPrimary() const { return m_index == 0; }
    virtual wxArrayVideoModes
        GetModes(const wxVideoMode& mode = wxDefaultVideoMode) const = 0;
    virtual wxVideoMode GetCurrentMode() const = 0;
    virtual bool ChangeMode(const wxVideoMode& mode = wxDefaultVideoMode) = 0;
    void ResetMode() { (void)ChangeMode(); }
    virtual ~wxDisplay() { }
protected:
    size_t m_index;
};

#endif
