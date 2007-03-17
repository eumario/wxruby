// wxBrush.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBrush_h_)
#define _wxBrush_h_
class wxBrush : public wxGDIObject
{
public:
	/**
	 * \brief Default constructor. The brush will be uninitialised, and   will
return false. 
	*/

   wxBrush() ;
	/**
	 * \brief Constructs a brush from a colour object and style. 
	 * \param const wxColour&  
	 * \param int  
	*/

   wxBrush(const wxColour&  colour , int  style ) ;
	/**
	 * \brief Constructs a brush from a colour name and style. 
	 * \param const wxString&   
	 * \param int  
	*/

   wxBrush(const wxString&  colourName , int  style ) ;
	/**
	 * \brief Constructs a stippled brush using a bitmap. 
	 * \param const wxBitmap&   
	*/

   wxBrush(const wxBitmap&  stippleBitmap ) ;
	/**
	 * \brief  
	 * \param const wxBrush&  
	*/

   wxBrush(const wxBrush&  brush ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxBrush() ;
	/**
	 * \brief Returns a reference to the brush colour. 
	*/

  wxColour& GetColour() const;
	/**
	 * \brief Gets a pointer to the stipple bitmap. If the brush does not have a wxSTIPPLE style,
this bitmap may be non-NULL but uninitialised (  returns false). 
	*/

  wxBitmap * GetStipple() const;
	/**
	 * \brief  
	*/

  int GetStyle() const;
	/**
	 * \brief Returns true if the brush is initialised. It will return false if the default
constructor has been used (for example, the brush is a member of a class, or
NULL has been assigned to it). 
	*/

  bool Ok() const;
	/**
	 * \brief Sets the brush colour using a reference to a colour object. 
	 * \param wxColour&   
	*/

  void SetColour(wxColour&  colour ) ;
	/**
	 * \brief Sets the brush colour using a colour name from the colour database. 
	 * \param const wxString&   
	*/

  void SetColour(const wxString&  colourName ) ;
	/**
	 * \brief Sets the brush colour using red, green and blue values. 
	 * \param const unsigned char  
	 * \param const unsigned char  
	 * \param const unsigned char  
	*/

  void SetColour(const unsigned char  red , const unsigned char  green , const unsigned char  blue ) ;
	/**
	 * \brief Sets the stipple bitmap. 
	 * \param const wxBitmap&  
	*/

  void SetStipple(const wxBitmap&  bitmap ) ;
	/**
	 * \brief Sets the brush style. 
	 * \param int  
	*/

  void SetStyle(int  style ) ;
};


#endif
