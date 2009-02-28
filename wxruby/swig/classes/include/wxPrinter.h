// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license


#if !defined(_wxPrinter_h_)
#define _wxPrinter_h_
class wxPrinter : public wxObject
{
public:
    wxPrinter(wxPrintDialogData *data = (wxPrintDialogData *) NULL);
    virtual ~wxPrinter();

    virtual wxWindow *CreateAbortWindow(wxWindow *parent, wxPrintout *printout);
    virtual void ReportError(wxWindow *parent, wxPrintout *printout, const wxString& message);

    virtual bool Setup(wxWindow *parent);
    virtual bool Print(wxWindow *parent, wxPrintout *printout, bool prompt = true);
    virtual wxDC* PrintDialog(wxWindow *parent);

    virtual wxPrintDialogData& GetPrintDialogData() const;

    bool GetAbort() const { return sm_abortIt; }

    static wxPrinterError GetLastError() { return sm_lastError; }

};


#endif
