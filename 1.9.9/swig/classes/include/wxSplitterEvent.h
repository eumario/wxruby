// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
