// wxMDIParentFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMDIParentFrame_h_)
#define _wxMDIParentFrame_h_
class wxMDIParentFrame : public wxFrame
{
public:
   wxMDIParentFrame() ;
   wxMDIParentFrame(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame") ;
  virtual  ~wxMDIParentFrame() ;
  void ActivateNext() ;
  void ActivatePrevious() ;
  void ArrangeIcons() ;
  void Cascade() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame") ;
  virtual void GetClientSize(int*  width , int*  height ) const;
  wxMDIChildFrame* GetActiveChild() const;
  wxMDIClientWindow* GetClientWindow() const;
  virtual wxWindow* GetToolBar() const;
  wxMenu* GetWindowMenu() const;
  virtual wxMDIClientWindow* OnCreateClient() ;
  virtual void SetToolBar(wxWindow*  toolbar ) ;
  void SetWindowMenu(wxMenu*  menu ) ;
  void Tile() ;
};


#endif
