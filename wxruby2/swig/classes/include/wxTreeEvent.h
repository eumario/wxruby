// wxTreeEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

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
