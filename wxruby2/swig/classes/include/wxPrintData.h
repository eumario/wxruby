// wxPrintData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrintData_h_)
#define _wxPrintData_h_
class wxPrintData : public wxObject
{
public:
   wxPrintData() ;
   wxPrintData(const wxPrintData&  data ) ;
  virtual  ~wxPrintData() ;
  bool GetCollate() const;
  bool GetColour() const;
  wxDuplexMode GetDuplex() const;
  int GetNoCopies() const;
  int GetOrientation() const;
  wxPaperSize GetPaperId() const;
  const wxString& GetPrinterName() const;
  wxPrintQuality GetQuality() const;
  bool Ok() const;
  void SetCollate(bool  flag ) ;
  void SetColour(bool  flag ) ;
  void SetDuplex(wxDuplexMode  mode ) ;
  void SetNoCopies(int  n ) ;
  void SetOrientation(int  orientation ) ;
  void SetPaperId(wxPaperSize  paperId ) ;
  void SetPrinterName(const wxString&  printerName ) ;
  void SetQuality(wxPrintQuality  quality ) ;
};


#endif
