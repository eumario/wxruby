// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxClipboardTextEvent_h_)
#define _wxClipboardTextEvent_h_

class wxClipboardTextEvent : public wxCommandEvent
{
public:
    wxClipboardTextEvent(wxEventType type = wxEVT_NULL,
                         wxWindowID winid = 0);
    wxClipboardTextEvent(const wxClipboardTextEvent & event);
    virtual wxEvent *Clone() const;
};

#endif
