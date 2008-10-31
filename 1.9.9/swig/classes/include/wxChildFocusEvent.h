// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
