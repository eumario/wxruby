// wxFileName.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileName_h_)
#define _wxFileName_h_
class wxFileName
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxFileName() ;
	/**
	 * \brief Copy constructor. 
	 * \param const wxFileName&   
	*/

   wxFileName(const wxFileName&  filename ) ;
	/**
	 * \brief Constructor taking a full filename. If it terminates with a '/', a directory path
is constructed (the name will be empty), otherwise a file name and
extension are extracted from it. 
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

   wxFileName(const wxString&  fullpath , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Constructor from a directory name and a file name. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

   wxFileName(const wxString&  path , const wxString&  name , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Constructor from a directory name, base file name and extension. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

   wxFileName(const wxString&  path , const wxString&  name , const wxString&  ext , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Constructor from a volume name, a directory name, base file name and extension. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

   wxFileName(const wxString&  volume , const wxString&  path , const wxString&  name , const wxString&  ext , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Appends a directory to the path. 
	 * \param const wxString&   
	*/

  void AppendDir(const wxString&  dir ) ;
	/**
	 * \brief  
	 * \param const wxFileName&   
	*/

  void Assign(const wxFileName&  filepath ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

  void Assign(const wxString&  fullpath , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

  void Assign(const wxString&  volume , const wxString&  path , const wxString&  name , const wxString&  ext , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

  void Assign(const wxString&  path , const wxString&  name , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Creates the file name from various combinations of data. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

  void Assign(const wxString&  path , const wxString&  name , const wxString&  ext , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Makes this object refer to the current working directory on the specified
volume (or current volume if   is empty). 
	 * \param const wxString&   
	*/

  void AssignCwd(const wxString&  volume = wxT("")) ;
	/**
	 * \brief Sets this file name object to the given directory name. The name and extension
will be empty. 
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

  void AssignDir(const wxString&  dir , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Sets this file name object to the home directory. 
	*/

  void AssignHomeDir() ;
	/**
	 * \brief The function calls   to
create a temporary file and sets this object to the name of the file. If a
temporary file couldn't be created, the object is put into the
  state. 
	 * \param const wxString&   
	 * \param wxFile *  
	*/

  void AssignTempFileName(const wxString&  prefix , wxFile * fileTemp = NULL) ;
	/**
	 * \brief Reset all components to default, uninitialized state. 
	*/

  void Clear() ;
	/**
	 * \brief Returns a temporary file name starting with the given  . If
the   is an absolute path, the temporary file is created in this
directory, otherwise it is created in the default system directory for the
temporary files or in the current directory.

If the function succeeds, the temporary file is actually created. If
  is not  , this file will be opened using the name of
the temporary file. When possible, this is done in an atomic way ensuring that
no race condition occurs between the temporary file name generation and opening
it which could often lead to security compromise on the multiuser systems.
If   is  , the file is only created, but not opened.

Under Unix, the temporary file will have read and write permissions for the
owner only to minimize the security problems. 
	 * \param const wxString&   
	 * \param wxFile *  
	*/

  static wxString CreateTempFileName(const wxString&  prefix , wxFile * fileTemp = NULL) ;
	/**
	 * \brief  
	*/

  bool DirExists() const;
	/**
	 * \brief Returns true if the directory with this name exists. 
	 * \param const wxString&   
	*/

  static bool DirExists(const wxString&  dir ) ;
	/**
	 * \brief Returns the directory name. 
	 * \param const wxString&   
	*/

  wxFileName DirName(const wxString&  dir ) ;
	/**
	 * \brief  
	*/

  bool FileExists() const;
	/**
	 * \brief Returns true if the file with this name exists. 
	 * \param const wxString&   
	*/

  static bool FileExists(const wxString&  file ) ;
	/**
	 * \brief Static pseudo constructors. 
	 * \param const wxString&   
	*/

  wxFileName FileName(const wxString&  file ) ;
	/**
	 * \brief Retrieves the value of the current working directory on the specified volume. If
the volume is empty, the programs current working directory is returned for the
current volume. 
	 * \param const wxString&   
	*/

  wxString GetCwd(const wxString&  volume = wxT("")) ;
	/**
	 * \brief Returns the number of directories in the file name. 
	*/

  size_t GetDirCount() const;
	/**
	 * \brief Returns the directories in string array form. 
	*/

  const wxArrayString& GetDirs() const;
	/**
	 * \brief Returns the file name extension. 
	*/

  wxString GetExt() const;
	/**
	 * \brief Returns the canonical path format for this platform. 
	 * \param wxPathFormat   
	*/

  wxPathFormat GetFormat(wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Returns the full name (including extension but excluding directories). 
	*/

  wxString GetFullName() const;
	/**
	 * \brief Returns the full path with name and extension. 
	 * \param wxPathFormat   
	*/

  wxString GetFullPath(wxPathFormat  format = wxPATH_NATIVE) const;
	/**
	 * \brief Returns the home directory. 
	*/

  wxString GetHomeDir() ;
	/**
	 * \brief Return the long form of the path (returns identity on non-Windows platforms) 
	*/

  wxString GetLongPath() const;
	/**
	 * \brief Returns the last time the file was last modified. 
	*/

  wxDateTime GetModificationTime() const;
	/**
	 * \brief Returns the name part of the filename. 
	*/

  wxString GetName() const;
	/**
	 * \brief Returns the path part of the filename (without the name or extension). The
possible flags values are:

\twocolwidtha{5cm} 
	 * \param int   
	 * \param wxPathFormat   
	*/

  wxString GetPath(int  flags = 0, wxPathFormat  format = wxPATH_NATIVE) const;
	/**
	 * \brief Returns the usually used path separator for this format. For all formats but 
  there is only one path separator anyhow, but for DOS there
are two of them and the native one, i.e. the backslash is returned by this
method. 
	 * \param wxPathFormat   
	*/

  wxChar GetPathSeparator(wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Returns the string containing all the path separators for this format. For all
formats but   this string contains only one character but for
DOS and Windows both   and   may be used as
separators. 
	 * \param wxPathFormat   
	*/

  wxString GetPathSeparators(wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Return the short form of the path (returns identity on non-Windows platforms). 
	*/

  wxString GetShortPath() const;
	/**
	 * \brief Returns the last access, last modification and creation times. The last access
time is updated whenever the file is read or written (or executed in the case
of Windows), last modification time is only changed when the file is written
to. Finally, the creation time is indeed the time when the file was created
under Windows and the inode change time under Unix (as it is impossible to
retrieve the real file creation time there anyhow) which can also be changed
by many operations after the file creation.

Any of the pointers may be   if the corresponding time is not
needed. 
	 * \param wxDateTime*   
	 * \param wxDateTime*   
	 * \param wxDateTime*   
	*/

  bool GetTimes(wxDateTime*  dtAccess , wxDateTime*  dtMod , wxDateTime*  dtCreate ) const;
	/**
	 * \brief Returns the string containing the volume for this file name, mepty if it
doesn't have one or if the file system doesn't support volumes at all (for
example, Unix). 
	*/

  wxString GetVolume() const;
	/**
	 * \brief Returns the string separating the volume from the path for this format. 
	 * \param wxPathFormat   
	*/

  wxString GetVolumeSeparator(wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Returns true if an extension is present. 
	*/

  bool HasExt() const;
	/**
	 * \brief Returns true if a name is present. 
	*/

  bool HasName() const;
	/**
	 * \brief Returns true if a volume specifier is present. 
	*/

  bool HasVolume() const;
	/**
	 * \brief Inserts a directory before the zero-based position in the directory list. 
	 * \param int   
	 * \param const wxString&   
	*/

  void InsertDir(int  before , const wxString&  dir ) ;
	/**
	 * \brief Returns true if this filename is absolute. 
	 * \param wxPathFormat   
	*/

  bool IsAbsolute(wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Returns true if the file names of this type are case-sensitive. 
	 * \param wxPathFormat   
	*/

  bool IsCaseSensitive(wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Returns   if the filename is valid,   if it is not
initialized yet. The assignment functions and
  may reset the object to the uninitialized,
invalid state (the former only do it on failure). 
	*/

  bool IsOk() const;
	/**
	 * \brief Returns   if the char is a path separator for this format. 
	 * \param wxChar   
	 * \param wxPathFormat   
	*/

  bool IsPathSeparator(wxChar  ch , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Returns   if this filename is not absolute. 
	 * \param wxPathFormat   
	*/

  bool IsRelative(wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Returns   if this object represents a directory,   otherwise
(i.e. if it is a file). Note that this method doesn't test whether the
directory or file really exists, you should use 
  or 
  for this. 
	*/

  bool IsDir() const;
	/**
	 * \brief Make the file name absolute. This is a shortcut for
 {wxfilenamenormalize}(wxPATH_NORM_DOTS | wxPATH_NORM_ABSOLUTE | wxPATH_NORM_TILDE, cwd, format)}. 
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

  bool MakeAbsolute(const wxString&  cwd = wxEmptyString, wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief This function tries to put this file name in a form relative to  .
In other words, it returns the file name which should be used to access this
file if the current directory were  . 
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

  bool MakeRelativeTo(const wxString&  pathBase = wxT(""), wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  bool Mkdir(int  perm = 0777, int  flags = 0) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param int   
	 * \param int   
	*/

  static bool Mkdir(const wxString&  dir , int  perm = 0777, int  flags = 0) ;
	/**
	 * \brief Normalize the path. With the default flags value, the path will be
made absolute, without any &quot;..&quot; and &quot;.&quot; and all environment
variables will be expanded in it. 
	 * \param int   
	 * \param const wxString&   
	 * \param wxPathFormat   
	*/

  bool Normalize(int  flags = wxPATH_NORM_ALL, const wxString&  cwd = wxEmptyString, wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Prepends a directory name. 
	 * \param const wxString&   
	*/

  void PrependDir(const wxString&  dir ) ;
	/**
	 * \brief Removes a directory name. 
	 * \param int   
	*/

  void RemoveDir(int  pos ) ;
	/**
	 * \brief  
	*/

  bool Rmdir() ;
	/**
	 * \brief Deletes the specified directory from the file system. 
	 * \param const wxString&   
	*/

  static bool Rmdir(const wxString&  dir ) ;
	/**
	 * \brief Compares the filename using the rules of this platform. 
	 * \param const wxFileName&   
	 * \param wxPathFormat   
	*/

  bool SameAs(const wxFileName&  filepath , wxPathFormat  format = wxPATH_NATIVE) const;
	/**
	 * \brief  
	*/

  bool SetCwd() ;
	/**
	 * \brief Changes the current working directory. 
	 * \param const wxString&   
	*/

  static bool SetCwd(const wxString&  cwd ) ;
	/**
	 * \brief Sets the extension of this file name. 
	 * \param const wxString&   
	*/

  void SetExt(const wxString&  ext ) ;
	/**
	 * \brief The full name is the file name and extension (but without the path). 
	 * \param const wxString&   
	*/

  void SetFullName(const wxString&  fullname ) ;
	/**
	 * \brief Sets the name. 
	 * \param const wxString&   
	*/

  void SetName(const wxString&  name ) ;
	/**
	 * \brief Sets the file creation and last access/modification times (any of the pointers may be NULL). 
	 * \param const wxDateTime*   
	 * \param const wxDateTime*   
	 * \param const wxDateTime*   
	*/

  bool SetTimes(const wxDateTime*  dtAccess , const wxDateTime*  dtMod , const wxDateTime*  dtCreate ) ;
	/**
	 * \brief Sets the volume specifier. 
	 * \param const wxString&   
	*/

  void SetVolume(const wxString&  volume ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param wxString*   
	 * \param wxString*   
	 * \param wxString*   
	 * \param wxString*   
	 * \param wxPathFormat   
	*/

  static void SplitPath(const wxString&  fullpath , wxString*  volume , wxString*  path , wxString*  name , wxString*  ext , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief This function splits a full file name into components: the volume (with the
first version) path (including the volume in the second version), the base name
and the extension. Any of the output parameters ( ,  , 
  or  ) may be   if you are not interested in the
value of a particular component. Also,   may be empty on entry.

On return,   contains the file path (without the trailing separator), 
  contains the file name and   contains the file extension
without leading dot. All three of them may be empty if the corresponding
component is. The old contents of the strings pointed to by these parameters
will be overwritten in any case (if the pointers are not  ). 
	 * \param const wxString&   
	 * \param wxString*   
	 * \param wxString*   
	 * \param wxString*   
	 * \param wxPathFormat   
	*/

  static void SplitPath(const wxString&  fullpath , wxString*  path , wxString*  name , wxString*  ext , wxPathFormat  format = wxPATH_NATIVE) ;
	/**
	 * \brief Sets the access and modification times to the current moment. 
	*/

  bool Touch() ;
};


#endif
