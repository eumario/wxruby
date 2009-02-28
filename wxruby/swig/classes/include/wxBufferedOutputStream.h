// wxBufferedOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBufferedOutputStream_h_)
#define _wxBufferedOutputStream_h_
class wxBufferedOutputStream : public wxFilterOutputStream
{
public:
	/**
	 * \brief Creates a buffered stream using a buffer of a default size of 1024 bytes for cashing
the stream  . 
	 * \param const wxOutputStream&  
	*/

   wxBufferedOutputStream(const wxOutputStream&  parent ) ;
	/**
	 * \brief Destructor. Calls Sync() and destroys the internal buffer. 
	*/

  virtual  ~wxBufferedOutputStream() ;
	/**
	 * \brief Calls Sync() and changes the stream position. 
	 * \param off_t  
	 * \param wxSeekMode  
	*/

  off_t SeekO(off_t  pos , wxSeekMode  mode ) ;
	/**
	 * \brief Flushes the buffer and calls Sync() on the parent stream. 
	*/

  void Sync() ;
};


#endif
