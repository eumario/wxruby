// wxPlotCurve.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPlotCurve_h_)
#define _wxPlotCurve_h_
class wxPlotCurve : public wxObject
{
public:
   wxPlotCurve(int  offsetY , double  startY , double  endY ) ;
  wxInt32 GetEndX() ;
  double GetEndY() ;
  int GetOffsetY() ;
  double GetY(wxInt32  x ) ;
  wxInt32 GetStartX() ;
  double GetStartY() ;
  void SetEndY(double  endY ) ;
  void SetOffsetY(int  offsetY ) ;
  void SetStartY(double  startY ) ;
};


#endif
