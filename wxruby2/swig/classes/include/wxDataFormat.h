// wxDataFormat.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDataFormat_h_)
#define _wxDataFormat_h_
class wxDataFormat
{
public:
	/**
	 * \brief Constructs a data format object for one of the standard data formats or an
empty data object (use   or 
  later in this case)

\perlnote{In wxPerl this function is named  .} 
	 * \param NativeFormat  
	*/

   wxDataFormat(NativeFormat format = wxDF_INVALID) ;
	/**
	 * \brief Constructs a data format object for a custom format identified by its name 
 .

\perlnote{In wxPerl this function is named  .} 
	 * \param const wxChar   
	*/

   wxDataFormat(const wxChar  *format ) ;
	/**
	 * \brief Returns the name of a custom format (this function will fail for a standard
format). 
	*/

  wxString GetId() const;
	/**
	 * \brief Returns the platform-specific number identifying the format. 
	*/

  NativeFormat GetType() const;
	/**
	 * \brief Sets the format to be the custom format identified by the given name. 
	 * \param const wxChar   
	*/

  void SetId(const wxChar  *format ) ;
	/**
	 * \brief Sets the format to the given value, which should be one of wxDF_XXX constants. 
	 * \param NativeFormat  
	*/

  void SetType(NativeFormat  format ) ;
};


#endif
