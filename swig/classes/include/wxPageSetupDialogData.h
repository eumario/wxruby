// wxPageSetupDialogData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPageSetupDialogData_h_)
#define _wxPageSetupDialogData_h_
class wxPageSetupDialogData : public wxObject
{
public:
   wxPageSetupDialogData() ;
   wxPageSetupDialogData(wxPageSetupDialogData&  data ) ;
   wxPageSetupDialogData(wxPrintData&  printData ) ;
  virtual  ~wxPageSetupDialogData() ;
  void EnableHelp(bool  flag ) ;
  void EnableMargins(bool  flag ) ;
  void EnableOrientation(bool  flag ) ;
  void EnablePaper(bool  flag ) ;
  void EnablePrinter(bool  flag ) ;
  bool GetDefaultMinMargins() const;
  bool GetEnableMargins() const;
  bool GetEnableOrientation() const;
  bool GetEnablePaper() const;
  bool GetEnablePrinter() const;
  bool GetEnableHelp() const;
  bool GetDefaultInfo() const;
  wxPoint GetMarginTopLeft() const;
  wxPoint GetMarginBottomRight() const;
  wxPoint GetMinMarginTopLeft() const;
  wxPoint GetMinMarginBottomRight() const;
  wxPaperSize GetPaperId() const;
  wxSize GetPaperSize() const;
  wxPrintData& GetPrintData() ;
  bool Ok() const;
  void SetDefaultInfo(bool  flag ) ;
  void SetDefaultMinMargins(bool  flag ) ;
  void SetMarginTopLeft(const wxPoint&  pt ) ;
  void SetMarginBottomRight(const wxPoint&  pt ) ;
  void SetMinMarginTopLeft(const wxPoint&  pt ) ;
  void SetMinMarginBottomRight(const wxPoint&  pt ) ;
  void SetPaperId(wxPaperSize&  id ) ;
  void SetPaperSize(const wxSize&  size ) ;
  void SetPrintData(const wxPrintData&  printData ) ;
};


#endif
