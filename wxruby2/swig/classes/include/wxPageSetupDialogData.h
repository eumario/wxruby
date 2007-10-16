// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPageSetupDialogData_h_)
#define _wxPageSetupDialogData_h_
class wxPageSetupDialogData : public wxObject
{
public:
    wxPageSetupDialogData();
    wxPageSetupDialogData(const wxPageSetupDialogData& dialogData);
    wxPageSetupDialogData(const wxPrintData& printData);
    ~wxPageSetupDialogData();

    wxSize GetPaperSize() const;
    wxPaperSize GetPaperId() const;
    wxPoint GetMinMarginTopLeft() const;
    wxPoint GetMinMarginBottomRight() const;
    wxPoint GetMarginTopLeft() const;
    wxPoint GetMarginBottomRight() const;

    bool GetDefaultMinMargins() const;
    bool GetEnableMargins() const;
    bool GetEnableOrientation() const;
    bool GetEnablePaper() const;
    bool GetEnablePrinter() const;
    bool GetDefaultInfo() const;
    bool GetEnableHelp() const;

    // Is this data OK for showing the page setup dialog?
    bool Ok() const;
		bool IsOk() const;

    // If a corresponding paper type is found in the paper database, will set the m_printData
    // paper size id member as well.
    void SetPaperSize(const wxSize& sz);

    void SetPaperId(wxPaperSize id);

    // Sets the wxPrintData id, plus the paper width/height if found in the paper database.
    void SetPaperSize(wxPaperSize id);

    void SetMinMarginTopLeft(const wxPoint& pt);
    void SetMinMarginBottomRight(const wxPoint& pt);
    void SetMarginTopLeft(const wxPoint& pt);
    void SetMarginBottomRight(const wxPoint& pt);
    void SetDefaultMinMargins(bool flag);
    void SetDefaultInfo(bool flag);

    void EnableMargins(bool flag);
    void EnableOrientation(bool flag);
    void EnablePaper(bool flag);
    void EnablePrinter(bool flag);
    void EnableHelp(bool flag);

    // Use paper size defined in this object to set the wxPrintData
    // paper id
    void CalculateIdFromPaperSize();

    // Use paper id in wxPrintData to set this object's paper size
    void CalculatePaperSizeFromId();

    wxPageSetupDialogData& operator=(const wxPageSetupData& data);
    wxPageSetupDialogData& operator=(const wxPrintData& data);

    wxPrintData& GetPrintData();
    void SetPrintData(const wxPrintData& printData);
};


#endif
