// wxOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxOutputStream_h_)
#define _wxOutputStream_h_
class wxOutputStream : public wxStreamBase
{
public:
	/**
	 * \brief Creates a dummy wxOutputStream object. 
	*/

   wxOutputStream() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxOutputStream() ;
	/**
	 * \brief Returns the number of bytes written during the last Write(). 
	*/

  size_t LastWrite() const;
	/**
	 * \brief Puts the specified character in the output queue and increments the
stream position. 
	 * \param char  
	*/

  void PutC(char  c ) ;
	/**
	 * \brief Changes the stream current position. 
	 * \param off_t  
	 * \param wxSeekMode  
	*/

  off_t SeekO(off_t  pos , wxSeekMode  mode ) ;
	/**
	 * \brief Returns the current stream position. 
	*/

  off_t TellO() const;
	/**
	 * \brief Writes the specified amount of bytes using the data of  . 
  The buffer absolutely needs to have at least the specified size.

This function returns a reference on the current object, so the user can test
any states of the stream right away. 
	 * \param const void *  
	 * \param size_t  
	*/

  wxOutputStream& Write(const void * buffer , size_t  size ) ;
	/**
	 * \brief Reads data from the specified input stream and stores them 
in the current stream. The data is read until an error is raised
by one of the two streams. 
	 * \param wxInputStream&  
	*/

  wxOutputStream& Write(wxInputStream&  stream_in ) ;
};


#endif
