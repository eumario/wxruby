// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPrintData_h_)
#define _wxPrintData_h_
class wxPrintData : public wxObject
{
public:
	    wxPrintData();
	    wxPrintData(const wxPrintData& printData);
	    ~wxPrintData();

	    int GetNoCopies() const;
	    bool GetCollate() const;
	    int  GetOrientation() const;

	    // Is this data OK for showing the print dialog?
	    bool Ok() const ;

	    const wxString& GetPrinterName() const;
	    bool GetColour() const;
	    wxDuplexMode GetDuplex() const;
	    wxPaperSize GetPaperId() const;
	    const wxSize& GetPaperSize() const; // Not used yet: confusable with paper size
	                                                                      // in wxPageSetupDialogData
	    wxPrintQuality GetQuality() const;
	    wxPrintBin GetBin() const;
	    wxPrintMode GetPrintMode() const;

	    void SetNoCopies(int v);
	    void SetCollate(bool flag);
	    void SetOrientation(int orient);

	    void SetPrinterName(const wxString& name);
	    void SetColour(bool colour);
	    void SetDuplex(wxDuplexMode duplex);
	    void SetPaperId(wxPaperSize sizeId);
	    void SetPaperSize(const wxSize& sz);
	    void SetQuality(wxPrintQuality quality);
	    void SetBin(wxPrintBin bin);
	    void SetPrintMode(wxPrintMode printMode);

	    wxString GetFilename() const;
	    void SetFilename( const wxString &filename );

	    void operator=(const wxPrintData& data);

	    char* GetPrivData() const;
	    int GetPrivDataLen() const;
	    void SetPrivData( char *privData, int len );

	    // Convert between wxPrintData and native data
	    void ConvertToNative();
	    void ConvertFromNative();
	    // Holds the native print data
	    wxPrintNativeDataBase *GetNativeData() const;
};


#endif
