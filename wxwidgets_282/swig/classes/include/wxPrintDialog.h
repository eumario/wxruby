//   Copyright 2004-2006 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxPrintDialog_h_)
#define _wxPrintDialog_h_
class wxPrintDialog : public wxDialog
{
public:
    wxPrintDialog(wxWindow *parent, wxPrintDialogData* data = NULL);
    wxPrintDialog(wxWindow *parent, wxPrintData* data);
    ~wxPrintDialog();

    virtual int ShowModal();

    virtual wxPrintDialogData& GetPrintDialogData();
    virtual wxPrintData& GetPrintData();
    virtual wxDC *GetPrintDC();
};


#endif
