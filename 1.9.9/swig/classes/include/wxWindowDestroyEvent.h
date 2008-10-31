// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxWindowDestroyEvent_h_)
#define _wxWindowDestroyEvent_h_
class wxWindowDestroyEvent : public wxCommandEvent
{
 public:
  wxWindowDestroyEvent(wxWindow* win = NULL);
};
#endif
