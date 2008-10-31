// wxMBConv.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMBConv_h_)
#define _wxMBConv_h_
class wxMBConv
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxMBConv() ;
	/**
	 * \brief Converts from a string   in multibyte encoding to Unicode putting the
output into the buffer   of the size   (in wide characters, not
bytes). If   is  , nothing is written to it but the length of
the string which would result from the conversion is calculated and returned.
Note that this is the length and not size, i.e. the returned value does 
  include the trailing NUL. But when the function is called with a
non-  buffer, the   parameter should be the size of the buffer
and so it   take into account the trailing NUL. 
	 * \param wchar_t*   
	 * \param const char*   
	 * \param size_t   
	*/

  virtual size_t MB2WC(wchar_t*  buf , const char*  psz , size_t  n ) const;
	/**
	 * \brief Converts from Unicode to multibyte encoding. The semantics of this function
(including the return value meaning) is the same as for 
 . 
	 * \param char*   
	 * \param const wchar_t*   
	 * \param size_t   
	*/

  virtual size_t WC2MB(char*  buf , const wchar_t*  psz , size_t  n ) const;
	/**
	 * \brief Converts from multibyte encoding to Unicode by calling MB2WC,
allocating a temporary wxWCharBuffer to hold the result. 
	 * \param const char*   
	*/

  const wxWCharBuffer cMB2WC(const char*  psz ) const;
	/**
	 * \brief Converts from Unicode to multibyte encoding by calling WC2MB,
allocating a temporary wxCharBuffer to hold the result. 
	 * \param const wchar_t*   
	*/

  const wxCharBuffer cWC2MB(const wchar_t*  psz ) const;
	/**
	 * \brief  
	 * \param const char*   
	*/

  const char* cMB2WX(const char*  psz ) const;
	/**
	 * \brief Converts from multibyte encoding to the current wxChar type
(which depends on whether wxUSE_UNICODE is set to 1). If wxChar is char,
it returns the parameter unaltered. If wxChar is wchar_t, it returns the
result in a wxWCharBuffer. The macro wxMB2WXbuf is defined as the correct
return type (without const). 
	 * \param const char*   
	*/

  const wxWCharBuffer cMB2WX(const char*  psz ) const;
	/**
	 * \brief  
	 * \param const wxChar*   
	*/

  const char* cWX2MB(const wxChar*  psz ) const;
	/**
	 * \brief Converts from the current wxChar type to multibyte encoding. If wxChar is char,
it returns the parameter unaltered. If wxChar is wchar_t, it returns the
result in a wxCharBuffer. The macro wxWX2MBbuf is defined as the correct
return type (without const). 
	 * \param const wxChar*   
	*/

  const wxCharBuffer cWX2MB(const wxChar*  psz ) const;
	/**
	 * \brief  
	 * \param const wchar_t*   
	*/

  const wchar_t* cWC2WX(const wchar_t*  psz ) const;
	/**
	 * \brief Converts from Unicode to the current wxChar type. If wxChar is wchar_t,
it returns the parameter unaltered. If wxChar is char, it returns the
result in a wxCharBuffer. The macro wxWC2WXbuf is defined as the correct
return type (without const). 
	 * \param const wchar_t*   
	*/

  const wxCharBuffer cWC2WX(const wchar_t*  psz ) const;
	/**
	 * \brief  
	 * \param const wxChar*   
	*/

  const wchar_t* cWX2WC(const wxChar*  psz ) const;
	/**
	 * \brief Converts from the current wxChar type to Unicode. If wxChar is wchar_t,
it returns the parameter unaltered. If wxChar is char, it returns the
result in a wxWCharBuffer. The macro wxWX2WCbuf is defined as the correct
return type (without const). 
	 * \param const wxChar*   
	*/

  const wxWCharBuffer cWX2WC(const wxChar*  psz ) const;
};


#endif
