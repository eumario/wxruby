// wxSplitterEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

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
