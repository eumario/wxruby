// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxCollapsiblePaneEvent_h_)
#define _wxCollapsiblePaneEvent_h_
class wxCollapsiblePaneEvent : public wxCommandEvent
{
public:
    wxCollapsiblePaneEvent() {}
    wxCollapsiblePaneEvent(wxObject *generator, int id, bool collapsed);
    bool GetCollapsed() const;
    void SetCollapsed(bool c);
};

#endif
