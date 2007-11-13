// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxCalculateLayoutEvent_h_)
#define _wxCalculateLayoutEvent_h_

class wxCalculateLayoutEvent : public wxEvent
{
public:
  wxCalculateLayoutEvent(wxWindowID id = 0);
  int GetFlags() const;
  wxRect GetRect() const;
  void SetFlags(int flags);
  void SetRect(const wxRect& rect);
};


#endif
