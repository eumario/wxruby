// wxScreenDC.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScreenDC_h_)
#define _wxScreenDC_h_
class wxScreenDC : public wxDC
{
public:
   wxScreenDC() ;
  bool StartDrawingOnTop(wxWindow*  window ) ;
  bool StartDrawingOnTop(wxRect* rect = NULL) ;
  bool EndDrawingOnTop() ;
};


#endif
