// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
  wxPoint GetPoint() const;
  bool IsEditCancelled() const;
};


#endif
