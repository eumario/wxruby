// wxHtmlDCRenderer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlDCRenderer_h_)
#define _wxHtmlDCRenderer_h_
class wxHtmlDCRenderer : public wxObject
{
public:
   wxHtmlDCRenderer() ;
  void SetDC(wxDC*  dc , double  pixel_scale = 1.0) ;
  void SetFonts(wxString  normal_face , wxString  fixed_face , const int  *sizes = NULL) ;
  void SetSize(int  width , int  height ) ;
  void SetHtmlText(const wxString&  html , const wxString&  basepath = wxEmptyString, bool  isdir = true) ;
  int Render(int  x , int  y , int  from = 0, int  dont_render = false) ;
  int GetTotalHeight() ;
};


#endif
