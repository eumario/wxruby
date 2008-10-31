// wxStreamBase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStreamBase_h_)
#define _wxStreamBase_h_
class wxStreamBase
{
public:
	/**
	 * \brief Creates a dummy stream object. It doesn't do anything. 
	*/

   wxStreamBase() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxStreamBase() ;
	/**
	 * \brief Returns true if no error occurred on the stream. 
	*/

  wxStreamError IsOk() const;
	/**
	 * \brief This function returns the last error.

\twocolwidtha{5cm} 
	*/

  wxStreamError LastError() const;
	/**
	 * \brief Internal function. It is called when the stream wants to read data of the
specified size. It should return the size that was actually read. 
	 * \param void*  
	 * \param size_t  
	*/

  virtual size_t OnSysRead(void*  buffer , size_t  bufsize ) ;
	/**
	 * \brief Internal function. It is called when the stream needs to change the
current position. 
	 * \param off_t  
	 * \param wxSeekMode  
	*/

  virtual off_t OnSysSeek(off_t  pos , wxSeekMode  mode ) ;
	/**
	 * \brief Internal function. Is is called when the stream needs to know the
real position. 
	*/

  virtual off_t OnSysTell() const;
	/**
	 * \brief See  . 
	 * \param void *  
	 * \param size_t  
	*/

  virtual size_t OnSysWrite(void * buffer , size_t  bufsize ) ;
	/**
	 * \brief This function returns the size of the stream. For example, for a file it is the size of
the file.

\wxheading{Warning}

There are streams which do not have size by definition, such as socket streams.
In that cases, GetSize returns an invalid size represented by 
	*/

  size_t GetSize() const;
};


#endif
