// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxWindowCreateEvent_h_)
#define _wxWindowCreateEvent_h_
class wxWindowCreateEvent : public wxCommandEvent
{
 public:
  wxWindowCreateEvent(wxWindow* win = NULL);
};
#endif
