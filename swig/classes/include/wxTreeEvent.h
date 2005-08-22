//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxTreeEvent_h_)
#define _wxTreeEvent_h_
class wxTreeEvent : public wxNotifyEvent
{
public:
   wxTreeEvent(WXTYPE  commandType = 0, int  id = 0) ;
  int GetKeyCode() const;
  wxTreeItemId GetItem() const;
  const wxKeyEvent& GetKeyEvent() const;
  const wxString& GetLabel() const;
  wxTreeItemId GetOldItem() const;
  wxPoint GetPoint()() const;
  bool IsEditCancelled()() const;
};


#endif
