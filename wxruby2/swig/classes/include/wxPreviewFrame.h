// wxPreviewFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPreviewFrame_h_)
#define _wxPreviewFrame_h_
class wxPreviewFrame : public wxFrame
{
public:
   wxPreviewFrame(wxPrintPreview*  preview , wxWindow*  parent , const wxString&  title , const wxPoint&  pos = wxDefaultPosition, const wxSize& size  size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame") ;
  virtual  ~wxPreviewFrame() ;
  void CreateControlBar() ;
  void CreateCanvas() ;
  void Initialize() ;
  virtual void OnCloseWindow(wxCloseEvent&  event ) ;
};


#endif
