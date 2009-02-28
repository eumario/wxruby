// wxEncodingConverter.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxEncodingConverter_h_)
#define _wxEncodingConverter_h_
class wxEncodingConverter : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxEncodingConverter() ;
	/**
	 * \brief Initialize conversion. Both output or input encoding may
be wxFONTENCODING_UNICODE, but only if wxUSE_ENCODING is set to 1.
All subsequent calls to   
will interpret its argument
as a string in   encoding and will output string in 
  encoding.
You must call this method before calling Convert. You may call 
it more than once in order to switch to another conversion.
  affects behaviour of Convert() in case input character
cannot be converted because it does not exist in output encoding:

 

Both modes guarantee that output string will have same length
as input string. 
	 * \param wxFontEncoding   
	 * \param wxFontEncoding   
	 * \param int   
	*/

  bool Init(wxFontEncoding  input_enc , wxFontEncoding  output_enc , int  method = wxCONVERT_STRICT) ;
	/**
	 * \brief  
	 * \param const char*   
	 * \param char*   
	*/

  void Convert(const char*  input , char*  output ) ;
	/**
	 * \brief  
	 * \param const wchar_t*   
	 * \param wchar_t*   
	*/

  void Convert(const wchar_t*  input , wchar_t*  output ) ;
	/**
	 * \brief  
	 * \param const char*   
	 * \param wchar_t*   
	*/

  void Convert(const char*  input , wchar_t*  output ) ;
	/**
	 * \brief Convert input string according to settings passed to
  and writes the result to  . 
	 * \param const wchar_t*   
	 * \param char*   
	*/

  void Convert(const wchar_t*  input , char*  output ) ;
	/**
	 * \brief  
	 * \param char*   
	*/

  void Convert(char*  str ) ;
	/**
	 * \brief Convert input string according to settings passed to
  in-place, i.e. write the result to the
same memory area. 
	 * \param wchar_t*   
	*/

  void Convert(wchar_t*  str ) ;
	/**
	 * \brief Convert wxString and return new wxString object. 
	 * \param const wxString&   
	*/

  wxString Convert(const wxString&  input ) ;
	/**
	 * \brief Return equivalents for given font that are used
under given platform. Supported platforms:

 

wxPLATFORM_CURRENT means the platform this binary was compiled for.

Examples:

 

Equivalence is defined in terms of convertibility:
two encodings are equivalent if you can convert text between
then without losing information (it may - and will - happen
that you lose special chars like quotation marks or em-dashes
but you shouldn't lose any diacritics and language-specific
characters when converting between equivalent encodings).

Remember that this function does   check for presence of
fonts in system. It only tells you what are most suitable
encodings. (It usually returns only one encoding.) 
	 * \param wxFontEncoding   
	 * \param int   
	*/

  static wxFontEncodingArray GetPlatformEquivalents(wxFontEncoding  enc , int  platform = wxPLATFORM_CURRENT) ;
	/**
	 * \brief Similar to 
 , 
but this one will return ALL 
equivalent encodings, regardless of the platform, and including itself.

This platform's encodings are before others in the array. And again, if   is in the array,
it is the very first item in it. 
	 * \param wxFontEncoding   
	*/

  static wxFontEncodingArray GetAllEquivalents(wxFontEncoding  enc ) ;
};


#endif
