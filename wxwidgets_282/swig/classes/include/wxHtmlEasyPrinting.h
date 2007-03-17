// wxHtmlEasyPrinting.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlEasyPrinting_h_)
#define _wxHtmlEasyPrinting_h_
class wxHtmlEasyPrinting : public wxObject
{
public:

   wxHtmlEasyPrinting(const wxString&  name = wxT("Printing"), wxWindow*  parentWindow = NULL) ;
  bool PreviewFile(const wxString&  htmlfile ) ;
  bool PreviewText(const wxString&  htmltext , const wxString&  basepath = wxEmptyString) ;
  bool PrintFile(const wxString&  htmlfile ) ;
  bool PrintText(const wxString&  htmltext , const wxString&  basepath = wxEmptyString) ;
  // Not defined in 2.6.3 headers
  //  void PrinterSetup() ;
  void PageSetup() ;
  void SetFonts(wxString  normal_face , wxString  fixed_face , const int  *sizes = NULL) ;
  void SetHeader(const wxString&  header , int  pg = wxPAGE_ALL) ;
  void SetFooter(const wxString&  footer , int  pg = wxPAGE_ALL) ;
  wxPrintData* GetPrintData() ;
  wxPageSetupDialogData* GetPageSetupData() ;
};


#endif
