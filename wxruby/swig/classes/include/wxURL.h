// wxURL.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxURL_h_)
#define _wxURL_h_
class wxURL : public wxObject
{
public:
	/**
	 * \brief Constructs a URL object from the string.  The URL must be valid according
to RFC 1738.  In particular, file URLs must be of the format
'file://hostname/path/to/file'.  It is valid to leave out the hostname
but slashes must remain in place-- i.e. a file URL without a hostname must
contain three consecutive slashes. 
	 * \param const wxString&  
	*/

   wxURL(const wxString&  url ) ;
	/**
	 * \brief Destroys the URL object. 
	*/

  virtual  ~wxURL() ;
	/**
	 * \brief Returns the name of the protocol which will be used to get the URL. 
	*/

  wxString GetProtocolName() const;
	/**
	 * \brief Returns a reference to the protocol which will be used to get the URL. 
	*/

  wxProtocol& GetProtocol() ;
	/**
	 * \brief Returns the path of the file to fetch. This path was encoded in the URL. 
	*/

  wxString GetPath() ;
	/**
	 * \brief Returns the last error. This error refers to the URL parsing or to the protocol.
It can be one of these errors:

\twocolwidtha{7cm} 
	*/

  wxURLError GetError() const;
	/**
	 * \brief Creates a new input stream on the the specified URL. You can use all but seek
functionality of wxStream. Seek isn't available on all stream. For example,
http or ftp streams doesn't deal with it. 
	*/

  wxInputStream * GetInputStream() ;
	/**
	 * \brief Sets the default proxy server to use to get the URL. The string specifies
the proxy like this: &lt;hostname&gt;:&lt;port number&gt;. 
	 * \param const wxString&  
	*/

  static void SetDefaultProxy(const wxString&  url_proxy ) ;
	/**
	 * \brief Sets the proxy to use for this URL. 
	 * \param const wxString&  
	*/

  void SetProxy(const wxString&  url_proxy ) ;
	/**
	 * \brief It converts a non-standardized URI to a valid network URI. It encodes non
standard characters. 
	 * \param const wxString&  
	*/

  static wxString ConvertToValidURI(const wxString&  uri ) ;
};


#endif
