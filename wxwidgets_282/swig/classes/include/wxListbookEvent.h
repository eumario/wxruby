//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

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
