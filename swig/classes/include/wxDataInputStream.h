// wxDataInputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDataInputStream_h_)
#define _wxDataInputStream_h_
class wxDataInputStream
{
public:
	/**
	 * \brief  
	 * \param wxInputStream&  
	*/

   wxDataInputStream(wxInputStream&  stream ) ;
	/**
	 * \brief Constructs a datastream object from an input stream. Only read methods will
be available. The second form is only available in Unicode build of wxWindows. 
	 * \param wxInputStream&  
	 * \param wxMBConv&  
	*/

   wxDataInputStream(wxInputStream&  stream , wxMBConv& conv = wxMBConvUTF8) ;
	/**
	 * \brief Destroys the wxDataInputStream object. 
	*/

  virtual  ~wxDataInputStream() ;
	/**
	 * \brief If   is true, all data will be read in big-endian
order, such as written by programs on a big endian architecture 
(e.g. Sparc) or written by Java-Streams (which always use 
big-endian order). 
	 * \param bool  
	*/

  void BigEndianOrdered(bool  be_order ) ;
	/**
	 * \brief Reads a single byte from the stream. 
	*/

  wxUint8 Read8() ;
	/**
	 * \brief Reads a 16 bit unsigned integer from the stream. 
	*/

  wxUint16 Read16() ;
	/**
	 * \brief Reads a 32 bit unsigned integer from the stream. 
	*/

  wxUint32 Read32() ;
	/**
	 * \brief Reads a 64 bit unsigned integer from the stream. 
	*/

  wxUint64 Read64() ;
	/**
	 * \brief Reads a double (IEEE encoded) from the stream. 
	*/

  double ReadDouble() ;
	/**
	 * \brief Reads a string from a stream. Actually, this function first reads a long 
integer specifying the length of the string (without the last null character) 
and then reads the string.

In Unicode build of wxWindows, the fuction first reads multibyte (char&#42;)
string from the stream and then converts it to Unicode using the  
object passed to constructor and returns the result as wxString. You are
responsible for using the same convertor as when writing the stream.

See also  . 
	*/

  wxString ReadString() ;
};


#endif
