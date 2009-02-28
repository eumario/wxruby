// wxFontEnumerator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFontEnumerator_h_)
#define _wxFontEnumerator_h_
class wxFontEnumerator
{
public:
	/**
	 * \brief Call   for each font which
supports given encoding (only if it is not wxFONTENCODING_SYSTEM) and is of
fixed width (if   is true).

Calling this function with default arguments will result in enumerating all
fonts available on the system. 
	 * \param wxFontEncoding   
	 * \param bool   
	*/

  virtual bool EnumerateFacenames(wxFontEncoding  encoding = wxFONTENCODING_SYSTEM, bool  fixedWidthOnly = false) ;
	/**
	 * \brief Call   for each
encoding supported by the given font - or for each encoding supported by at
least some font if   is not specified. 
	 * \param const wxString&   
	*/

  virtual bool EnumerateEncodings(const wxString&  font = wxT("")) ;
	/**
	 * \brief Return array of strings containing all encodings found by 
 . This is convenience function. It is 
based on default implementation of   so don't expect
it to work if you overwrite that method. 
	*/

  wxArrayString* GetEncodings() ;
	/**
	 * \brief Return array of strings containing all facenames found by 
 . This is convenience function. It is 
based on default implementation of   so don't expect
it to work if you overwrite that method. 
	*/

  wxArrayString* GetFacenames() ;
	/**
	 * \brief Called by   for
each match. Return true to continue enumeration or false to stop it. 
	 * \param const wxString&   
	*/

  virtual bool OnFacename(const wxString&  font ) ;
	/**
	 * \brief Called by   for
each match. Return true to continue enumeration or false to stop it. 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  virtual bool OnFontEncoding(const wxString&  font , const wxString&  encoding ) ;
};


#endif
