// wxPrintDialogData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrintDialogData_h_)
#define _wxPrintDialogData_h_
class wxPrintDialogData : public wxObject
{
public:
   wxPrintDialogData() ;
   wxPrintDialogData(wxPrintDialogData&  dialogData ) ;
   wxPrintDialogData(wxPrintData&  printData ) ;
  virtual  ~wxprintdialogdata() ;
  void EnableHelp(bool  flag ) ;
  void EnablePageNumbers(bool  flag ) ;
  void EnablePrintToFile(bool  flag ) ;
  void EnableSelection(bool  flag ) ;
  bool GetAllPages() const;
  bool GetCollate() const;
  int GetFromPage() const;
  int GetMaxPage() const;
  int GetMinPage() const;
  int GetNoCopies() const;
  wxPrintData& GetPrintData() ;
  bool GetPrintToFile() const;
  bool GetSelection() const;
  int GetToPage() const;
  bool Ok() const;
  void SetCollate(bool  flag ) ;
  void SetFromPage(int  page ) ;
  void SetMaxPage(int  page ) ;
  void SetMinPage(int  page ) ;
  void SetNoCopies(int  n ) ;
  void SetPrintData(const wxPrintData&  printData ) ;
  void SetPrintToFile(bool  flag ) ;
  void SetSelection(bool  flag ) ;
  void SetSetupDialog(bool  flag ) ;
  void SetToPage(int  page ) ;
};


#endif
