//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxSplitterEvent_h_)
#define _wxSplitterEvent_h_
class wxSplitterEvent : public wxNotifyEvent
{
public:
   wxSplitterEvent(wxEventType eventType = wxEVT_NULL, wxSplitterWindow * splitter = NULL) ;
  int GetSashPosition() const;
  int GetX() const;
  int GetY() const;
  wxWindow* GetWindowBeingRemoved() const;
  void SetSashPosition(int  pos ) ;
};


#endif
