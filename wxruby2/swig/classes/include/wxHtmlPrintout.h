// wxHtmlPrintout.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlPrintout_h_)
#define _wxHtmlPrintout_h_
class wxHtmlPrintout : public wxPrintout
{
public:
   wxHtmlPrintout(const wxString&  title = "Printout") ;
  void SetFonts(wxString  normal_face , wxString  fixed_face , const int  *sizes = NULL) ;
  void SetFooter(const wxString&  footer , int  pg = wxPAGE_ALL) ;
  void SetHeader(const wxString&  header , int  pg = wxPAGE_ALL) ;
  void SetHtmlFile(const wxString&  htmlfile ) ;
  void SetHtmlText(const wxString&  html , const wxString&  basepath = wxEmptyString, bool  isdir = true) ;
  void SetMargins(float  top = 25.2, float  bottom = 25.2, float  left = 25.2, float  right = 25.2, float  spaces = 5) ;
};


#endif
