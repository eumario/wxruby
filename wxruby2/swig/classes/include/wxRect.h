// wxRect.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxRect_h_)
#define _wxRect_h_
class wxRect
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxRect() ;
	/**
	 * \brief Creates a wxRect object from x, y, width and height values. 
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	*/

   wxRect(int  x , int  y , int  width , int  height ) ;
	/**
	 * \brief Creates a wxRect object from top-left and bottom-right points. 
	 * \param const wxPoint&  
	 * \param const wxPoint&  
	*/

   wxRect(const wxPoint&  topLeft , const wxPoint&  bottomRight ) ;
	/**
	 * \brief Creates a wxRect object from position and size values. 
	 * \param const wxPoint&  
	 * \param const wxSize&  
	*/

   wxRect(const wxPoint&  pos , const wxSize&  size ) ;
	/**
	 * \brief  
	 * \param wxCoord   
	 * \param wxCoord   
	*/

  void Deflate(wxCoord  dx , wxCoord  dy ) ;
	/**
	 * \brief  
	 * \param wxCoord   
	*/

  void Deflate(wxCoord  diff ) ;
	/**
	 * \brief Decrease the rectangle size by   in x direction and   in y
direction. Both (or one of) parameters may be negative to increase the
rectngle size. This method is the opposite of  .

The second form uses the same   for both   and  .

The first two versions modify the rectangle in place, the last one returns a
new rectangle leaving this one unchanged. 
	 * \param wxCoord   
	 * \param wxCoord   
	*/

  wxRect Deflate(wxCoord  dx , wxCoord  dy ) const;
	/**
	 * \brief Gets the bottom point of the rectangle. 
	*/

  int GetBottom() const;
	/**
	 * \brief Gets the height member. 
	*/

  int GetHeight() const;
	/**
	 * \brief Gets the left point of the rectangle (the same as  ). 
	*/

  int GetLeft() const;
	/**
	 * \brief Gets the position. 
	*/

  wxPoint GetPosition() const;
	/**
	 * \brief Gets the right point of the rectangle. 
	*/

  int GetRight() const;
	/**
	 * \brief Gets the size. 
	*/

  wxSize GetSize() const;
	/**
	 * \brief Gets the top point of the rectangle (the same as  ). 
	*/

  int GetTop() const;
	/**
	 * \brief Gets the width member. 
	*/

  int GetWidth() const;
	/**
	 * \brief Gets the x member. 
	*/

  int GetX() const;
	/**
	 * \brief Gets the y member. 
	*/

  int GetY() const;
	/**
	 * \brief  
	 * \param wxCoord   
	 * \param wxCoord   
	*/

  void Inflate(wxCoord  dx , wxCoord  dy ) ;
	/**
	 * \brief  
	 * \param wxCoord   
	*/

  void Inflate(wxCoord  diff ) ;
	/**
	 * \brief Increase the rectangle size by   in x direction and   in y
direction. Both (or one of) parameters may be negative to decrease the
rectangle size.

The second form uses the same   for both   and  .

The first two versions modify the rectangle in place, the last one returns a
new rectangle leaving this one unchanged. 
	 * \param wxCoord   
	 * \param wxCoord   
	*/

  wxRect Inflate(wxCoord  dx , wxCoord  dy ) const;
	/**
	 * \brief  
	 * \param wxCoord   
	 * \param wxCoord   
	*/

  void Offset(wxCoord  dx , wxCoord  dy ) ;
	/**
	 * \brief Moves the rectangle by the specified offset. If   is positive, the
rectangle is moved to the right, if   is positive, it is moved to the
bottom, otherwise it is moved to the left or top respectively. 
	 * \param const wxPoint&   
	*/

  void Offset(const wxPoint&  pt ) ;
	/**
	 * \brief Sets the height. 
	 * \param int  
	*/

  void SetHeight(int  height ) ;
	/**
	 * \brief Sets the width. 
	 * \param int  
	*/

  void SetWidth(int  width ) ;
	/**
	 * \brief Sets the x position. 
	 * \param int  
	*/

  void SetX(int  x ) ;
	/**
	 * \brief Sets the y position. 
	 * \param int  
	*/

  void SetY(int  y ) ;

  // Missing from XML
  int x, y;
  int width, height;
};


#endif
