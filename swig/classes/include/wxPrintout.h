// wxPrintout.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrintout_h_)
#define _wxPrintout_h_
class wxPrintout : public wxObject
{
public:
   wxPrintout(const wxString&  title = "Printout") ;
  virtual  ~wxPrintout() ;
  wxDC * GetDC() ;
  void GetPageInfo(int * minPage , int * maxPage , int * pageFrom , int * pageTo ) ;
  void GetPageSizeMM(int * w , int * h ) ;
  void GetPageSizePixels(int * w , int * h ) ;
  void GetPPIPrinter(int * w , int * h ) ;
  void GetPPIScreen(int * w , int * h ) ;
  wxString GetTitle() ;
  bool HasPage(int  pageNum ) ;
  bool IsPreview() ;
  virtual bool OnBeginDocument(int  startPage , int  endPage ) ;
  virtual void OnEndDocument() ;
  virtual void OnBeginPrinting() ;
  virtual void OnEndPrinting() ;
  virtual void OnPreparePrinting() ;
  virtual bool OnPrintPage(int  pageNum ) ;
};


#endif
