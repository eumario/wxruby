// wxPostScriptDC.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPostScriptDC_h_)
#define _wxPostScriptDC_h_
class wxPostScriptDC : public wxDC
{
public:
   wxPostScriptDC(const wxPrintData&  printData ) ;
   wxPostScriptDC(const wxString&  output , bool  interactive = true, wxWindow * parent ) ;
  static void SetResolution(int  ppi ) ;
  static int GetResolution() ;
};


#endif
