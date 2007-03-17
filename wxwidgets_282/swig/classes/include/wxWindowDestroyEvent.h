//   Copyright 2004-2006 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxWindowDestroyEvent_h_)
#define _wxWindowDestroyEvent_h_
class wxWindowDestroyEvent : public wxCommandEvent
{
 public:
  wxWindowDestroyEvent(wxWindow* win = NULL);
};
#endif
