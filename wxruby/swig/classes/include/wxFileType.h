// wxFileType.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileType_h_)
#define _wxFileType_h_
class wxFileType
{
public:
	/**
	 * \brief The default constructor is private because you should never create objects of
this type: they are only returned by   methods. 
	*/

   wxFileType() ;
	/**
	 * \brief The destructor of this class is not virtual, so it should not be derived from. 
	*/

  virtual  ~wxFileType() ;
	/**
	 * \brief If the function returns  , the string pointed to by   is filled
with full MIME type specification for this file type: for example, &quot;text/plain&quot;. 
	 * \param wxString*  
	*/

  bool GetMimeType(wxString*  mimeType ) ;
	/**
	 * \brief Same as   but returns array of MIME
types. This array will contain only one item in most cases but sometimes,
notably under Unix with KDE, may contain more MIME types. This happens when
one file extension is mapped to different MIME types by KDE, mailcap and
mime.types. 
	 * \param wxArrayString&  
	*/

  bool GetMimeTypes(wxArrayString&  mimeTypes ) ;
	/**
	 * \brief If the function returns  , the array   is filled
with all extensions associated with this file type: for example, it may
contain the following two elements for the MIME type &quot;text/html&quot; (notice the
absence of the leading dot): &quot;html&quot; and &quot;htm&quot;.

  This function is currently not implemented: there is no
(efficient) way to retrieve associated extensions from the given MIME type on
this platform, so it will only return   if the wxFileType object was created
by   
function in the first place. 
	 * \param wxArrayString&  
	*/

  bool GetExtensions(wxArrayString&  extensions ) ;
	/**
	 * \brief If the function returns  , the   is filled with the
location of the icon for this MIME type. A   may be
created from   later.

  The function returns the icon shown by Explorer for the files of
the specified type.

  This function is not implemented and always returns  .

  MIME manager gathers information about icons from GNOME
and KDE settings and thus GetIcon's success depends on availability
of these desktop environments. 
	 * \param wxIconLocation *  
	*/

  bool GetIcon(wxIconLocation *  iconLoc ) ;
	/**
	 * \brief If the function returns  , the string pointed to by   is filled
with a brief description for this file type: for example, &quot;text document&quot; for
the &quot;text/plain&quot; MIME type. 
	 * \param wxString*  
	*/

  bool GetDescription(wxString*  desc ) ;
	/**
	 * \brief  
	 * \param wxString*  
	 * \param MessageParameters&  
	*/

  bool GetOpenCommand(wxString*  command , MessageParameters&  params ) ;
	/**
	 * \brief With the first version of this method, if the   is returned, the
string pointed to by   is filled with the command which must be
executed (see  ) in order to open the file of the
given type. In this case, the name of the file as well as any other parameters
is retrieved from   
class.

In the second case, only the filename is specified and the command to be used
to open this kind of file is returned directly. An empty string is returned to
indicate that an error occured (typically meaning that there is no standard way
to open this kind of files). 
	 * \param const wxString&  
	*/

  wxString GetOpenCommand(const wxString&  filename ) ;
	/**
	 * \brief If the function returns  , the string pointed to by   is filled
with the command which must be executed (see  ) in
order to print the file of the given type. The name of the file is
retrieved from   class. 
	 * \param wxString*  
	 * \param MessageParameters&  
	*/

  bool GetPrintCommand(wxString*  command , MessageParameters&  params ) ;
	/**
	 * \brief This function is primarily intended for GetOpenCommand and GetPrintCommand
usage but may be also used by the application directly if, for example, you want
to use some non default command to open the file.

The function replaces all occurrences of

\twocolwidtha{7cm}
 

using the MessageParameters object you pass to it.

If there is no '\assumed that the command reads the data on stdin and so the effect is the same
as &quot;&lt; \
Unlike all other functions of this class, there is no error return for this
function. 
	 * \param const wxString&  
	 * \param MessageParameters&  
	*/

  static wxString ExpandCommand(const wxString&  command , MessageParameters&  params ) ;
};


#endif
