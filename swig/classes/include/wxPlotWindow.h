// wxPlotWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPlotWindow_h_)
#define _wxPlotWindow_h_
class wxPlotWindow : public wxScrolledWindow
{
public:
   wxPlotWindow() ;
   wxPlotWindow(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos , const wxSize&  size , int  flags = wxPLOT_DEFAULT) ;
  virtual  ~wxPlotWindow() ;
  void Add(wxPlotCurve*  curve ) ;
  size_t GetCount() ;
  wxPlotCurve* GetAt(size_t  n ) ;
  void SetCurrent(wxPlotCurve*  current ) ;
  wxPlotCurve* GetCurrent() ;
  void Delete(wxPlotCurve*  curve ) ;
  void Move(wxPlotCurve*  curve , int  pixels_up ) ;
  void Enlarge(wxPlotCurve*  curve , double  factor ) ;
  void SetUnitsPerValue(double  upv ) ;
  double GetUnitsPerValue() ;
  void SetZoom(double  zoom ) ;
  double GetZoom() ;
  void RedrawEverything() ;
  void RedrawXAxis() ;
  void RedrawYAxis() ;
  void SetScrollOnThumbRelease(bool onrelease = true) ;
  void SetEnlargeAroundWindowCentre(bool aroundwindow = true) ;
};


#endif
