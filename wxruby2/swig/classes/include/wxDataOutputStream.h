// wxDataOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDataOutputStream_h_)
#define _wxDataOutputStream_h_
class wxDataOutputStream
{
public:
	/**
	 * \brief  
	 * \param wxOutputStream&  
	*/

   wxDataOutputStream(wxOutputStream&  stream ) ;
	/**
	 * \brief Constructs a datastream object from an output stream. Only write methods will
be available. The second form is only available in Unicode build of wxWindows. 
	 * \param wxOutputStream&  
	 * \param wxMBConv&  
	*/

   wxDataOutputStream(wxOutputStream&  stream , wxMBConv& conv = wxMBConvUTF8) ;
	/**
	 * \brief Destroys the wxDataOutputStream object. 
	*/

  virtual  ~wxDataOutputStream() ;
	/**
	 * \brief If   is true, all data will be written in big-endian
order, e.g. for reading on a Sparc or from Java-Streams (which
always use big-endian order), otherwise data will be written in
little-endian order. 
	 * \param bool  
	*/

  void BigEndianOrdered(bool  be_order ) ;
	/**
	 * \brief Writes the single byte   to the stream. 
	*/

  void Write8() ;
	/**
	 * \brief Writes the 16 bit unsigned integer   to the stream. 
	*/

  void Write16() ;
	/**
	 * \brief Writes the 32 bit unsigned integer   to the stream. 
	*/

  void Write32() ;
	/**
	 * \brief Writes the 64 bit unsigned integer   to the stream. 
	*/

  void Write64() ;
	/**
	 * \brief Writes the double   to the stream using the IEEE format. 
	*/

  void WriteDouble() ;
	/**
	 * \brief Writes   to the stream. Actually, this method writes the size of
the string before writing   itself.

In ANSI build of wxWindows, the string is written to the stream in exactly
same way it is represented in memory. In Unicode build, however, the string
is first converted to multibyte representation with   object passed
to stream's constructor (consequently, ANSI application can read data 
written by Unicode application, as long as they agree on encoding) and this
representation is written to the stream. UTF-8 is used by default. 
	*/

  void WriteString() ;
};


#endif
