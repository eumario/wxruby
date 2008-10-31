// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDC_h_)
#define _wxDC_h_

class wxDC : public wxObject
{
public:
   wxDC() ;
  virtual  ~wxDC() ;
  bool Blit(wxCoord  xdest , wxCoord  ydest , wxCoord  width , wxCoord  height , wxDC*  source , wxCoord  xsrc , wxCoord  ysrc , int logicalFunc = wxCOPY, bool  useMask = false, wxCoord xsrcMask = -1, wxCoord ysrcMask = -1);
  void CalcBoundingBox(wxCoord  x , wxCoord  y ) ;
  void Clear();
  virtual void ComputeScaleAndOrigin();
  void CrossHair(wxCoord  x , wxCoord  y );
  void DestroyClippingRegion() ;
  wxCoord DeviceToLogicalX(wxCoord  x ) ;
  wxCoord DeviceToLogicalXRel(wxCoord  x ) ;
  wxCoord DeviceToLogicalY(wxCoord  y ) ;
  wxCoord DeviceToLogicalYRel(wxCoord  y ) ;
  void DrawArc(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 , wxCoord  xc , wxCoord  yc );
  void DrawBitmap(const wxBitmap&  bitmap , wxCoord  x , wxCoord  y , bool  transparent );
  void DrawCheckMark(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
  void DrawCheckMark(const wxRect & rect ) ;
  void DrawCircle(wxCoord  x , wxCoord  y , wxCoord  radius ) ;
  void DrawCircle(const wxPoint&  pt , wxCoord  radius ) ;
  void DrawEllipse(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height );
  void DrawEllipse(const wxPoint&  pt , const wxSize&  size );
  void DrawEllipse(const wxRect&  rect );
  void DrawEllipticArc(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height , double  start , double  end );
  void DrawIcon(const wxIcon&  icon , wxCoord  x , wxCoord  y );
  virtual void DrawLabel(const wxString& text, const wxBitmap& image, const wxRect& rect, int alignment = wxALIGN_LEFT | wxALIGN_TOP, int indexAccel = -1, wxRect *rectBounding = NULL);
  void DrawLabel(const wxString& text, const wxRect& rect, int alignment = wxALIGN_LEFT | wxALIGN_TOP, int indexAccel = -1);
  void DrawLine(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 );
  void DrawLines(int  n , wxPoint  points[] , wxCoord xoffset = 0, wxCoord yoffset = 0);
  void DrawLines(wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0);
  void DrawPolygon(int  n , wxPoint  points[] , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE);
  void DrawPolygon(wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE);
  void DrawPolyPolygon(int n, int count[], wxPoint points[], wxCoord xoffset = 0, wxCoord yoffset = 0, int fill_style = wxODDEVEN_RULE);
  void DrawPoint(wxCoord  x , wxCoord  y );
  void DrawRectangle(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height );
  void DrawRotatedText(const wxString&  text , wxCoord  x , wxCoord  y , double  angle );
  void DrawRoundedRectangle(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height , double radius );
  void DrawSpline(int n, wxPoint points[] ) ;
  void DrawSpline(wxList * points ) ;
  void DrawSpline(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 , wxCoord  x3 , wxCoord  y3 ) ;
   void DrawText(const wxString&  text , wxCoord  x , wxCoord  y );
  void EndDoc() ;
  void EndPage() ;
  bool FloodFill(wxCoord  x , wxCoord  y , const wxColour&  colour , int style = wxFLOOD_SURFACE) ;
  const wxBrush& GetBackground() const;
  int GetBackgroundMode() const;
  const wxBrush& GetBrush() const;
  wxCoord GetCharHeight();
  wxCoord GetCharWidth();
  void GetClippingBox(wxCoord  *x , wxCoord  *y , wxCoord  *width , wxCoord  *height ) ;
  const wxFont& GetFont() const;
  wxLayoutDirection GetLayoutDirection() const;
  int GetLogicalFunction() ;
  int GetMapMode() ;
  void GetMultiLineTextExtent(const wxString& text,
							  wxCoord *width,
							  wxCoord *height,
							  wxCoord *heightLine = NULL,
							  wxFont *font = NULL) const;
  wxSize GetMultiLineTextExtent(const wxString& string) const;
  bool GetPartialTextExtents(const wxString& text, wxArrayInt& widths) const;
  const wxPen& GetPen() const;
  bool GetPixel(wxCoord  x , wxCoord  y , wxColour * colour );
  wxSize GetPPI() const;
  void GetSize(wxCoord * width , wxCoord * height );
  wxSize GetSize() const;
  void GetSizeMM(wxCoord *width, wxCoord *height) const;
  wxSize GetSizeMM() const;
  const wxColour& GetTextBackground() const;
  void GetTextExtent(const wxString&  string , wxCoord * w , wxCoord * h , wxCoord * descent = NULL, wxCoord * externalLeading = NULL, wxFont * font = NULL);
  wxSize GetTextExtent(const wxString& string) const;
  const wxColour& GetTextForeground() const;
  void GetUserScale(double  *x , double  *y ) ;
  void GradientFillConcentric(const wxRect& rect, const wxColour& initialColour, const wxColour& destColour);
  void GradientFillConcentric(const wxRect& rect, const wxColour& initialColour, const wxColour& destColour, const wxPoint& circleCenter);
  void GradientFillLinear(const wxRect& rect, const wxColour& initialColour, const wxColour& destColour, wxDirection nDirection = wxEAST);
  wxCoord LogicalToDeviceX(wxCoord  x ) ;
  wxCoord LogicalToDeviceXRel(wxCoord  x ) ;
  wxCoord LogicalToDeviceY(wxCoord  y ) ;
  wxCoord LogicalToDeviceYRel(wxCoord  y ) ;
  wxCoord MaxX() ;
  wxCoord MaxY() ;
  wxCoord MinX() ;
  wxCoord MinY() ;
  bool IsOk();
  void ResetBoundingBox() ;
  void SetAxisOrientation(bool  xLeftRight , bool  yBottomUp ) ;
  void SetDeviceOrigin(wxCoord  x , wxCoord  y ) ;
  void SetBackground(const wxBrush&  brush );
  void SetBackgroundMode(int  mode );
  void SetBrush(const wxBrush&  brush );
  void SetClippingRegion(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
  void SetClippingRegion(const wxPoint&  pt , const wxSize&  sz ) ;
  void SetClippingRegion(const wxRect&  rect ) ;
  void SetClippingRegion(const wxRegion&  region ) ;
  void SetFont(const wxFont&  font );
  void SetLogicalFunction(int  function );
  void SetMapMode(int  int ) ;
  void SetPalette(const wxPalette&  palette );
  void SetPen(const wxPen&  pen );
  void SetTextBackground(const wxColour&  colour ) ;
  void SetTextForeground(const wxColour&  colour ) ;
  void SetUserScale(double  xScale , double  yScale ) ;
  bool StartDoc(const wxString&  message ) ;
  bool StartPage() ;
};


#endif
