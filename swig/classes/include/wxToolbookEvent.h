// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxToolbookEvent_h_)
#define _wxToolbookEvent_h_

class wxToolbookEvent : public wxBookCtrlBaseEvent
{
public:
  wxToolbookEvent(wxEventType commandType = wxEVT_NULL, 
                    int id = 0,
                    int nSel = wxNOT_FOUND, 
                    int nOldSel = wxNOT_FOUND);
  wxToolbookEvent(const wxToolbookEvent& event);

};

#endif
