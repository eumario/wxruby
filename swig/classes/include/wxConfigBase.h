// wxConfigBase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxConfigBase_h_)
#define _wxConfigBase_h_
class wxConfigBase
{
public:
	/**
	 * \brief This is the default and only constructor of the wxConfigBase class, and
derived classes. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param long  
	 * \param wxMBConv&  
	*/

  wxConfigBase(const wxString&  appName = wxEmptyString, const wxString&  vendorName = wxEmptyString);
	/**
	 * \brief Empty but ensures that dtor of all derived classes is virtual. 
	*/

  virtual  ~wxConfigBase() ;
	/**
	 * \brief Create a new config object: this function will create the &quot;best&quot;
implementation of wxConfig available for the current platform, see comments
near the definition of wxCONFIG_WIN32_NATIVE for details. It returns the
created object and also sets it as the current one. 
	*/

  static wxConfigBase * Create() ;
	/**
	 * \brief Calling this function will prevent   from automatically creating a
new config object if the current one is NULL. It might be useful to call it
near the program end to prevent new config object &quot;accidental&quot; creation. 
	*/

  void DontCreateOnDemand() ;
	/**
	 * \brief Delete the whole underlying object (disk file, registry key, ...). Primarly
for use by desinstallation routine. 
	*/

  bool DeleteAll() ;
	/**
	 * \brief Deletes the specified entry and the group it belongs to if it was the last key
in it and the second parameter is true. 
	 * \param const wxString&   
	 * \param bool  
	*/

  bool DeleteEntry(const wxString&   key , bool bDeleteGroupIfEmpty = true) ;
	/**
	 * \brief Delete the group (with all subgroups) 
	 * \param const wxString&   
	*/

  bool DeleteGroup(const wxString&   key ) ;
	/**
	 * \brief returns true if either a group or an entry with a given name exists 
	 * \param wxString&   
	*/

  bool Exists(wxString&  strName ) const;
	/**
	 * \brief permanently writes all changes (otherwise, they're only written from object's
destructor) 
	 * \param bool   
	*/

  bool Flush(bool  bCurrentOnly = false) ;
	/**
	 * \brief Get the current config object. If there is no current object and
  is true, creates one
(using  ) unless DontCreateOnDemand was called previously. 
	 * \param bool   
	*/

  static wxConfigBase * Get(bool  CreateOnDemand = true) ;
	/**
	 * \brief Returns the application name. 
	*/

  wxString GetAppName() const;
	/**
	 * \brief Returns the type of the given entry or   if the entry doesn't
exist. This function should be used to decide which version of Read() should
be used because some of wxConfig implementations will complain about type
mismatch otherwise: e.g., an attempt to read a string value from an integer
key with wxRegConfig will fail.

The result is an element of enum EntryType: 
	 * \param const wxString&   
	*/

  enum wxConfigBase::EntryType GetEntryType(const wxString&  name ) const;
	/**
	 * \brief Gets the first group.

\pythonnote{The wxPython version of this method returns a 3-tuple
consisting of the continue flag, the value string, and the index for
the next call.}

\perlnote{In wxPerl this method takes no arguments and returns a 3-element
list  .} 
	 * \param wxString&   
	 * \param long&  
	*/

  bool GetFirstGroup(wxString&  str , long&  index ) const;
	/**
	 * \brief Gets the first entry.

\pythonnote{The wxPython version of this method returns a 3-tuple
consisting of the continue flag, the value string, and the index for
the next call.}

\perlnote{In wxPerl this method takes no arguments and returns a 3-element
list  .} 
	 * \param wxString&   
	 * \param long&  
	*/

  bool GetFirstEntry(wxString&  str , long&  index ) const;
	/**
	 * \brief Gets the next group.

\pythonnote{The wxPython version of this method returns a 3-tuple
consisting of the continue flag, the value string, and the index for
the next call.}

\perlnote{In wxPerl this method only takes the   parameter
and returns a 3-element list  .} 
	 * \param wxString&   
	 * \param long&  
	*/

  bool GetNextGroup(wxString&  str , long&  index ) const;
	/**
	 * \brief Gets the next entry.

\pythonnote{The wxPython version of this method returns a 3-tuple
consisting of the continue flag, the value string, and the index for
the next call.}

\perlnote{In wxPerl this method only takes the   parameter
and returns a 3-element list  .} 
	 * \param wxString&   
	 * \param long&  
	*/

  bool GetNextEntry(wxString&  str , long&  index ) const;
	/**
	 * \brief  
	 * \param bool   
	*/

  int  GetNumberOfEntries(bool  bRecursive = false) const;
	/**
	 * \brief Get number of entries/subgroups in the current group, with or without its
subgroups. 
	 * \param bool   
	*/

  int GetNumberOfGroups(bool  bRecursive = false) const;
	/**
	 * \brief Retrieve the current path (always as absolute path). 
	*/

  wxString GetPath() const;
	/**
	 * \brief Returns the vendor name. 
	*/

  wxString GetVendorName() const;
	/**
	 * \brief returns true if the entry by this name exists 
	 * \param wxString&   
	*/

  bool HasEntry(wxString&  strName ) const;
	/**
	 * \brief returns true if the group by this name exists 
	 * \param const wxString&   
	*/

  bool HasGroup(const wxString&  strName ) const;
	/**
	 * \brief Returns true if we are expanding environment variables in key values. 
	*/

  bool IsExpandingEnvVars() const;
	/**
	 * \brief Returns true if we are writing defaults back to the config file. 
	*/

  bool IsRecordingDefaults() const;
	/**
	 * \brief Read a string from the key, returning true if the value was read. If the key
was not found,   is not changed. 
	 * \param const wxString&   
	 * \param wxString*  
	*/

  bool Read(const wxString&  key , wxString*  str ) const;
	/**
	 * \brief Read a string from the key. The default value is returned if the key was not
found.

Returns true if value was really read, false if the default was used. 
	 * \param const wxString&   
	 * \param wxString*  
	 * \param const wxString&   
	*/

  bool Read(const wxString&  key , wxString*  str , const wxString&  defaultVal ) const;
	/**
	 * \brief Another version of  , returning the string value directly. 
	 * \param const wxString&   
	 * \param const
wxString&   
	*/

  wxString Read(const wxString&  key , const
wxString&  defaultVal ) const;
	/**
	 * \brief Reads a long value, returning true if the value was found. If the value was
not found,   is not changed. 
	 * \param const wxString&   
	 * \param long*  
	*/

  bool Read(const wxString&   key , long*  l ) const;
	/**
	 * \brief Reads a long value, returning true if the value was found. If the value was
not found,   is used instead. 
	 * \param const wxString&   
	 * \param long*  
	 * \param long  
	*/

  bool Read(const wxString&   key , long*  l , long  defaultVal ) const;
	/**
	 * \brief Reads a long value from the key and returns it.   is returned
if the key is not found.

NB: writing

 

won't work because the call is ambiguous: compiler can not choose between two
  functions. Instead, write: 
	 * \param const wxString&   
	 * \param long  
	*/

  long  Read(const wxString&  key , long  defaultVal ) const;
	/**
	 * \brief Reads a double value, returning true if the value was found. If the value was
not found,   is not changed. 
	 * \param const wxString&   
	 * \param double*  
	*/

  bool Read(const wxString&   key , double*  d ) const;
	/**
	 * \brief Reads a double value, returning true if the value was found. If the value was
not found,   is used instead. 
	 * \param const wxString&   
	 * \param double*  
	 * \param double  
	*/

  bool Read(const wxString&   key , double*  d , double  defaultVal ) const;
	/**
	 * \brief Reads a bool value, returning true if the value was found. If the value was
not found,   is not changed. 
	 * \param const wxString&   
	 * \param bool*  
	*/

  bool Read(const wxString&   key , bool*  b ) const;
	/**
	 * \brief Reads a bool value, returning true if the value was found. If the value was
not found,   is used instead.

\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
}

\perlnote{In place of a single overloaded method, wxPerl uses:\par
\indented{2cm}{ 
}} 
	 * \param const wxString&   
	 * \param bool*  
	 * \param bool  
	*/

  bool Read(const wxString&   key , bool*  d , bool  defaultVal ) const;
	/**
	 * \brief Renames an entry in the current group. The entries names (both the old and
the new one) shouldn't contain backslashes, i.e. only simple names and not
arbitrary paths are accepted by this function.

Returns false if the   doesn't exist or if   already
exists. 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  bool RenameEntry(const wxString&   oldName , const wxString&   newName ) ;
	/**
	 * \brief Renames a subgroup of the current group. The subgroup names (both the old and
the new one) shouldn't contain backslashes, i.e. only simple names and not
arbitrary paths are accepted by this function.

Returns false if the   doesn't exist or if   already
exists. 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  bool RenameGroup(const wxString&   oldName , const wxString&   newName ) ;
	/**
	 * \brief Sets the config object as the current one, returns the pointer to the previous
current object (both the parameter and returned value may be NULL) 
	 * \param wxConfigBase *  
	*/

  static wxConfigBase * Set(wxConfigBase * pConfig ) ;
	/**
	 * \brief Determine whether we wish to expand environment variables in key values. 
	 * \param bool   
	*/

  void SetExpandEnvVars(bool  bDoIt = true) ;
	/**
	 * \brief Set current path: if the first character is '/', it is the absolute path,
otherwise it is a relative path. '..' is supported. If the strPath doesn't
exist it is created. 
	 * \param const wxString&   
	*/

  void SetPath(const wxString&  strPath ) ;
	/**
	 * \brief Sets whether defaults are recorded to the config file whenever an attempt to
read read the value which is not present in it is done.

If on (default is off) all default values for the settings used by the program
are written back to the config file. This allows the user to see what config
options may be changed and is probably useful only for wxFileConfig. 
	 * \param bool   
	*/

  void SetRecordDefaults(bool  bDoIt = true) ;
	/**
	 * \brief this function is not in the base wxConfigBase class but is only
implemented in wxFileConfig. Moreover, this function is Unix-specific and
doesn't do anything on other platforms.

SetUmask() allows to set the mode to be used for the config file creation.
For example, to create a config file which is not readable by other users
(useful if it stores some sensitive information, such as passwords), you
should do  . 
	 * \param int   
	*/

  void SetUmask(int  mode ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  bool Write(const wxString&   key , const wxString&  
value ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param long  
	*/

  bool Write(const wxString&   key , long  value ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param double  
	*/

  bool Write(const wxString&   key , double  value ) ;
	/**
	 * \brief These functions write the specified value to the config file and return true
on success.

\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
}

\perlnote{In place of a single overloaded method, wxPerl uses:\par
\indented{2cm}{ 
}} 
	 * \param const wxString&   
	 * \param bool  
	*/

  bool Write(const wxString&   key , bool  value ) ;
};


#endif
