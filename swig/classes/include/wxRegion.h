// wxRegion.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxRegion_h_)
#define _wxRegion_h_
class wxRegion : public wxGDIObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxRegion() ;
	/**
	 * \brief Constructs a rectangular region with the given position and size. 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

   wxRegion(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
	/**
	 * \brief Constructs a rectangular region from the top left point and the bottom right point. 
	 * \param const wxPoint&  
	 * \param const wxPoint&  
	*/

   wxRegion(const wxPoint&  topLeft , const wxPoint&  bottomRight ) ;
	/**
	 * \brief Constructs a rectangular region a wxRect object. 
	 * \param const wxRect&  
	*/

   wxRegion(const wxRect&  rect ) ;
	/**
	 * \brief Constructs a region by copying another region. 
	 * \param const wxRegion&  
	*/

   wxRegion(const wxRegion&  region ) ;
	/**
	 * \brief Constructs a region corresponding to the polygon made of   points in the
provided array.   parameter may have values
  or  .

  This constructor is only implemented for Win32 and GTK+ wxWindows ports. 
	 * \param size_t  
	 * \param const wxPoint   
	 * \param int   
	*/

   wxRegion(size_t  n , const wxPoint  *points , int  fillStyle = wxWINDING_RULE) ;
	/**
	 * \brief Constructs a region using the non-transparent pixels of a bitmap.  See
  for more details. 
	 * \param const wxBitmap&  
	 * \param const wxColour&  
	 * \param int  
	*/

   wxRegion(const wxBitmap&  bmp , const wxColour& transColour = wxNullColour, int tolerance = 0) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxRegion() ;
	/**
	 * \brief Clears the current region. 
	*/

  void Clear() ;
	/**
	 * \brief Returns a value indicating whether the given point is contained within the region. 
	 * \param long&   
	 * \param long&   
	*/

  wxRegionContain Contains(long&  x , long&  y ) const;
	/**
	 * \brief Returns a value indicating whether the given point is contained within the region. 
	 * \param const wxPoint&  
	*/

  wxRegionContain Contains(const wxPoint&  pt ) const;
	/**
	 * \brief Returns a value indicating whether the given rectangle is contained within the region. 
	 * \param long&   
	 * \param long&   
	 * \param long&   
	 * \param long&   
	*/

  wxRegionContain Contains(long&  x , long&  y , long&  width , long&  height ) const;
	/**
	 * \brief Returns a value indicating whether the given rectangle is contained within the region. 
	 * \param const wxRect&   
	*/

  wxRegionContain Contains(const wxRect&  rect ) const;
	/**
	 * \brief Convert the region to a black and white bitmap with the white pixels
being inside the region. 
	*/

  wxBitmap ConvertToBitmap() const;
	/**
	 * \brief Returns the outer bounds of the region. 
	 * \param long&   
	 * \param long&   
	 * \param long&   
	 * \param long&   
	*/

  void GetBox(long&  x , long&  y , long&  width , long&  height ) const;
	/**
	 * \brief Returns the outer bounds of the region. 
	*/

  wxRect GetBox() const;
	/**
	 * \brief Finds the intersection of this region and another, rectangular region, specified using position and size. 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  bool Intersect(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
	/**
	 * \brief Finds the intersection of this region and another, rectangular region. 
	 * \param const wxRect&  
	*/

  bool Intersect(const wxRect&  rect ) ;
	/**
	 * \brief Finds the intersection of this region and another region. 
	 * \param const wxRegion&  
	*/

  bool Intersect(const wxRegion&  region ) ;
	/**
	 * \brief Returns   if the region is empty,   otherwise. 
	*/

  bool IsEmpty() const;
	/**
	 * \brief Subtracts a rectangular region from this region. 
	 * \param const wxRect&  
	*/

  bool Subtract(const wxRect&  rect ) ;
	/**
	 * \brief Subtracts a region from this region. 
	 * \param const wxRegion&  
	*/

  bool Subtract(const wxRegion&  region ) ;
	/**
	 * \brief Moves the region by the specified offsets in horizontal and vertical
directions. 
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  bool Offset(wxCoord  x , wxCoord  y ) ;
	/**
	 * \brief Finds the union of this region and another, rectangular region, specified using position and size. 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  bool Union(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
	/**
	 * \brief Finds the union of this region and another, rectangular region. 
	 * \param const wxRect&  
	*/

  bool Union(const wxRect&  rect ) ;
	/**
	 * \brief Finds the union of this region and another region. 
	 * \param const wxRegion&  
	*/

  bool Union(const wxRegion&  region ) ;
	/**
	 * \brief Finds the union of this region and the the non-transparent pixels of a
bitmap.  If the bitmap has a mask then it will be used, otherwise the
colour to be treated as transparent may be specified, along with an
optional colour tolerance value. 
	 * \param const wxBitmap&  
	 * \param const wxColour&  
	 * \param int  
	*/

  bool Union(const wxBitmap&  bmp , const wxColour& transColour = wxNullColour, int tolerance = 0) ;
	/**
	 * \brief Finds the Xor of this region and another, rectangular region, specified using position and size. 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  bool Xor(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
	/**
	 * \brief Finds the Xor of this region and another, rectangular region. 
	 * \param const wxRect&  
	*/

  bool Xor(const wxRect&  rect ) ;
	/**
	 * \brief Finds the Xor of this region and another region. 
	 * \param const wxRegion&  
	*/

  bool Xor(const wxRegion&  region ) ;
};


#endif
