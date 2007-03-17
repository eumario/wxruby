// wxCSConv.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCSConv_h_)
#define _wxCSConv_h_
class wxCSConv : public wxMBConv
{
public:
	/**
	 * \brief Constructor. Specify the name of the character set you want to convert
from/to. 
	 * \param const wxChar*   
	*/

   wxCSConv(const wxChar*  charset ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxCSConv() ;
	/**
	 * \brief If the conversion tables needs to be loaded from disk, this method
will do so. Otherwise, they will be loaded when any of the conversion
methods are called. 
	*/

  void LoadNow() ;
	/**
	 * \brief Converts from the selected character set to Unicode. Returns the size of the destination buffer. 
	 * \param wchar_t*   
	 * \param const char*   
	 * \param size_t   
	*/

  size_t MB2WC(wchar_t*  buf , const char*  psz , size_t  n ) const;
	/**
	 * \brief Converts from Unicode to the selected character set. Returns the size of the destination buffer. 
	 * \param char*   
	 * \param const wchar_t*   
	 * \param size_t   
	*/

  size_t WC2MB(char*  buf , const wchar_t*  psz , size_t  n ) const;
};


#endif
