// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxRegion_h_)
#define _wxRegion_h_

class wxRegion : public wxGDIObject
{
 public:
 wxRegion();
 wxRegion(wxCoord x, wxCoord y, wxCoord width, wxCoord height );
 wxRegion(const wxPoint& topLeft, const wxPoint& bottomRight );
 wxRegion(const wxRect& rect );
 wxRegion(const wxRegion& region );
 wxRegion(size_t n, const wxPoint *points, int fillStyle = wxWINDING_RULE);
 wxRegion(const wxBitmap& bmp, const wxColour& transColour = wxNullColour, int tolerance = 0);
 virtual ~wxRegion();
 void Clear();
 wxRegionContain Contains(wxCoord x, wxCoord y) const;
 wxRegionContain Contains(const wxPoint& pt) const;
 wxRegionContain Contains(wxCoord x, wxCoord y, 
                          wxCoord width, wxCoord height) const;
 wxRegionContain Contains(const wxRect& rect) const;
 wxBitmap ConvertToBitmap() const;
 void GetBox(long& x, long& y, long& width, long& height) const;
 wxRect GetBox() const;
 bool Intersect(wxCoord x, wxCoord y, wxCoord width, wxCoord height );
 bool Intersect(const wxRect& rect );
 bool Intersect(const wxRegion& region );
 bool IsEmpty() const;
 bool Subtract(const wxRect& rect );
 bool Subtract(const wxRegion& region );
 bool Offset(wxCoord x, wxCoord y );
 bool Union(wxCoord x, wxCoord y, wxCoord width, wxCoord height );
 bool Union(const wxRect& rect );
 bool Union(const wxRegion& region );
 bool Union(const wxBitmap& bmp, const wxColour& transColour = wxNullColour, int tolerance = 0);
 bool Xor(wxCoord x, wxCoord y, wxCoord width, wxCoord height );
 bool Xor(const wxRect& rect );
 bool Xor(const wxRegion& region );
};

#endif
