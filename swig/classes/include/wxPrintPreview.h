// wxPrintPreview.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrintPreview_h_)
#define _wxPrintPreview_h_
class wxPrintPreview : public wxObject
{
public:
   wxPrintPreview(wxPrintout*  printout , wxPrintout*  printoutForPrinting , wxPrintData*  data = NULL) ;
  virtual  ~wxPrintPreview() ;
  bool DrawBlankPage(wxWindow*  window ) ;
  wxWindow*  GetCanvas() ;
  int GetCurrentPage() ;
  wxFrame * GetFrame() ;
  int GetMaxPage() ;
  int GetMinPage() ;
  wxPrintData& GetPrintData() ;
  wxPrintout * GetPrintout() ;
  wxPrintout * GetPrintoutForPrinting() ;
  bool Ok() ;
  bool PaintPage(wxWindow*  window ) ;
  bool Print(bool  prompt ) ;
  bool RenderPage(int  pageNum ) ;
  void SetCanvas(wxWindow*  window ) ;
  void SetCurrentPage(int  pageNum ) ;
  void SetFrame(wxFrame * frame ) ;
  void SetPrintout(wxPrintout * printout ) ;
  void SetZoom(int  percent ) ;
};


#endif
