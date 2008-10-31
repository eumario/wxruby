// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPrintDialogData_h_)
#define _wxPrintDialogData_h_
class wxPrintDialogData : public wxObject
{
public:
	    wxPrintDialogData();
	    wxPrintDialogData(const wxPrintDialogData& dialogData);
	    wxPrintDialogData(const wxPrintData& printData);
	    ~wxPrintDialogData();

	    int GetFromPage() const;
	    int GetToPage() const;
	    int GetMinPage() const;
	    int GetMaxPage() const;
	    int GetNoCopies() const;
	    bool GetAllPages() const;
	    bool GetSelection() const;
	    bool GetCollate() const;
	    bool GetPrintToFile() const;

	    void SetFromPage(int v);
	    void SetToPage(int v);
	    void SetMinPage(int v);
	    void SetMaxPage(int v);
	    void SetNoCopies(int v);
	    void SetAllPages(bool flag);
	    void SetSelection(bool flag);
	    void SetCollate(bool flag);
	    void SetPrintToFile(bool flag);

	    void EnablePrintToFile(bool flag);
	    void EnableSelection(bool flag);
	    void EnablePageNumbers(bool flag);
	    void EnableHelp(bool flag);

	    bool GetEnablePrintToFile() const;
	    bool GetEnableSelection() const;
	    bool GetEnablePageNumbers() const;
	    bool GetEnableHelp() const;

	    // Is this data OK for showing the print dialog?
	    bool Ok() const;

	    wxPrintData& GetPrintData();
	    void SetPrintData(const wxPrintData& printData);

	    void operator=(const wxPrintDialogData& data);
	    void operator=(const wxPrintData& data); // Sets internal m_printData member
};


#endif
