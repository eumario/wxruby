// wxDocMDIParentFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDocMDIParentFrame_h_)
#define _wxDocMDIParentFrame_h_
class wxDocMDIParentFrame : public wxMDIParentFrame
{
public:
   wxDocMDIParentFrame(wxDocManager*  manager , wxFrame * parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame") ;
  virtual  ~wxDocMDIParentFrame() ;
  virtual void OnCloseWindow(wxCloseEvent&  event ) ;
};


#endif
