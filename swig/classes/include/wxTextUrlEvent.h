// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxTextUrlEvent_h_)
#define _wxTextUrlEvent_h_

class wxTextUrlEvent : public wxCommandEvent
{
public:
    wxTextUrlEvent(int winid, const wxMouseEvent& evtMouse,
                   long start, long end)
        : wxCommandEvent(wxEVT_COMMAND_TEXT_URL, winid)
        , m_evtMouse(evtMouse), m_start(start), m_end(end)
        { }

    const wxMouseEvent& GetMouseEvent() const { return m_evtMouse; }
    long GetURLStart() const { return m_start; }
    long GetURLEnd() const { return m_end; }

protected:
    wxMouseEvent m_evtMouse;
    long m_start,
         m_end;
};

#endif
