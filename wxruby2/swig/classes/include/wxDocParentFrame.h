// wxDocParentFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDocParentFrame_h_)
#define _wxDocParentFrame_h_
class wxDocParentFrame : public wxFrame
{
public:
   wxDocParentFrame(wxDocManager*  manager , wxFrame * parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame") ;
  virtual  ~wxDocParentFrame() ;
  virtual void OnCloseWindow(wxCloseEvent&  event ) ;
};


#endif
