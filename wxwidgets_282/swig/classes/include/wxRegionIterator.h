// wxRegionIterator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxRegionIterator_h_)
#define _wxRegionIterator_h_
class wxRegionIterator : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxRegionIterator() ;
	/**
	 * \brief Creates an iterator object given a region. 
	 * \param const wxRegion&  
	*/

   wxRegionIterator(const wxRegion&  region ) ;
	/**
	 * \brief Returns the x value for the current region. 
	*/

  wxCoord GetX() const;
	/**
	 * \brief Returns the y value for the current region. 
	*/

  wxCoord GetY() const;
	/**
	 * \brief An alias for GetWidth. 
	*/

  wxCoord GetW() const;
	/**
	 * \brief Returns the width value for the current region. 
	*/

  wxCoord GetWidth() const;
	/**
	 * \brief An alias for GetHeight. 
	*/

  wxCoord GetH() const;
	/**
	 * \brief Returns the width value for the current region. 
	*/

  wxCoord GetHeight() const;
	/**
	 * \brief Returns the current rectangle. 
	*/

  wxRect GetRect() const;
	/**
	 * \brief Returns   if there are still some rectangles; otherwise returns  . 
	*/

  bool HaveRects() const;
	/**
	 * \brief Resets the iterator to the beginning of the rectangles. 
	*/

  void Reset() ;
	/**
	 * \brief Resets the iterator to the given region. 
	 * \param const wxRegion&  
	*/

  void Reset(const wxRegion&  region ) ;
};


#endif
