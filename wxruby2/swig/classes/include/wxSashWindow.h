// wxSashWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSashWindow_h_)
#define _wxSashWindow_h_
class wxSashWindow : public wxWindow
{
public:
   wxSashWindow() ;
   wxSashWindow(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxCLIP_CHILDREN, const wxString&  name = "sashWindow") ;
  virtual  ~wxSashWindow() ;
  bool GetSashVisible(wxSashEdgePosition  edge ) const;
  int GetMaximumSizeX() const;
  int GetMaximumSizeY() const;
  int GetMinimumSizeX() ;
  int GetMinimumSizeY(int  min ) const;
  bool HasBorder(wxSashEdgePosition  edge ) const;
  void SetMaximumSizeX(int  min ) ;
  void SetMaximumSizeY(int  min ) ;
  void SetMinimumSizeX(int  min ) ;
  void SetMinimumSizeY(int  min ) ;
  void SetSashVisible(wxSashEdgePosition  edge , bool  visible ) ;
  void SetSashBorder(wxSashEdgePosition  edge , bool  hasBorder ) ;
};


#endif
