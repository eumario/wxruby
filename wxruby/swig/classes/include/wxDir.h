// wxDir.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDir_h_)
#define _wxDir_h_
class wxDir
{
public:
	/**
	 * \brief Default constructor, use   afterwards. 
	*/

   wxDir() ;
	/**
	 * \brief Opens the directory for enumeration, use   
to test for errors. 
	 * \param const wxString&   
	*/

   wxDir(const wxString&  dir ) ;
	/**
	 * \brief Destructor cleans up the associated resources. It is not virtual and so this
class is not meant to be used polymorphically. 
	*/

  virtual  ~wxDir() ;
	/**
	 * \brief Test for existence of a directory with the given name 
	 * \param const wxString&   
	*/

  static bool Exists(const wxString&  dir ) ;
	/**
	 * \brief The function appends the names of all the files under directory   
to the array   (note that its old contents is preserved). Only files
matching the   are taken, with empty spec matching all the files.

The   parameter should always include   or the array
would be unchanged and should include   flag to recurse into
subdirectories (both flags are included in the value by default).

See also: 
	 * \param const wxString&   
	 * \param wxArrayString *  
	 * \param const wxString&   
	 * \param int   
	*/

  static size_t GetAllFiles(const wxString&  dirname , wxArrayString * files , const wxString&  filespec = wxEmptyString, int  flags = wxDIR_DEFAULT) ;
	/**
	 * \brief Start enumerating all files matching   (or all files if it is
empty) and flags, return true on success. 
	 * \param wxString*   
	 * \param const wxString&   
	 * \param int   
	*/

  bool GetFirst(wxString*  filename , const wxString&  filespec = wxEmptyString, int  flags = wxDIR_DEFAULT) const;
	/**
	 * \brief Returns the name of the directory itself. The returned string does not have the
trailing path separator (slash or backslash). 
	*/

  wxString GetName() const;
	/**
	 * \brief Continue enumerating files satisfying the criteria specified by the last call
to  . 
	 * \param wxString*   
	*/

  bool GetNext(wxString*  filename ) const;
	/**
	 * \brief Returns   if the directory contains any files matching the given 
 . If   is empty, look for any files at all. In any
case, even hidden files are taken into account. 
	 * \param const wxString&   
	*/

  bool HasFiles(const wxString&  filespec = wxEmptyString) ;
	/**
	 * \brief Returns   if the directory contains any subdirectories (if a non
empty   is given, only check for directories matching it).
The hidden subdirectories are taken into account as well. 
	 * \param const wxString&   
	*/

  bool HasSubDirs(const wxString&  dirspec = wxEmptyString) ;
	/**
	 * \brief Returns true if the directory was successfully opened by a previous call to 
 . 
	*/

  bool IsOpened() const;
	/**
	 * \brief Open the directory for enumerating, returns true on success or false if an
error occurred. 
	 * \param const wxString&   
	*/

  bool Open(const wxString&  dir ) ;
	/**
	 * \brief Enumerate all files and directories under the given directory recursively
calling the element of the provided   
object for each of them.

More precisely, the function will really recurse into subdirectories if 
  contains   flag. It will ignore the files (but
still possibly recurse into subdirectories) if   flag is
given.

For each found directory,   is called
and   is called for every file.
Depending on the return value, the enumeration may continue or stop.

The function returns the total number of files found or   on
error.

See also: 
	 * \param wxDirTraverser&   
	 * \param const wxString&   
	 * \param int   
	*/

  size_t Traverse(wxDirTraverser&  sink , const wxString&  filespec = wxEmptyString, int  flags = wxDIR_DEFAULT) ;
};


#endif
