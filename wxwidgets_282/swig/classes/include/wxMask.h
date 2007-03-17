// wxMask.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMask_h_)
#define _wxMask_h_
class wxMask : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxMask() ;
	/**
	 * \brief Constructs a mask from a monochrome bitmap.

\pythonnote{This is the default constructor for wxMask in wxPython.} 
	 * \param const \helpref{wxBitmap  
	*/

  wxMask(const wxBitmap & wxbitmap );
	/**
	 * \brief Constructs a mask from a bitmap and a colour that indicates the background.

\pythonnote{wxPython has an alternate wxMask constructor matching this
form called  .} 
	 * \param const \helpref{wxBitmap  
	 * \param const \helpref{wxColour  
	*/

  wxMask(const wxBitmap & wxbitmap , const wxColour &wxcolour );
	/**
	 * \brief Constructs a mask from a bitmap and a palette index that indicates the background. Not
yet implemented for GTK. 
	 * \param const wxBitmap&   
	 * \param int  
	*/

   wxMask(const wxBitmap&  bitmap , int  index ) ;
	/**
	 * \brief Destroys the wxMask object and the underlying bitmap data. 
	*/

  virtual  ~wxMask() ;
	/**
	 * \brief Constructs a mask from a monochrome bitmap. 
	 * \param const wxBitmap&   
	*/

  bool Create(const wxBitmap&  bitmap ) ;
	/**
	 * \brief Constructs a mask from a bitmap and a colour that indicates the background. 
	 * \param const wxBitmap&   
	 * \param const wxColour&   
	*/

  bool Create(const wxBitmap&  bitmap , const wxColour&  colour ) ;
	/**
	 * \brief Constructs a mask from a bitmap and a palette index that indicates the background. Not
yet implemented for GTK. 
	 * \param const wxBitmap&   
	 * \param int  
	*/

  bool Create(const wxBitmap&  bitmap , int  index ) ;
};


#endif
