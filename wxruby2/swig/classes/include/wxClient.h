// wxClient.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxClient_h_)
#define _wxClient_h_
class wxClient : public wxObject
{
public:
	/**
	 * \brief Constructs a client object. 
	*/

   wxClient() ;
	/**
	 * \brief Tries to make a connection with a server by host (machine name
under UNIX - use 'localhost' for same machine; ignored when using
native DDE in Windows), service name and topic string. If the
server allows a connection, a wxConnection object will be
returned. The type of wxConnection returned can be altered by
overriding the 
  
member to return your own derived connection object.

Under Unix, the service name may be either an integer port
identifier in which case an Internet domain socket will be used
for the communications, or a valid file name (which shouldn't
exist and will be deleted afterwards) in which case a Unix domain
socket is created.

  Using Internet domain sockets if extremely
insecure for IPC as there is absolutely no access control for
them, use Unix domain sockets whenever possible! 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  wxConnectionBase * MakeConnection(const wxString&  host , const wxString&  service , const wxString&  topic ) ;
	/**
	 * \brief Called by  , by
default this simply returns a new wxConnection object. Override
this method to return a wxConnection descendant customised for the
application.

The advantage of deriving your own connection class is that it
will enable you to intercept messages initiated by the server,
such as  . You
may also want to store application-specific data in instances of
the new class. 
	*/

  virtual wxConnectionBase * OnMakeConnection() ;
	/**
	 * \brief Returns true if this is a valid host name, false otherwise. This always
returns true under MS Windows. 
	 * \param const wxString&   
	*/

  bool ValidHost(const wxString&  host ) ;
};


#endif
