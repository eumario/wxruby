//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxChoicebookEvent_h_)
#define _wxChoicebookEvent_h_
class wxChoicebookEvent : public wxNotifyEvent
{
public:
  wxChoicebookEvent(wxEventType commandType = wxEVT_NULL, int id = 0,

              int nSel = wxNOT_FOUND, int nOldSel = wxNOT_FOUND);
  int GetOldSelection() const;
  int GetSelection() const;
  void SetOldSelection(int  page ) ;
  void SetSelection(int  page ) ;
};


#endif
