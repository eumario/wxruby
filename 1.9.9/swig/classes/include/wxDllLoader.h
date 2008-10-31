// wxDllLoader.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDllLoader_h_)
#define _wxDllLoader_h_
class wxDllLoader
{
public:
	/**
	 * \brief Returns the string containing the usual extension for shared libraries for the
given systems (including the leading dot if not empty).

For example, this function will return   under Windows or (usually) 
  under Unix. 
	*/

  static wxString GetDllExt() ;
	/**
	 * \brief This function returns a valid handle for the main program itself. Notice that
the   return value is valid for some systems (i.e. doesn't mean that
the function failed).

  This function is Unix specific. It will always fail under Windows
or OS/2. 
	*/

  wxDllType GetProgramHandle() ;
	/**
	 * \brief This function resolves a symbol in a loaded DLL, such as a variable or
function name.

Returned value will be   if the symbol was not found in the DLL or if
an error occured. 
	 * \param wxDllType   
	 * \param const wxString&   
	*/

  void * GetSymbol(wxDllType  dllHandle , const wxString&  name ) ;
	/**
	 * \brief This function loads a shared library into memory, with   being the
name of the library: it may be either the full name including path and
(platform-dependent) extension, just the basename (no path and no extension)
or a basename with extension. In the last two cases, the library will be
searched in all standard locations.

Returns a handle to the loaded DLL. Use   parameter to test if it
is valid. If the handle is valid, the library must be unloaded later with 
 . 
	 * \param const wxString &   
	 * \param bool*   
	*/

  wxDllType LoadLibrary(const wxString &  libname , bool*  success = NULL) ;
	/**
	 * \brief This function unloads the shared library. The handle   must have
been returned by   previously. 
	 * \param wxDllType   
	*/

  void UnloadLibrary(wxDllType  dllhandle ) ;
};


#endif
