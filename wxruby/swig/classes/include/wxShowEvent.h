// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxShowEvent_h_)
#define _wxShowEvent_h_
class wxShowEvent : public wxEvent
{
public:
  wxShowEvent(int  id = 0, bool show = false);
  wxShowEvent(const wxShowEvent & event);
  bool GetShow() const;
  void SetShow(bool show);
};


#endif
