//   Copyright 2007 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxChildFocusEvent_h_)
#define _wxChildFocusEvent_h_

class wxChildFocusEvent : public wxCommandEvent
{
public:
    wxChildFocusEvent(wxWindow *win = NULL);
    wxWindow *GetWindow() const;
    virtual wxEvent *Clone() const;

};

#endif
