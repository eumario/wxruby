// wxTextInputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextInputStream_h_)
#define _wxTextInputStream_h_
class wxTextInputStream
{
public:
	/**
	 * \brief Constructs a text stream object from an input stream. Only read methods will
be available. 
	 * \param wxInputStream&  
	*/

   wxTextInputStream(wxInputStream&  stream ) ;
	/**
	 * \brief Destroys the wxTextInputStream object. 
	*/

  virtual  ~wxTextInputStream() ;
	/**
	 * \brief Reads a single byte from the stream. 
	*/

  wxUint8 Read8() ;
	/**
	 * \brief Reads a 16 bit integer from the stream. 
	*/

  wxUint16 Read16() ;
	/**
	 * \brief Reads a 32 bit integer from the stream. 
	*/

  wxUint32 Read32() ;
	/**
	 * \brief Reads a double (IEEE encoded) from the stream. 
	*/

  double ReadDouble() ;
	/**
	 * \brief Reads a line from the input stream and returns it (without the end of line
character). 
	*/

  wxString ReadLine() ;
	/**
	 * \brief This method is deprecated, use   
or   instead.

Same as  . 
	*/

  wxString ReadString() ;
	/**
	 * \brief Reads a word (a sequence of characters until the next separator) from the
input stream. 
	*/

  wxString ReadWord() ;
	/**
	 * \brief Sets the characters which are used to define the word boundaries in 
 .

The default separators are the space and   characters. 
	 * \param const wxString&   
	*/

  void SetStringSeparators(const wxString&  sep ) ;
};


#endif
