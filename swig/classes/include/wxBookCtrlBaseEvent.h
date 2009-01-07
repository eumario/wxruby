// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxBookCtrlBaseEvent_h_)
#define _wxBookCtrlBaseEvent_h_

class wxBookCtrlBaseEvent : public wxNotifyEvent
{
 public:
  wxBookCtrlBaseEvent(wxEventType commandType = wxEVT_NULL, 
                      int winid = 0,
                      int nSel = -1, 
                      int nOldSel = -1);

  wxBookCtrlBaseEvent(const wxBookCtrlBaseEvent& event);

  // accessors
  // the currently selected page (-1 if none)
  int GetSelection() const;
  void SetSelection(int nSel); 
  // the page that was selected before the change (-1 if none)
  int GetOldSelection() const;
  void SetOldSelection(int nOldSel);
};

#endif
