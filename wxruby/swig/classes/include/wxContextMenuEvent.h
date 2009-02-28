// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxContextMenuEvent_h_)
#define _wxContextMenuEvent_h_


class wxContextMenuEvent : public wxCommandEvent
{
public:
    wxContextMenuEvent(wxEventType type = wxEVT_NULL,
                       wxWindowID winid = 0,
                       const wxPoint& pt = wxDefaultPosition)
        : wxCommandEvent(type, winid),
          m_pos(pt)
    { }
    wxContextMenuEvent(const wxContextMenuEvent & event)
        : wxCommandEvent(event),
        m_pos(event.m_pos)
    { }

    // Position of event (in screen coordinates)
    const wxPoint& GetPosition() const { return m_pos; }
    void SetPosition(const wxPoint& pos) { m_pos = pos; }

    virtual wxEvent *Clone() const { return new wxContextMenuEvent(*this); }

protected:
    wxPoint   m_pos;
};

#endif
