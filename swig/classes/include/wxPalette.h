// wxPalette.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPalette_h_)
#define _wxPalette_h_
class wxPalette : public wxGDIObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxPalette() ;
	/**
	 * \brief Copy constructor. This uses reference counting so is a cheap operation. 
	 * \param const wxPalette&  
	*/

   wxPalette(const wxPalette&  palette ) ;
	/**
	 * \brief Creates a palette from arrays of size  , one for each
red, blue or green component. 
	 * \param int  
	 * \param const unsigned char*   
	 * \param const unsigned char*   
	 * \param const unsigned char*   
	*/

   wxPalette(int  n , const unsigned char*  red , const unsigned char*  green , const unsigned char*  blue ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxPalette() ;
	/**
	 * \brief Creates a palette from arrays of size  , one for each
red, blue or green component. 
	 * \param int  
	 * \param const unsigned char*   
	 * \param const unsigned char*   
	 * \param const unsigned char*   
	*/

  bool Create(int  n , const unsigned char*  red , const unsigned char*  green , const unsigned char*  blue ) ;
	/**
	 * \brief Returns a pixel value (index into the palette) for the given RGB values. 
	 * \param const unsigned char   
	 * \param const unsigned char   
	 * \param const unsigned char   
	*/

  int GetPixel(const unsigned char  red , const unsigned char  green , const unsigned char  blue ) const;
	/**
	 * \brief Returns RGB values for a given palette index. 
	 * \param int  
	 * \param const unsigned char*   
	 * \param const unsigned char*   
	 * \param const unsigned char*   
	*/

  bool GetRGB(int  pixel , const unsigned char*  red , const unsigned char*  green , const unsigned char*  blue ) const;
	/**
	 * \brief Returns true if palette data is present. 
	*/

  bool Ok() const;
};


#endif
