// wxPrinterDC.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPrinterDC_h_)
#define _wxPrinterDC_h_
class wxPrinterDC : public wxDC
{
public:
   wxPrinterDC(const wxPrintData&  printData ) ;
   wxPrinterDC(const wxString&  driver , const wxString&  device , const wxString&  output , const bool  interactive = true, int  orientation = wxPORTRAIT) ;
};


#endif
