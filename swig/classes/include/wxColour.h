// wxColour.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxColour_h_)
#define _wxColour_h_
class wxColour : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxColour() ;
	/**
	 * \brief Constructs a colour from red, green and blue values. 
	 * \param const unsigned char  
	 * \param const unsigned char  
	 * \param const unsigned char  
	*/

   wxColour(const unsigned char  red , const unsigned char  green , const unsigned char  blue ) ;
	/**
	 * \brief Constructs a colour object using a colour name
listed in  . 
	 * \param const wxString&   
	*/

   wxColour(const wxString&  colourNname ) ;
	/**
	 * \brief  
	 * \param const wxColour&  
	*/

   wxColour(const wxColour&  colour ) ;
	/**
	 * \brief Returns the blue intensity. 
	*/

  unsigned char Blue() const;
	/**
	 * \brief Returns a pixel value which is platform-dependent. On Windows, a COLORREF is returned.
On X, an allocated pixel value is returned.

-1 is returned if the pixel is invalid (on X, unallocated). 
	*/

  long GetPixel() const;
	/**
	 * \brief Returns the green intensity. 
	*/

  unsigned char Green() const;
	/**
	 * \brief Returns true if the colour object is valid (the colour has been initialised with RGB values). 
	*/

  bool Ok() const;
	/**
	 * \brief Returns the red intensity. 
	*/

  unsigned char Red() const;
	/**
	 * \brief Sets the RGB intensity values. 
	 * \param const unsigned char  
	 * \param const unsigned char  
	 * \param const unsigned char  
	*/

  void Set(const unsigned char  red , const unsigned char  green , const unsigned char  blue ) ;
};


#endif
