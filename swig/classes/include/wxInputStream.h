// wxInputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxInputStream_h_)
#define _wxInputStream_h_
class wxInputStream : public wxStreamBase
{
public:
	/**
	 * \brief Creates a dummy input stream. 
	*/

   wxInputStream() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxInputStream() ;
	/**
	 * \brief Returns the first character in the input queue and removes it. 
	*/

  char GetC() ;
	/**
	 * \brief Returns true if the end of stream has been reached. 
	*/

  wxInputStream Eof() const;
	/**
	 * \brief Returns the last number of bytes read. 
	*/

  size_t LastRead() const;
	/**
	 * \brief Returns the first character in the input queue without removing it. 
	*/

  char Peek() ;
	/**
	 * \brief Reads the specified amount of bytes and stores the data in  .

\wxheading{Warning}

The buffer absolutely needs to have at least the specified size. 
	 * \param void *  
	 * \param size_t  
	*/

  wxInputStream& Read(void * buffer , size_t  size ) ;
	/**
	 * \brief Reads data from the input queue and stores it in the specified output stream.
The data is read until an error is raised by one of the two streams. 
	 * \param wxOutputStream&  
	*/

  wxInputStream& Read(wxOutputStream&  stream_out ) ;
	/**
	 * \brief Changes the stream current position. 
	 * \param off_t  
	 * \param wxSeekMode  
	*/

  off_t SeekI(off_t  pos , wxSeekMode mode = wxFromStart) ;
	/**
	 * \brief Returns the current stream position. 
	*/

  off_t TellI() const;
	/**
	 * \brief This function is only useful in   mode. It is the manager of the &quot;Write-Back&quot;
buffer. This buffer acts like a temporary buffer where data which has to be
read during the next read IO call are put. This is useful when you get a big
block of data which you didn't want to read: you can replace them at the top
of the input queue by this way.

Be very careful about this call in connection with calling SeekI() on the same
stream. Any call to SeekI() will invalidate any previous call to this method
(otherwise you could SeekI() to one position, &quot;unread&quot; a few bytes there, SeekI()
to another position and data would be either lost or corrupted). 
	 * \param const char*  
	 * \param size_t  
	*/

  size_t Ungetch(const char*  buffer , size_t  size ) ;
	/**
	 * \brief This function acts like the previous one except that it takes only one
character: it is sometimes shorter to use than the generic function. 
	 * \param char   
	*/

  bool Ungetch(char  c ) ;
};


#endif
