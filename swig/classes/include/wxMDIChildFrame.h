// wxMDIChildFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMDIChildFrame_h_)
#define _wxMDIChildFrame_h_
class wxMDIChildFrame : public wxFrame
{
public:
   wxMDIChildFrame() ;
   wxMDIChildFrame(wxMDIParentFrame*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame") ;
  virtual  ~wxMDIChildFrame() ;
  void Activate() ;
  bool Create(wxMDIParentFrame*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame");
  void Maximize() ;
  void Restore() ;
};


#endif
