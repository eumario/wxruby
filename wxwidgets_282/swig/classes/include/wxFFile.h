// wxFFile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFFile_h_)
#define _wxFFile_h_
class wxFFile
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxFFile() ;
	/**
	 * \brief Opens a file with the given mode. As there is no way to return whether the
operation was successful or not from the constructor you should test the
return value of   to check that it didn't
fail. 
	 * \param const char*  
	 * \param const char*  
	*/

   wxFFile(const char*  filename , const char* mode = "r") ;
	/**
	 * \brief Opens a file with the given file pointer, which has already been opened. 
	 * \param FILE*  
	*/

   wxFFile(FILE*  fp ) ;
	/**
	 * \brief Destructor will close the file.

NB: it is not virtual so you should   derive from wxFFile! 
	*/

  virtual  ~wxFFile() ;
	/**
	 * \brief Attaches an existing file pointer to the wxFFile object.

The descriptor should be already opened and it will be closed by wxFFile
object. 
	 * \param FILE*  
	*/

  void Attach(FILE*  fp ) ;
	/**
	 * \brief Closes the file and returns true on success. 
	*/

  bool Close() ;
	/**
	 * \brief Get back a file pointer from wxFFile object - the caller is responsible for closing the file if this
descriptor is opened.   will return false after call to Detach(). 
	*/

  void Detach() ;
	/**
	 * \brief Returns the file pointer associated with the file. 
	*/

  FILE * fp() const;
	/**
	 * \brief Returns true if the an attempt has been made to read  
the end of the file. 

Note that the behaviour of the file descriptor based class
  is different as  
will return true here as soon as the last byte of the file has been
read. 
	*/

  bool Eof() const;
	/**
	 * \brief Flushes the file and returns true on success. 
	*/

  bool Flush() ;
	/**
	 * \brief Returns true if the file has been opened. 
	*/

  bool IsOpened() const;
	/**
	 * \brief Returns the length of the file. 
	*/

  size_t Length() const;
	/**
	 * \brief Opens the file, returning true if successful. 
	 * \param const char*  
	 * \param const char*  
	*/

  bool Open(const char*  filename , const char* mode = "r") ;
	/**
	 * \brief Reads the specified number of bytes into a buffer, returning the actual number read. 
	 * \param void*  
	 * \param off_t  
	*/

  size_t Read(void*  buffer , off_t  count ) ;
	/**
	 * \brief Seeks to the specified position and returns true on success. 
	 * \param long   
	 * \param wxSeekMode   
	*/

  bool Seek(long  ofs , wxSeekMode  mode = wxFromStart) ;
	/**
	 * \brief Moves the file pointer to the specified number of bytes before the end of the file
and returns true on success. 
	 * \param long   
	*/

  bool SeekEnd(long  ofs = 0) ;
	/**
	 * \brief Returns the current position. 
	*/

  size_t Tell() const;
	/**
	 * \brief Writes the specified number of bytes from a buffer. 
	 * \param const void*  
	 * \param size_t  
	*/

  size_t Write(const void*  buffer , size_t  count ) ;
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
