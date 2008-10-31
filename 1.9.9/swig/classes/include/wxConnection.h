// wxConnection.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxConnection_h_)
#define _wxConnection_h_
class wxConnection : public wxObject
{
public:
	/**
	 * \brief  
	*/

   wxConnection() ;
	/**
	 * \brief Constructs a connection object. If no user-defined connection
object is to be derived from wxConnection, then the constructor
should not be called directly, since the default connection
object will be provided on requesting (or accepting) a
connection. However, if the user defines his or her own derived
connection object, the 
and/or   
members should be replaced by functions which construct the new
connection object.

If the arguments of the wxConnection constructor are void then
the wxConnection object manages its own connection buffer,
allocating memory as needed. A programmer-supplied buffer cannot
be increased if necessary, and the program will assert if it is
not large enough. The programmer-supplied buffer is included
mainly for backwards compatibility. 
	 * \param char*   
	 * \param int  
	*/

   wxConnection(char*  buffer , int  size ) ;
	/**
	 * \brief Called by the server application to advise the client of a change
in the data associated with the given item. Causes the client
connection's   member
to be called. Returns true if successful. 
	 * \param const wxString&   
	 * \param char*   
	 * \param int  
	 * \param wxIPCFormat  
	*/

  bool Advise(const wxString&  item , char*  data , int size = -1, wxIPCFormat format = wxCF_TEXT) ;
	/**
	 * \brief Called by the client application to execute a command on the
server. Can also be used to transfer arbitrary data to the server
(similar to   in
that respect). Causes the server connection's   
member to be called. Returns true if successful. 
	 * \param char*   
	 * \param int  
	 * \param wxIPCFormat  
	*/

  bool Execute(char*  data , int size = -1, wxIPCFormat format = wxCF_TEXT) ;
	/**
	 * \brief Called by the client or server application to disconnect from the
other program; it causes the   
message to be sent to the corresponding connection object in the
other program. Returns true if successful or already disconnected.
The application that calls   must explicitly delete
its side of the connection. 
	*/

  bool Disconnect() ;
	/**
	 * \brief Message sent to the client application when the server notifies
it of a change in the data associated with the given item, using
 . 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param char*   
	 * \param int  
	 * \param wxIPCFormat  
	*/

  virtual bool OnAdvise(const wxString&  topic , const wxString&  item , char*  data , int  size , wxIPCFormat  format ) ;
	/**
	 * \brief Message sent to the client or server application when the other
application notifies it to end the connection. The default
behaviour is to delete the connection object and return true, so
applications should generally override  
(finally calling the inherited method as well) so that they know
the connection object is no longer available. 
	*/

  virtual bool OnDisconnect() ;
	/**
	 * \brief Message sent to the server application when the client notifies
it to execute the given data, using  .
Note that there is no item associated with this message. 
	 * \param const wxString&   
	 * \param char*   
	 * \param int  
	 * \param wxIPCFormat  
	*/

  virtual bool OnExecute(const wxString&  topic , char*  data , int  size , wxIPCFormat  format ) ;
	/**
	 * \brief Message sent to the server application when the client notifies it to
accept the given data. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param char*   
	 * \param int  
	 * \param wxIPCFormat  
	*/

  virtual bool OnPoke(const wxString&  topic , const wxString&  item , char*  data , int  size , wxIPCFormat  format ) ;
	/**
	 * \brief Message sent to the server application when the client calls 
 . The
server's   method
should respond by returning a character string, or NULL to
indicate no data, and setting &#42;size. The character string must of
course persist after the call returns. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param int *  
	 * \param wxIPCFormat  
	*/

  virtual char* OnRequest(const wxString&  topic , const wxString&  item , int * size , wxIPCFormat  format ) ;
	/**
	 * \brief Message sent to the server application by the client, when the client
wishes to start an `advise loop' for the given topic and item. The
server can refuse to participate by returning false. 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  virtual bool OnStartAdvise(const wxString&  topic , const wxString&  item ) ;
	/**
	 * \brief Message sent to the server application by the client, when the client
wishes to stop an `advise loop' for the given topic and item. The
server can refuse to stop the advise loop by returning false, although
this doesn't have much meaning in practice. 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  virtual bool OnStopAdvise(const wxString&  topic , const wxString&  item ) ;
	/**
	 * \brief Called by the client application to poke data into the server.
Can be used to transfer arbitrary data to the server. Causes the
server connection's   member to
be called. If size is -1 the size is computed from the string
length of data.

Returns true if successful. 
	 * \param const wxString&   
	 * \param char*   
	 * \param int  
	 * \param wxIPCFormat  
	*/

  bool Poke(const wxString&  item , char*  data , int size = -1, wxIPCFormat format = wxCF_TEXT) ;
	/**
	 * \brief Called by the client application to request data from the server.
Causes the server connection's   
member to be called. Size may be NULL or a pointer to a variable
to receive the size of the requested item.

Returns a character string (actually a pointer to the
connection's buffer) if successful, NULL otherwise. This buffer
does not need to be deleted. 
	 * \param const wxString&   
	 * \param int *  
	 * \param wxIPCFormat  
	*/

  char* Request(const wxString&  item , int * size , wxIPCFormat format = wxIPC_TEXT) ;
	/**
	 * \brief Called by the client application to ask if an advise loop can be
started with the server. Causes the server connection's 
 
member to be called. Returns true if the server okays it, false
otherwise. 
	 * \param const wxString&   
	*/

  bool StartAdvise(const wxString&  item ) ;
	/**
	 * \brief Called by the client application to ask if an advise loop can be
stopped. Causes the server connection's   
member to be called. Returns true if the server okays it, false
otherwise. 
	 * \param const wxString&   
	*/

  bool StopAdvise(const wxString&  item ) ;
};


#endif
