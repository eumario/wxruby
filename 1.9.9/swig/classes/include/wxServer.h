// wxServer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxServer_h_)
#define _wxServer_h_
class wxServer
{
public:
	/**
	 * \brief Constructs a server object. 
	*/

   wxServer() ;
	/**
	 * \brief Registers the server using the given service name. Under Unix,
the service name may be either an integer port identifier in
which case an Internet domain socket will be used for the
communications, or a valid file name (which shouldn't exist and
will be deleted afterwards) in which case a Unix domain socket is
created. false is returned if the call failed (for example, the
port number is already in use). 
	 * \param const wxString&   
	*/

  bool Create(const wxString&  service ) ;
	/**
	 * \brief When a client calls  , the server receives the
message and this member is called. The application should derive a
member to intercept this message and return a connection object of
either the standard wxConnection type, or (more likely) of a
user-derived type.

If the topic is  , the application may wish to refuse the
connection. Under UNIX, when a server is created the
OnAcceptConnection message is always sent for standard input and
output, but in the context of DDE messages it doesn't make a lot
of sense. 
	 * \param const wxString&   
	*/

  virtual wxConnectionBase * OnAcceptConnection(const wxString&  topic ) ;
};


#endif
