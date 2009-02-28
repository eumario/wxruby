// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxListbookEvent_h_)
#define _wxListbookEvent_h_

class wxListbookEvent : public wxBookCtrlBaseEvent
{
public:
  wxListbookEvent(wxEventType commandType = wxEVT_NULL, 
                  int id = 0,
                  int nSel = wxNOT_FOUND, 
                  int nOldSel = wxNOT_FOUND);

  wxListbookEvent(const wxListbookEvent& event);
};


#endif
