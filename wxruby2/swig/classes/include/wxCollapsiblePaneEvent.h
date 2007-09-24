//   Copyright 2007 by Kevin Smith
//   released under the MIT-style wxruby2 license

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
