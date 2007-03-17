// Copyright 2004-2007 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxPasswordEntryDialog_h_)
#define _wxPasswordEntryDialog_h_

class wxPasswordEntryDialog : public wxTextEntryDialog
{
public:
    wxPasswordEntryDialog(wxWindow *parent,
                      const wxString& message,
                      const wxString& caption = wxGetPasswordFromUserPromptStr,
                      const wxString& value = wxEmptyString,
                      long style = wxTextEntryDialogStyle,
                      const wxPoint& pos = wxDefaultPosition);
};

#endif
