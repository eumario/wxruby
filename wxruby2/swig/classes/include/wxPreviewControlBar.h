// wxPreviewControlBar.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPreviewControlBar_h_)
#define _wxPreviewControlBar_h_
class wxPreviewControlBar : public wxPanel
{
public:
   wxPreviewControlbar(wxPrintPreview*  preview , long  buttons , wxWindow*  parent , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = "panel") ;
  virtual  ~wxPreviewControlBar() ;
  void CreateButtons() ;
  wxPrintPreview * GetPrintPreview() ;
  int GetZoomControl() ;
  void SetZoomControl(int  percent ) ;
};


#endif
