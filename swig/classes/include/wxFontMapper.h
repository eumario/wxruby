// wxFontMapper.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFontMapper_h_)
#define _wxFontMapper_h_
class wxFontMapper
{
public:
	/**
	 * \brief Default ctor. 
	*/

   wxFontMapper() ;
	/**
	 * \brief Virtual dtor for a base class. 
	*/

  virtual  ~wxFontMapper() ;
	/**
	 * \brief Get the current font mapper object. If there is no current object, creates
one. 
	*/

  static wxFontMapper * Get() ;
	/**
	 * \brief  
	 * \param wxFontEncoding   
	 * \param wxNativeEncodingInfo*   
	 * \param const wxString&   
	 * \param bool   
	*/

  bool GetAltForEncoding(wxFontEncoding  encoding , wxNativeEncodingInfo*  info , const wxString&  facename = wxEmptyString, bool  interactive = true) ;
	/**
	 * \brief Find an alternative for the given encoding (which is supposed to not be
available on this system). If successful, return true and fill info
structure with the parameters required to create the font, otherwise
return false.

The first form is for wxWindows' internal use while the second one
is better suitable for general use -- it returns wxFontEncoding which
can consequently be passed to wxFont constructor. 
	 * \param wxFontEncoding   
	 * \param wxFontEncoding*   
	 * \param const wxString&   
	 * \param bool   
	*/

  bool GetAltForEncoding(wxFontEncoding  encoding , wxFontEncoding*  alt_encoding , const wxString&  facename = wxEmptyString, bool  interactive = true) ;
	/**
	 * \brief Check whether given encoding is available in given face or not.
If no facename is given, find   font in this encoding. 
	 * \param wxFontEncoding   
	 * \param const wxString&   
	*/

  bool IsEncodingAvailable(wxFontEncoding  encoding , const wxString&  facename = wxEmptyString) ;
	/**
	 * \brief Returns the encoding for the given charset (in the form of RFC 2046) or
wxFONTENCODING_SYSTEM if couldn't decode it. 
	 * \param const wxString&   
	 * \param bool   
	*/

  wxFontEncoding CharsetToEncoding(const wxString&  charset , bool  interactive = true) ;
	/**
	 * \brief Returns the  -th supported encoding. Together with 
  
this method may be used to get all supported encodings. 
	 * \param size_t   
	*/

  static wxFontEncoding GetEncoding(size_t  n ) ;
	/**
	 * \brief Return internal string identifier for the encoding (see also 
 ) 
	 * \param wxFontEncoding   
	*/

  static wxString GetEncodingName(wxFontEncoding  encoding ) ;
	/**
	 * \brief Return user-readable string describing the given encoding. 
	 * \param wxFontEncoding   
	*/

  static wxString GetEncodingDescription(wxFontEncoding  encoding ) ;
	/**
	 * \brief Returns the number of the font encodings supported by this class. Together with 
  this method may be used to get
all supported encodings. 
	*/

  static size_t GetSupportedEncodingsCount() ;
	/**
	 * \brief The parent window for modal dialogs. 
	 * \param wxWindow*   
	*/

  void SetDialogParent(wxWindow*  parent ) ;
	/**
	 * \brief The title for the dialogs (note that default is quite reasonable). 
	 * \param const wxString&   
	*/

  void SetDialogTitle(const wxString&  title ) ;
	/**
	 * \brief Set the current font mapper object and return previous one (may be NULL).
This method is only useful if you want to plug-in an alternative font mapper
into wxWindows. 
	 * \param wxFontMapper *  
	*/

  static wxFontMapper * Set(wxFontMapper * mapper ) ;
	/**
	 * \brief Set the config object to use (may be NULL to use default).

By default, the global one (from wxConfigBase::Get() will be used) 
and the default root path for the config settings is the string returned by
GetDefaultConfigPath(). 
	 * \param wxConfigBase*   
	*/

  void SetConfig(wxConfigBase*  config ) ;
	/**
	 * \brief Set the root config path to use (should be an absolute path). 
	 * \param const wxString&   
	*/

  void SetConfigPath(const wxString&  prefix ) ;
};


#endif
