// wxFont.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFont_h_)
#define _wxFont_h_
class wxFont : public wxGDIObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxFont() ;
	/**
	 * \brief Creates a font object (see   for the meaning of the last parameter). 
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param const bool  
	 * \param const wxString&   
	 * \param wxFontEncoding   
	*/

   wxFont(int  pointSize , int  family , int  style , int  weight , const bool underline = false, const wxString&  faceName = wxT(""), wxFontEncoding  encoding = wxFONTENCODING_DEFAULT) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxFont() ;
	/**
	 * \brief Returns   if the font is a fixed width (or monospaced) font, 
  if it is a proportional one or font is invalid. 
	*/

  bool IsFixedWidth() const;
	/**
	 * \brief  
	*/

  static wxFontEncoding GetDefaultEncoding() ;
	/**
	 * \brief Returns the typeface name associated with the font, or the empty string if there is no
typeface information. 
	*/

  wxString GetFaceName() const;
	/**
	 * \brief Gets the font family. See   for a list of valid
family identifiers. 
	*/

  int GetFamily() const;
	/**
	 * \brief Returns the platform-dependent string completely describing this font or an
empty string if the font wasn't constructed using the native font description. 
	*/

  wxString GetNativeFontInfoDesc() const;
	/**
	 * \brief Gets the point size. 
	*/

  int GetPointSize() const;
	/**
	 * \brief Gets the font style. See   for a list of valid
styles. 
	*/

  int GetStyle() const;
	/**
	 * \brief Returns true if the font is underlined, false otherwise. 
	*/

  bool GetUnderlined() const;
	/**
	 * \brief Gets the font weight. See   for a list of valid
weight identifiers. 
	*/

  int GetWeight() const;
	/**
	 * \brief Returns   if this object is a valid font,   otherwise. 
	*/

  bool Ok() const;
	/**
	 * \brief  
	 * \param wxFontEncoding   
	*/

  static void SetDefaultEncoding(wxFontEncoding  encoding ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  void SetFaceName(const wxString&  faceName ) ;
	/**
	 * \brief  
	 * \param int  
	*/

  void SetFamily(int  family ) ;
	/**
	 * \brief Creates the font corresponding to the given native font description string
which must have been previously returned by 
 . If the string is
invalid, font is unchanged. 
	 * \param const wxString&   
	*/

  void SetNativeFontInfo(const wxString&  info ) ;
	/**
	 * \brief Sets the point size. 
	 * \param int  
	*/

  void SetPointSize(int  pointSize ) ;
	/**
	 * \brief Sets the font style. 
	 * \param int  
	*/

  void SetStyle(int  style ) ;
	/**
	 * \brief Sets underlining. 
	 * \param const bool  
	*/

  void SetUnderlined(const bool  underlined ) ;
	/**
	 * \brief Sets the font weight. 
	 * \param int  
	*/

  void SetWeight(int  weight ) ;
};


#endif
