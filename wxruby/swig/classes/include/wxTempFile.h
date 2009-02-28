// wxTempFile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTempFile_h_)
#define _wxTempFile_h_
class wxTempFile
{
public:
	/**
	 * \brief Default constructor -   must be used to open the
file. 
	*/

   wxTempFile() ;
	/**
	 * \brief Associates wxTempFile with the file to be replaced and opens it. You should use 
  to verify if the constructor succeeded. 
	 * \param const wxString&   
	*/

   wxTempFile(const wxString&  strName ) ;
	/**
	 * \brief Open the temporary file, returns   on success,   if an error
occurred.

  is the name of file to be replaced. The temporary file is always
created in the directory where   is. In particular, if 
  doesn't include the path, it is created in the current directory
and the program should have write access to it for the function to succeed. 
	 * \param const wxString&   
	*/

  bool Open(const wxString&  strName ) ;
	/**
	 * \brief Returns   if the file was successfully opened. 
	*/

  bool IsOpened() const;
	/**
	 * \brief Write to the file, return   on success,   on failure. 
	 * \param const void   
	 * \param size_t   
	*/

  bool Write(const void  *p , size_t  n ) ;
	/**
	 * \brief Write to the file, return   on success,   on failure.

The second argument is only meaningful in Unicode build of wxWindows when
  is used to convert   to multibyte representation. 
	 * \param const wxString&   
	 * \param wxMBConv&  
	*/

  bool Write(const wxString&  str , wxMBConv& conv = wxConvLibc) ;
	/**
	 * \brief Validate changes: deletes the old file of name m_strName and renames the new
file to the old name. Returns   if both actions succeeded. If   is
returned it may unfortunately mean two quite different things: either that
either the old file couldn't be deleted or that the new file couldn't be renamed
to the old name. 
	*/

  bool Commit() ;
	/**
	 * \brief Discard changes: the old file contents is not changed, temporary file is
deleted. 
	*/

  void Discard() ;
	/**
	 * \brief Destructor calls   if temporary file
is still opened. 
	*/

  virtual  ~wxTempFile() ;
};


#endif
