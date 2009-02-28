// wxDynamicLibrary.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDynamicLibrary_h_)
#define _wxDynamicLibrary_h_
class wxDynamicLibrary
{
public:
	/**
	 * \brief  
	*/

   wxDynamicLibrary() ;
	/**
	 * \brief Constructor. Second form calls  . 
	 * \param const wxString&   
	*/

   wxDynamicLibrary(const wxString&  name ) ;
	/**
	 * \brief Detaches this object from its library handle, i.e. the object will not unload
the library any longer in its destructor but it is now the callers
responsability to do this. 
	*/

  wxDllType Detach() ;
	/**
	 * \brief Returns true if the library was successfully loaded, false otherwise. 
	*/

  bool IsLoaded() const;
	/**
	 * \brief Loads DLL into memory.

Returns true if the library was successfully loaded, false otherwise. 
	 * \param const wxString&   
	*/

  bool Load(const wxString&  name ) ;
	/**
	 * \brief Unloads the library from memory. 
	*/

  void Unload() ;
	/**
	 * \brief Returns pointer to symbol   in the library or NULL if the library
contains no such symbol. 
	 * \param const wxString&   
	*/

  void* GetSymbol(const wxString&  name ) const;
};


#endif
