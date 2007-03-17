// wxWindowDC.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWindowDC_h_)
#define _wxWindowDC_h_
class wxWindowDC : public wxDC
{
public:
	/**
	 * \brief Constructor. Pass a pointer to the window on which you wish to paint. 
	 * \param wxWindow*  
	*/

   wxWindowDC(wxWindow*  window ) ;
  // the following were missing from the xml
  virtual ~wxWindowDC();

  virtual bool Blit(wxCoord  xdest , wxCoord  ydest , wxCoord  width , wxCoord  height , wxDC*  source , wxCoord  xsrc , wxCoord  ysrc , int logicalFunc = wxCOPY, bool  useMask = false, wxCoord xsrcMask = -1, wxCoord ysrcMask = -1) ;
  virtual void Clear() ;
  virtual void CrossHair(wxCoord  x , wxCoord  y );
  virtual void DrawArc(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 , wxCoord  xc , wxCoord  yc );
  virtual void DrawBitmap(const wxBitmap&  bitmap , wxCoord  x , wxCoord  y , bool  transparent ) ;
  virtual void DrawEllipse(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
  virtual void DrawEllipse(const wxPoint&  pt , const wxSize&  size ) ;
  virtual void DrawEllipse(const wxRect&  rect ) ;
  virtual void DrawEllipticArc(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height , double  start , double  end ) ;
  virtual void DrawIcon(const wxIcon&  icon , wxCoord  x , wxCoord  y ) ;
  virtual void DrawLine(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 ) ;
  virtual void DrawLines(int  n , wxPoint  points[] , wxCoord xoffset = 0, wxCoord yoffset = 0) ;
  virtual void DrawLines(wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0) ;
  virtual void DrawPolygon(int  n , wxPoint  points[] , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE) ;
  virtual void DrawPolygon(wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE) ;
  virtual void DrawPoint(wxCoord  x , wxCoord  y ) ;
  virtual void DrawRectangle(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
  virtual void DrawRotatedText(const wxString&  text , wxCoord  x , wxCoord  y , double  angle ) ;
  virtual void DrawRoundedRectangle(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height , double radius ) ;
  virtual  void DrawText(const wxString&  text , wxCoord  x , wxCoord  y ) ;
  virtual wxCoord GetCharHeight() ;
  virtual wxCoord GetCharWidth() ;
  virtual bool GetPixel(wxCoord  x , wxCoord  y , wxColour * colour ) ;
  virtual void GetSize(wxCoord * width , wxCoord * height ) ;
  virtual void GetTextExtent(const wxString&  string , wxCoord * w , wxCoord * h , wxCoord * descent = NULL, wxCoord * externalLeading = NULL, wxFont * font = NULL) ;
  virtual void SetBackground(const wxBrush&  brush ) ;
  virtual void SetBackgroundMode(int  mode ) ;
  virtual void SetPalette(const wxPalette&  palette ) ;
  virtual void SetBrush(const wxBrush&  brush ) ;
  virtual void SetFont(const wxFont&  font ) ;
  virtual void SetLogicalFunction(int  function ) ;
  virtual void SetPen(const wxPen&  pen ) ;
};


#endif
