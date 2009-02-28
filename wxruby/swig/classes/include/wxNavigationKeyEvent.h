// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license
// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxNavigationKeyEvent_h_)
#define _wxNavigationKeyEvent_h_

class wxNavigationKeyEvent : public wxEvent
{
public:
  wxNavigationKeyEvent();
  wxNavigationKeyEvent(const wxNavigationKeyEvent& event);
  // direction: forward (true) or backward (false)
  bool GetDirection() const;
  void SetDirection(bool bForward);

  // it may be a window change event (MDI, notebook pages...) or a control
  // change event
  bool IsWindowChange() const;
  void SetWindowChange(bool bIs);

  // Set to true under MSW if the event was generated using the tab key.
  // This is required for proper navogation over radio buttons
  bool IsFromTab() const;
  void SetFromTab(bool bIs);

  // the child which has the focus currently (may be NULL - use
  // wxWindow::FindFocus then)
  wxWindow* GetCurrentFocus() const;
  void SetCurrentFocus(wxWindow *win);

  virtual wxEvent *Clone() const;
};

#endif
