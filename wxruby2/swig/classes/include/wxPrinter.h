// wxPrinter.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrinter_h_)
#define _wxPrinter_h_
class wxPrinter : public wxObject
{
public:
   wxPrinter(wxPrintDialogData*  data = NULL) ;
  virtual  ~wxPrinter() ;
  bool Abort() ;
  void CreateAbortWindow(wxWindow*  parent , wxPrintout*  printout ) ;
  static wxPrinterError GetLastError() ;
  wxPrintDialogData& GetPrintDialogData() ;
  bool Print(wxWindow * parent , wxPrintout * printout , bool  prompt = true) ;
  wxDC* PrintDialog(wxWindow * parent ) ;
  void ReportError(wxWindow * parent , wxPrintout * printout , const wxString&  message ) ;
  bool Setup(wxWindow * parent ) ;
};


#endif
