//   Copyright 2004-2006 by Kevin Smith
//   released under the MIT-style wxruby2 license

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
