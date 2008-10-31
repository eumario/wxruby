// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxListbookEvent_h_)
#define _wxListbookEvent_h_
class wxListbookEvent : public wxNotifyEvent
{
public:
  wxListbookEvent(wxEventType commandType = wxEVT_NULL, int id = 0,
              int nSel = wxNOT_FOUND, int nOldSel = wxNOT_FOUND);
  int GetOldSelection() const;
  int GetSelection() const;
  void SetOldSelection(int  page ) ;
  void SetSelection(int  page ) ;
};


#endif
