// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRect_h_)
#define _wxRect_h_
class wxRect
{
public:
   wxRect();
   wxRect(int  x , int  y , int  width , int  height);
   wxRect(const wxPoint& topLeft, const wxPoint& bottomRight);
   wxRect(const wxPoint& pos, const wxSize&  size);

  int x, y;
  int width, height;

  // centre this rectangle in the given (usually, but not necessarily,
  // larger) one
  wxRect CentreIn(const wxRect& r, int dir = wxBOTH) const;
  wxRect CenterIn(const wxRect& r, int dir = wxBOTH) const;

  // return true if the point is (not strcitly) inside the rect
  bool Contains(int x, int y) const;
  bool Contains(const wxPoint& pt) const;
  // return true if the rectangle is (not strcitly) inside the rect
  bool Contains(const wxRect& rect) const;

  void Deflate(wxCoord dx , wxCoord dy);
  void Deflate(wxCoord diff ) ;
  wxRect Deflate(wxCoord dx, wxCoord dy) const;

  int GetHeight() const;
  int GetWidth() const;

  int GetBottom() const;
  int GetLeft() const;
  int GetRight() const;
  int GetTop() const;

  wxSize GetSize() const;
  wxPoint GetPosition() const;

  wxPoint GetTopLeft() const;
  wxPoint GetTopRight() const;
  wxPoint GetBottomLeft() const;
  wxPoint GetBottomRight() const;

  int GetX() const;
  int GetY() const;

  void Inflate(wxCoord dx, wxCoord dy);
  void Inflate(wxCoord diff);
  void Inflate(const wxSize diff);
  wxRect Inflate(wxCoord dx, wxCoord dy) const;

  wxRect Intersect(const wxRect& rect) const;

  bool IsEmpty() const;

  void Offset(wxCoord dx, wxCoord dy);
  void Offset(const wxPoint& pt);

  void SetHeight(int height);
  void SetWidth(int width);
  void SetX(int  x);
  void SetY(int  y);

  void SetSize(const wxSize &s);

  wxRect Union(const wxRect& rect) const;
};


#endif
