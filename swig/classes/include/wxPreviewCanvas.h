// wxPreviewCanvas.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPreviewCanvas_h_)
#define _wxPreviewCanvas_h_
class wxPreviewCanvas : public wxScrolledWindow
{
public:
   wxPreviewCanvas(wxPrintPreview*  preview , wxWindow*  parent , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = "canvas") ;
  virtual  ~wxPreviewCanvas() ;
  virtual void OnPaint(wxPaintEvent&  event ) ;
};


#endif
