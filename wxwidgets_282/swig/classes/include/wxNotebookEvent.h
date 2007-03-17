//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxNotebookEvent_h_)
#define _wxNotebookEvent_h_
class wxNotebookEvent : public wxNotifyEvent
{
public:
   wxNotebookEvent(wxEventType eventType = wxEVT_NULL, int id = 0, int sel = -1, int oldSel = -1) ;
  int GetOldSelection() const;
  int GetSelection() const;
  void SetOldSelection(int  page ) ;
  void SetSelection(int  page ) ;
};


#endif
