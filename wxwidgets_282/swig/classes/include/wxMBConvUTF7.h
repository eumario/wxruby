// wxMBConvUTF7.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMBConvUTF7_h_)
#define _wxMBConvUTF7_h_
class wxMBConvUTF7 : public wxMBConv
{
public:
	/**
	 * \brief Converts from UTF-7 encoding to Unicode. Returns the size of the destination buffer. 
	 * \param wchar_t*   
	 * \param const char*   
	 * \param size_t   
	*/

  size_t MB2WC(wchar_t*  buf , const char*  psz , size_t  n ) const;
	/**
	 * \brief Converts from Unicode to UTF-7 encoding. Returns the size of the destination buffer. 
	 * \param char*   
	 * \param const wchar_t*   
	 * \param size_t   
	*/

  size_t WC2MB(char*  buf , const wchar_t*  psz , size_t  n ) const;
};


#endif
