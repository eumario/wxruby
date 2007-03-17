//   Copyright 2004-2006 by Kevin Smith
//   released under the MIT-style wxruby2 license


#if !defined(_wxPageSetupDialog_h_)
#define _wxPageSetupDialog_h_
class wxPageSetupDialog : public wxDialog
{
public:
    wxPageSetupDialog(wxWindow *parent, wxPageSetupDialogData *data = NULL);
    ~wxPageSetupDialog();

    int ShowModal();
    wxPageSetupDialogData& GetPageSetupDialogData();
    // old name
    wxPageSetupDialogData& GetPageSetupData();
};


#endif
