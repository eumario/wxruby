// wxTextOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextOutputStream_h_)
#define _wxTextOutputStream_h_
class wxTextOutputStream
{
public:
	/**
	 * \brief Constructs a text stream object from an output stream. Only write methods will
be available. 
	 * \param wxOutputStream&  
	 * \param wxEOL  
	*/

   wxTextOutputStream(wxOutputStream&  stream , wxEOL mode = wxEOL_NATIVE) ;
	/**
	 * \brief Destroys the wxTextOutputStream object. 
	*/

  virtual  ~wxTextOutputStream() ;
	/**
	 * \brief Returns the end-of-line mode. One of  ,   and  . 
	*/

  wxEOL GetMode() ;
	/**
	 * \brief Set the end-of-line mode. One of  ,  ,   and  . 
	*/

  void SetMode() ;
	/**
	 * \brief Writes the single byte   to the stream. 
	*/

  void Write8() ;
	/**
	 * \brief Writes the 16 bit integer   to the stream. 
	*/

  void Write16() ;
	/**
	 * \brief Writes the 32 bit integer   to the stream. 
	*/

  void Write32() ;
	/**
	 * \brief Writes the double   to the stream using the IEEE format. 
	*/

  virtual void WriteDouble() ;
	/**
	 * \brief Writes   as a line. Depending on the end-of-line mode the end of
line ('$\backslash$n') characters in the string are converted to the correct
line ending terminator. 
	*/

  virtual void WriteString() ;
};


#endif
