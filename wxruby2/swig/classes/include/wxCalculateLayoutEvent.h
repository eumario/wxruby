// wxCalculateLayoutEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCalculateLayoutEvent_h_)
#define _wxCalculateLayoutEvent_h_
class wxCalculateLayoutEvent : public wxEvent
{
public:
   wxCalculateLayoutEvent(wxWindowID  id = 0) ;
  int GetFlags() const;
  wxRect GetRect() const;
  void SetFlags(int  flags ) ;
  void SetRect(const wxRect&  rect ) ;
};


#endif
