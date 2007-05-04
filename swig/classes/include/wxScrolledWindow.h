// wxScrolledWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScrolledWindow_h_)
#define _wxScrolledWindow_h_
class wxScrolledWindow : public wxPanel
{
public:
   wxScrolledWindow() ;
   wxScrolledWindow(wxWindow*  parent , wxWindowID  id = -1, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxHSCROLL, const wxString&  name = wxT("scrolledWindow")) ;
  virtual  ~wxScrolledWindow() ;
  void CalcScrolledPosition(int  x , int  y , int * xx , int * yy ) const;
  void CalcUnscrolledPosition(int  x , int  y , int * xx , int * yy ) const;
  bool Create(wxWindow *parent,
                wxWindowID winid,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxScrolledWindowStyle,
                const wxString& name = wxPanelNameStr);
  void DoPrepareDC(wxDC &dc);
  void EnableScrolling(const bool  xScrolling , const bool  yScrolling ) ;
  void GetScrollPixelsPerUnit(int*  xUnit , int*  yUnit ) const;
  void GetViewStart(int*  x , int*   y ) const;
  void GetVirtualSize(int*  x , int*  y ) const;
  bool IsRetained() const;
  void PrepareDC(wxDC&  dc ) ;
  virtual void OnDraw(wxDC&  dc ) ;
  void Scroll(int  x , int  y ) ;
  void SetScrollbars(int  pixelsPerUnitX , int  pixelsPerUnitY , int  noUnitsX , int  noUnitsY , int  xPos = 0, int yPos = 0, bool  noRefresh = false) ;
  void SetScrollRate(int  xstep , int  ystep ) ;
  void SetTargetWindow(wxWindow*  window ) ;
};


#endif
