// wxProtocol.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxProtocol_h_)
#define _wxProtocol_h_
class wxProtocol : public wxSocketClient
{
public:
	/**
	 * \brief Tries to reestablish a previous opened connection (close and renegotiate connection). 
	*/

  bool Reconnect() ;
	/**
	 * \brief Creates a new input stream on the the specified path. You can use all but seek
functionality of wxStream. Seek isn't available on all stream. For example,
http or ftp streams doesn't deal with it. Other functions like StreamSize and
Tell aren't available for the moment for this sort of stream.
You will be notified when the EOF is reached by an error. 
	 * \param const wxString&  
	*/

  wxInputStream * GetInputStream(const wxString&  path ) ;
	/**
	 * \brief Abort the current stream.

\wxheading{Warning}

It is advised to destroy the input stream instead of aborting the stream this way. 
	*/

  bool Abort() ;
	/**
	 * \brief Returns the last occurred error.

\twocolwidtha{7cm} 
	*/

  wxProtocolError GetError() ;
	/**
	 * \brief Returns the type of the content of the last opened stream. It is a mime-type. 
	*/

  wxString GetContentType() ;
	/**
	 * \brief Sets the authentication user. It is mainly useful when FTP is used. 
	 * \param const wxString&  
	*/

  void  SetUser(const wxString&  user ) ;
	/**
	 * \brief Sets the authentication password. It is mainly useful when FTP is used. 
	 * \param const wxString&  
	*/

  void SetPassword(const wxString&  user ) ;
};


#endif
