// wxPrintDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrintDialog_h_)
#define _wxPrintDialog_h_
class wxPrintDialog : public wxDialog
{
public:
   wxPrintDialog(wxWindow*  parent , wxPrintDialogData*  data = NULL) ;
  virtual  ~wxPrintDialog() ;
  wxPrintDialogData& GetPrintDialogData() ;
  wxDC*  GetPrintDC() ;
  bool Ok() const;
  int ShowModal() ;
};


#endif
