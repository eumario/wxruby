//   Copyright 2004-2006 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxWindowCreateEvent_h_)
#define _wxWindowCreateEvent_h_
class wxWindowCreateEvent : public wxCommandEvent
{
 public:
  wxWindowCreateEvent(wxWindow* win = NULL);
};
#endif
