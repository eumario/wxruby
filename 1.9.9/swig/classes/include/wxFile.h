// wxFile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFile_h_)
#define _wxFile_h_
class wxFile
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxFile() ;
	/**
	 * \brief Opens a file with the given mode. As there is no way to return whether the
operation was successful or not from the constructor you should test the
return value of   to check that it didn't
fail. 
	 * \param const char*  
	 * \param wxFile::OpenMode  
	*/

   wxFile(const char*  filename , wxFile::OpenMode mode = wxFile::read) ;
	/**
	 * \brief Associates the file with the given file descriptor, which has already been opened. 
	 * \param int  
	*/

   wxFile(int  fd ) ;
	/**
	 * \brief Destructor will close the file.

  it is not virtual so you should not use wxFile polymorphically. 
	*/

  virtual  ~wxFile() ;
	/**
	 * \brief This function verifies if we may access the given file in specified mode. Only
values of wxFile::read or wxFile::write really make sense here. 
	 * \param const char *  
	 * \param OpenMode  
	*/

  static bool Access(const char *  name , OpenMode  mode ) ;
	/**
	 * \brief Attaches an existing file descriptor to the wxFile object. Example of predefined
file descriptors are 0, 1 and 2 which correspond to stdin, stdout and stderr (and
have symbolic names of  ,   and  ).

The descriptor should be already opened and it will be closed by wxFile
object. 
	 * \param int  
	*/

  void Attach(int  fd ) ;
	/**
	 * \brief Closes the file. 
	*/

  void Close() ;
	/**
	 * \brief Creates a file for writing. If the file already exists, setting   to true
will ensure it is overwritten. 
	 * \param const char*  
	 * \param bool  
	 * \param int   
	*/

  bool Create(const char*  filename , bool overwrite = false, int  access = wxS_DEFAULT) ;
	/**
	 * \brief Get back a file descriptor from wxFile object - the caller is responsible for closing the file if this
descriptor is opened.   will return false after call to Detach(). 
	*/

  void Detach() ;
	/**
	 * \brief Returns the file descriptor associated with the file. 
	*/

  int fd() const;
	/**
	 * \brief Returns true if the end of the file has been reached.

Note that the behaviour of the file pointer based class 
  is different as   
will return true here only if an attempt has been made to read 
  the last byte of the file, while wxFile::Eof() will return true
even before such attempt is made if the file pointer is at the last position
in the file.

Note also that this function doesn't work on unseekable file descriptors
(examples include pipes, terminals and sockets under Unix) and an attempt to
use it will result in an error message in such case. So, to read the entire
file into memory, you should write a loop which uses 
  repeatedly and tests its return condition instead
of using Eof() as this will not work for special files under Unix. 
	*/

  bool Eof() const;
	/**
	 * \brief Returns true if the given name specifies an existing regular file (not a
directory or a link) 
	 * \param const char*  
	*/

  static bool Exists(const char*  filename ) ;
	/**
	 * \brief Flushes the file descriptor.

Note that wxFile::Flush is not implemented on some Windows compilers
due to a missing fsync function, which reduces the usefulness of this function
(it can still be called but it will do nothing on unsupported compilers). 
	*/

  bool Flush() ;
	/**
	 * \brief Returns true if the file has been opened. 
	*/

  bool IsOpened() const;
	/**
	 * \brief Returns the length of the file. 
	*/

  off_t Length() const;
	/**
	 * \brief Opens the file, returning true if successful. 
	 * \param const char*  
	 * \param wxFile::OpenMode  
	*/

  bool Open(const char*  filename , wxFile::OpenMode mode = wxFile::read) ;
	/**
	 * \brief Reads the specified number of bytes into a buffer, returning the actual number read. 
	 * \param void*  
	 * \param off_t  
	*/

  off_t Read(void*  buffer , off_t  count ) ;
	/**
	 * \brief Seeks to the specified position. 
	 * \param off_t   
	 * \param wxSeekMode   
	*/

  off_t Seek(off_t  ofs , wxSeekMode  mode = wxFromStart) ;
	/**
	 * \brief Moves the file pointer to the specified number of bytes before the end of the file. 
	 * \param off_t   
	*/

  off_t SeekEnd(off_t  ofs = 0) ;
	/**
	 * \brief Returns the current position or wxInvalidOffset if file is not opened or if another
error occurred. 
	*/

  off_t Tell() const;
	/**
	 * \brief Writes the specified number of bytes from a buffer. 
	 * \param const void*  
	 * \param off_t  
	*/

  size_t Write(const void*  buffer , off_t  count ) ;
	/**
	 * \brief Writes the contents of the string to the file, returns true on success.

The second argument is only meaningful in Unicode build of wxWindows when
  is used to convert   to multibyte representation. 
	 * \param const wxString&   
	 * \param wxMBConv&  
	*/

  bool Write(const wxString&  s , wxMBConv& conv = wxConvUTF8) ;
};


#endif
