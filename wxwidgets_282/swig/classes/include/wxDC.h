// Copyright 2004-2005 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxDC_h_)
#define _wxDC_h_
class wxDC : public wxObject
{
public:
   wxDC() ;
  virtual  ~wxDC() ;
  void BeginDrawing() ;
  virtual bool Blit(wxCoord  xdest , wxCoord  ydest , wxCoord  width , wxCoord  height , wxDC*  source , wxCoord  xsrc , wxCoord  ysrc , int logicalFunc = wxCOPY, bool  useMask = false, wxCoord xsrcMask = -1, wxCoord ysrcMask = -1)  = 0;
  static bool CacheEnabled() ;
  void CalcBoundingBox(wxCoord  x , wxCoord  y ) ;
  virtual void Clear()  = 0;
  static void ClearCache() ;
  virtual void CrossHair(wxCoord  x , wxCoord  y )  = 0;
  void DestroyClippingRegion() ;
  wxCoord DeviceToLogicalX(wxCoord  x ) ;
  wxCoord DeviceToLogicalXRel(wxCoord  x ) ;
  wxCoord DeviceToLogicalY(wxCoord  y ) ;
  wxCoord DeviceToLogicalYRel(wxCoord  y ) ;
  virtual void DrawArc(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 , wxCoord  xc , wxCoord  yc ) = 0;
  virtual void DrawBitmap(const wxBitmap&  bitmap , wxCoord  x , wxCoord  y , bool  transparent )  = 0;
  void DrawCheckMark(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
  void DrawCheckMark(const wxRect & rect ) ;
  void DrawCircle(wxCoord  x , wxCoord  y , wxCoord  radius ) ;
  void DrawCircle(const wxPoint&  pt , wxCoord  radius ) ;
  virtual void DrawEllipse(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height )  = 0;
  virtual void DrawEllipse(const wxPoint&  pt , const wxSize&  size )  = 0;
  virtual void DrawEllipse(const wxRect&  rect )  = 0;
  virtual void DrawEllipticArc(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height , double  start , double  end )  = 0;
  virtual void DrawIcon(const wxIcon&  icon , wxCoord  x , wxCoord  y )  = 0;
  virtual void DrawLine(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 )  = 0;
  virtual void DrawLines(int  n , wxPoint  points[] , wxCoord xoffset = 0, wxCoord yoffset = 0)  = 0;
  virtual void DrawLines(wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0)  = 0;
  virtual void DrawPolygon(int  n , wxPoint  points[] , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE)  = 0;
  virtual void DrawPolygon(wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE)  = 0;
  virtual void DrawPoint(wxCoord  x , wxCoord  y )  = 0;
  virtual void DrawRectangle(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height )  = 0;
  virtual void DrawRotatedText(const wxString&  text , wxCoord  x , wxCoord  y , double  angle )  = 0;
  virtual void DrawRoundedRectangle(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height , double radius )  = 0;
  void DrawSpline(int n, wxPoint points[] ) ;
  void DrawSpline(wxList * points ) ;
  void DrawSpline(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 , wxCoord  x3 , wxCoord  y3 ) ;
  virtual  void DrawText(const wxString&  text , wxCoord  x , wxCoord  y )  = 0;
  static void EnableCache(bool  enableCache ) ;
  void EndDoc() ;
  void EndDrawing() ;
  void EndPage() ;
  bool FloodFill(wxCoord  x , wxCoord  y , const wxColour&  colour , int style = wxFLOOD_SURFACE) ;
  //wxBrush& GetBackground();
  const wxBrush& GetBackground() const;
  int GetBackgroundMode() const;
  //wxBrush& GetBrush();
  const wxBrush& GetBrush() const;
  virtual wxCoord GetCharHeight()  = 0;
  virtual wxCoord GetCharWidth()  = 0;
  void GetClippingBox(wxCoord  *x , wxCoord  *y , wxCoord  *width , wxCoord  *height ) ;
  //wxFont& GetFont();
  const wxFont& GetFont() const;
  int GetLogicalFunction() ;
  int GetMapMode() ;
//  bool GetOptimization() ;
  //wxPen& GetPen();
  const wxPen& GetPen() const;
  virtual bool GetPixel(wxCoord  x , wxCoord  y , wxColour * colour )  = 0;
  virtual void GetSize(wxCoord * width , wxCoord * height )  = 0;
  //wxColour& GetTextBackground();
  const wxColour& GetTextBackground() const;
  virtual void GetTextExtent(const wxString&  string , wxCoord * w , wxCoord * h , wxCoord * descent = NULL, wxCoord * externalLeading = NULL, wxFont * font = NULL)  = 0;
    virtual void GetMultiLineTextExtent(const wxString& text,
                                        wxCoord *width,
                                        wxCoord *height,
                                        wxCoord *heightLine = NULL,
                                        wxFont *font = NULL);
  //wxColour& GetTextForeground();
  const wxColour& GetTextForeground() const;
  void GetUserScale(double  *x , double  *y ) ;
  wxCoord LogicalToDeviceX(wxCoord  x ) ;
  wxCoord LogicalToDeviceXRel(wxCoord  x ) ;
  wxCoord LogicalToDeviceY(wxCoord  y ) ;
  wxCoord LogicalToDeviceYRel(wxCoord  y ) ;
  wxCoord MaxX() ;
  wxCoord MaxY() ;
  wxCoord MinX() ;
  wxCoord MinY() ;
  bool Ok() ;
  void ResetBoundingBox() ;
  void SetAxisOrientation(bool  xLeftRight , bool  yBottomUp ) ;
  void SetDeviceOrigin(wxCoord  x , wxCoord  y ) ;
  virtual void SetBackground(const wxBrush&  brush )  = 0;
  virtual void SetBackgroundMode(int  mode )  = 0;
  void SetClippingRegion(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
  void SetClippingRegion(const wxPoint&  pt , const wxSize&  sz ) ;
  void SetClippingRegion(const wxRect&  rect ) ;
  void SetClippingRegion(const wxRegion&  region ) ;
  virtual void SetPalette(const wxPalette&  palette )  = 0;
  virtual void SetBrush(const wxBrush&  brush )  = 0;
  virtual void SetFont(const wxFont&  font )  = 0;
  virtual void SetLogicalFunction(int  function )  = 0;
  void SetMapMode(int  int ) ;
//  void SetOptimization(bool  optimize ) ;
  virtual void SetPen(const wxPen&  pen )  = 0;
  void SetTextBackground(const wxColour&  colour ) ;
  void SetTextForeground(const wxColour&  colour ) ;
  void SetUserScale(double  xScale , double  yScale ) ;
  bool StartDoc(const wxString&  message ) ;
  bool StartPage() ;
};


#endif
