// wxMimeTypesManager.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMimeTypesManager_h_)
#define _wxMimeTypesManager_h_
class wxMimeTypesManager
{
public:
	/**
	 * \brief Constructor puts the object in the &quot;working&quot; state, no additional initialization
are needed - but   may be used to load
additional mailcap/mime.types files. 
	*/

   wxMimeTypesManager() ;
	/**
	 * \brief Destructor is not virtual, so this class should not be derived from. 
	*/

  virtual  ~wxMimeTypesManager() ;
	/**
	 * \brief This function may be used to provide hard-wired fallbacks for the MIME types
and extensions that might not be present in the system MIME database.


Please see the typetest sample for an example of using it. 
	 * \param const wxFileTypeInfo *  
	*/

  void AddFallbacks(const wxFileTypeInfo * fallbacks ) ;
	/**
	 * \brief Gather information about the files with given extension and return the
corresponding   object or NULL if the extension
is unknown. 
	 * \param const wxString&  
	*/

  wxFileType* GetFileTypeFromExtension(const wxString&  extension ) ;
	/**
	 * \brief Gather information about the files with given MIME type and return the
corresponding   object or NULL if the MIME type
is unknown. 
	 * \param const wxString&  
	*/

  wxFileType* GetFileTypeFromMimeType(const wxString&  mimeType ) ;
	/**
	 * \brief This function returns true if either the given   is exactly the
same as   or if it has the same category and the subtype of
  is '&#42;'. Note that the '&#42;' wildcard is not allowed in
  itself.

The comparison don by this function is case insensitive so it is not
necessary to convert the strings to the same case before calling it. 
	 * \param const wxString&  
	 * \param const wxString&  
	*/

  bool IsOfType(const wxString&  mimeType , const wxString&  wildcard ) ;
	/**
	 * \brief Load additional file containing information about MIME types and associated
information in mailcap format. See metamail(1) and mailcap(5) for more
information.

  parameter may be used to load additional mailcap files without
overriding the settings found in the standard files: normally, entries from
files loaded with ReadMailcap will override the entries from files loaded
previously (and the standard ones are loaded in the very beginning), but this
will not happen if this parameter is set to true (default is false).

The return value is true if there were no errors in the file or false
otherwise. 
	 * \param const wxString&  
	 * \param bool  
	*/

  bool ReadMailcap(const wxString&  filename , bool fallback = false) ;
	/**
	 * \brief Load additional file containing information about MIME types and associated
information in mime.types file format. See metamail(1) and mailcap(5) for more
information.

The return value is true if there were no errors in the file or false
otherwise. 
	 * \param const wxString&  
	*/

  bool ReadMimeTypes(const wxString&  filename ) ;
};


#endif
