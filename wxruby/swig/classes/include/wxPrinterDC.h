// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPrinterDC_h_)
#define _wxPrinterDC_h_
class wxPrinterDC : public wxDC
{
public:
  // Create a printer DC
  wxPrinterDC(const wxPrintData& printdata );
  ~wxPrinterDC();

  virtual bool StartDoc( const wxString& message );
  virtual void EndDoc(void);
  virtual void StartPage(void);
  virtual void EndPage(void);
  //wxPrintData& GetPrintData();
};


#endif
