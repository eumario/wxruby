// wxSashLayoutWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSashLayoutWindow_h_)
#define _wxSashLayoutWindow_h_
class wxSashLayoutWindow : public wxSashWindow
{
public:
   wxSashLayoutWindow() ;
   wxSashLayoutWindow(wxSashLayoutWindow*  parent , wxSashLayoutWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxCLIP_CHILDREN, const wxString&  name = "layoutWindow") ;
  virtual  ~wxSashLayoutWindow() ;
  wxLayoutAlignment GetAlignment() const;
  wxLayoutOrientation GetOrientation() const;
  virtual void OnCalculateLayout(wxCalculateLayoutEvent&  event ) ;
  virtual void OnQueryLayoutInfo(wxQueryLayoutInfoEvent&  event ) ;
  void SetAlignment(wxLayoutAlignment  alignment ) ;
  void SetDefaultSize(const wxSize&  size ) ;
  void SetOrientation(wxLayoutOrientation  orientation ) ;
};


#endif
