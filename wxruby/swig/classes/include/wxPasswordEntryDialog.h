// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
