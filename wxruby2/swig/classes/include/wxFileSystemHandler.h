// wxFileSystemHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileSystemHandler_h_)
#define _wxFileSystemHandler_h_
class wxFileSystemHandler : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxFileSystemHandler() ;
	/**
	 * \brief Returns true if the handler is able to open this file. This function doesn't
check whether the file exists or not, it only checks if it knows the protocol.
Example:

 

Must be overridden in derived handlers. 
	 * \param const wxString&   
	*/

  virtual bool CanOpen(const wxString&  location ) ;
	/**
	 * \brief Returns the anchor if present in the location.
See   for details.

Example: GetAnchor(&quot;index.htm\#chapter2&quot;) == &quot;chapter2&quot;

  the anchor is NOT part of the left location. 
	 * \param const wxString&   
	*/

  wxString GetAnchor(const wxString&  location ) const;
	/**
	 * \brief Returns the left location string extracted from  . 

Example: GetLeftLocation(&quot;file:myzipfile.zip\#zip:index.htm&quot;) == &quot;file:myzipfile.zip&quot; 
	 * \param const wxString&   
	*/

  wxString GetLeftLocation(const wxString&  location ) const;
	/**
	 * \brief Returns the MIME type based on   of  . (While wxFSFile::GetMimeType
returns real MIME type - either extension-based or queried from HTTP.)

Example : GetMimeTypeFromExt(&quot;index.htm&quot;) == &quot;text/html&quot; 
	 * \param const wxString&   
	*/

  wxString GetMimeTypeFromExt(const wxString&  location ) ;
	/**
	 * \brief Returns the protocol string extracted from  . 

Example: GetProtocol(&quot;file:myzipfile.zip\#zip:index.htm&quot;) == &quot;zip&quot; 
	 * \param const wxString&   
	*/

  wxString GetProtocol(const wxString&  location ) const;
	/**
	 * \brief Returns the right location string extracted from  . 

Example : GetRightLocation(&quot;file:myzipfile.zip\#zip:index.htm&quot;) == &quot;index.htm&quot; 
	 * \param const wxString&   
	*/

  wxString GetRightLocation(const wxString&  location ) const;
	/**
	 * \brief Works like  . Returns name of the first
filename (within filesystem's current path) that matches  .   may be one of
wxFILE (only files), wxDIR (only directories) or 0 (both).

This method is only called if   returns true. 
	 * \param const wxString&   
	 * \param int   
	*/

  virtual wxString FindFirst(const wxString&  wildcard , int  flags = 0) ;
	/**
	 * \brief Returns next filename that matches parameters passed to  .

This method is only called if   returns true and FindFirst
returned a non-empty string. 
	*/

  virtual wxString FindNext() ;
	/**
	 * \brief Opens the file and returns wxFSFile pointer or NULL if failed.

Must be overridden in derived handlers. 
	 * \param wxFileSystem&   
	 * \param const wxString&   
	*/

  virtual wxFSFile* OpenFile(wxFileSystem&  fs , const wxString&  location ) ;
};


#endif
