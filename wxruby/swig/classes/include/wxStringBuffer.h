// wxStringBuffer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStringBuffer_h_)
#define _wxStringBuffer_h_
class wxStringBuffer
{
public:
	/**
	 * \brief Constructs a writable string buffer object associated with the given string
and containing enough space for at least   characters. Basically, this
is equivalent to calling   and
saving the result. 
	 * \param const wxString&   
	 * \param size_t   
	*/

   wxStringBuffer(const wxString&  str , size_t  len ) ;
	/**
	 * \brief Restores the string passed to the constructor to the usable state by calling 
  on it. 
	*/

  virtual  ~wxStringBuffer() ;
};


#endif
