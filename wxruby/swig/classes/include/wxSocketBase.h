// wxSocketBase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSocketBase_h_)
#define _wxSocketBase_h_
class wxSocketBase : public wxObject
{
public:
	/**
	 * \brief Default constructor. Don't use it directly; instead, use 
  to construct a socket client, or 
  to construct a socket server. 
	*/

   wxSocketBase() ;
	/**
	 * \brief Destructor. Do not destroy a socket using the delete operator directly;
use   instead. Also, do not create
socket objects in the stack. 
	*/

  virtual  ~wxSocketBase() ;
	/**
	 * \brief  
	 * \param wxSocketBase::wxSockCbk  
	*/

  wxSocketBase::wxSockCbk Callback(wxSocketBase::wxSockCbk  callback ) ;
	/**
	 * \brief  
	 * \param char *  
	*/

  char * CallbackData(char * cdata ) ;
	/**
	 * \brief This function shuts down the socket, disabling further transmission and
reception of data; it also disables events for the socket and frees the
associated system resources. Upon socket destruction, Close is automatically
called, so in most cases you won't need to do it yourself, unless you
explicitly want to shut down the socket, typically to notify the peer
that you are closing the connection.

\wxheading{Remark/Warning}

Although Close immediately disables events for the socket, it is possible
that event messages may be waiting in the application's event queue. The
application must therefore be prepared to handle socket event messages
even after calling Close. 
	*/

  void Close() ;
	/**
	 * \brief Destroys the socket safely. Use this function instead of the delete operator,
since otherwise socket events could reach the application even after the
socket has been destroyed. To prevent this problem, this function appends
the wxSocket to a list of object to be deleted on idle time, after all
events have been processed. For the same reason, you should avoid creating
socket objects in the stack.

Destroy calls   automatically. 
	*/

  bool Destroy() ;
	/**
	 * \brief This function simply deletes all bytes in the incoming queue. This function
always returns immediately and its operation is not affected by IO flags.

Use   to verify the number of bytes actually discarded.

If you use  , it will always return false. 
	*/

  wxSocketBase& Discard() ;
	/**
	 * \brief Returns true if an error occurred in the last IO operation.

Use this function to check for an error condition after one of the
following calls: Discard, Peek, Read, ReadMsg, Unread, Write, WriteMsg. 
	*/

  bool Error() const;
	/**
	 * \brief Returns a pointer of the client data for this socket, as set with 
	*/

  void * GetClientData() const;
	/**
	 * \brief This function returns the local address field of the socket. The local
address field contains the complete local address of the socket (local
address, local port, ...). 
	 * \param wxSockAddress&   
	*/

  bool GetLocal(wxSockAddress&  addr ) const;
	/**
	 * \brief Returns current IO flags, as set with 
	*/

  wxSocketFlags GetFlags() const;
	/**
	 * \brief This function returns the peer address field of the socket. The peer 
address field contains the complete peer host address of the socket
(address, port, ...). 
	 * \param wxSockAddress&   
	*/

  bool GetPeer(wxSockAddress&  addr ) const;
	/**
	 * \brief Use this function to interrupt any wait operation currently in progress.
Note that this is not intended as a regular way to interrupt a Wait call,
but only as an escape mechanism for exceptional situations where it is
absolutely necessary to use it, for example to abort an operation due to
some exception or abnormal problem. InterruptWait is automatically called
when you   a socket (and thus also upon
socket destruction), so you don't need to use it in these cases.

 , 
 , 
 , 
 , 
 , 
	*/

  void InterruptWait() ;
	/**
	 * \brief Returns true if the socket is connected. 
	*/

  bool IsConnected() const;
	/**
	 * \brief This function waits until the socket is readable. This might mean that
queued data is available for reading or, for streamed sockets, that
the connection has been closed, so that a read operation will complete
immediately without blocking (unless the   flag
is set, in which case the operation might still block). 
	*/

  bool IsData() const;
	/**
	 * \brief Returns true if the socket is not connected. 
	*/

  bool IsDisconnected() const;
	/**
	 * \brief Returns the number of bytes read or written by the last IO call.

Use this function to get the number of bytes actually transferred
after using one of the following IO calls: Discard, Peek, Read,
ReadMsg, Unread, Write, WriteMsg. 
	*/

  wxUint32 LastCount() const;
	/**
	 * \brief Returns the last wxSocket error. See  .

Please note that this function merely returns the last error code,
but it should not be used to determine if an error has occurred (this
is because successful operations do not change the LastError value).
Use   first, in order to determine
if the last IO call failed. If this returns true, use LastError
to discover the cause of the error. 
	*/

  wxSocketError LastError() const;
	/**
	 * \brief According to the   value, this function enables
or disables socket events. If   is true, the events
configured with   will
be sent to the application. If   is false; no events
will be sent. 
	 * \param bool  
	*/

  void Notify(bool  notify ) ;
	/**
	 * \brief Returns true if the socket is initialized and ready and false in other
cases.

\wxheading{Remark/Warning}

For  , Ok won't return true unless
the client is connected to a server.

For  , Ok will return true if the
server could bind to the specified address and is already listening for
new connections.

Ok does not check for IO errors;
use   instead for that purpose. 
	*/

  bool Ok() const;
	/**
	 * \brief This function restores the previous state of the socket, as saved
with  

Calls to SaveState and RestoreState can be nested. 
	*/

  void RestoreState() ;
	/**
	 * \brief This function saves the current state of the socket in a stack. Socket
state includes flags, as set with  ,
event mask, as set with   and 
 , user data, as set with 
 , and asynchronous
callback settings, as set with   
and  .

Calls to SaveState and RestoreState can be nested. 
	*/

  void SaveState() ;
	/**
	 * \brief Sets user-supplied client data for this socket. All socket events will
contain a pointer to this data, which can be retrieved with
the   function. 
	 * \param void *  
	*/

  void SetClientData(void * data ) ;
	/**
	 * \brief  
	 * \param wxEvtHandler&  
	 * \param int  
	*/

  void SetEventHandler(wxEvtHandler&  handler , int id = -1) ;
	/**
	 * \brief Use SetFlags to customize IO operation for this socket.
The   parameter may be a combination of flags ORed together.
The following flags can be used:

\twocolwidtha{7cm}
 

A brief overview on how to use these flags follows.

If no flag is specified (this is the same as  ),
IO calls will return after some data has been read or written, even
when the transfer might not be complete. This is the same as issuing
exactly one blocking low-level call to recv() or send(). Note
that   here refers to when the function returns, not
to whether the GUI blocks during this time.

If   is specified, IO calls will return immediately.
Read operations will retrieve only available data. Write operations will
write as much data as possible, depending on how much space is available
in the output buffer. This is the same as issuing exactly one nonblocking
low-level call to recv() or send(). Note that   here
refers to when the function returns, not to whether the GUI blocks during
this time.

If   is specified, IO calls won't return until ALL
the data has been read or written (or until an error occurs), blocking if
necessary, and issuing several low level calls if necessary. This is the
same as having a loop which makes as many blocking low-level calls to
recv() or send() as needed so as to transfer all the data. Note
that   here refers to when the function returns, not
to whether the GUI blocks during this time.

The   flag controls whether the GUI blocks during
IO operations. If this flag is specified, the socket will not yield
during IO calls, so the GUI will remain blocked until the operation
completes. If it is not used, then the application must take extra
care to avoid unwanted reentrance.

So:

  will try to read at least SOME data, no matter how much.

  will always return immediately, even if it cannot
read or write ANY data.

  will only return when it has read or written ALL
the data.

  has nothing to do with the previous flags and
it controls whether the GUI blocks. 
	 * \param wxSocketFlags  
	*/

  void SetFlags(wxSocketFlags  flags ) ;
	/**
	 * \brief SetNotify specifies which socket events are to be sent to the event handler.
The   parameter may be combination of flags ORed together. The
following flags can be used:

\twocolwidtha{7cm}
 

For example:

 

In this example, the user will be notified about incoming socket data and
whenever the connection is closed.

For more information on socket events see  . 
	 * \param wxSocketEventFlags  
	*/

  void SetNotify(wxSocketEventFlags  flags ) ;
	/**
	 * \brief This function sets the default socket timeout in seconds. This timeout
applies to all IO calls, and also to the   family
of functions if you don't specify a wait interval. Initially, the default
timeout is 10 minutes. 
	 * \param int   
	*/

  void SetTimeout(int  seconds ) ;
	/**
	 * \brief  
	 * \param void *  
	 * \param wxUint32  
	*/

  wxSocketBase& Peek(void *  buffer , wxUint32  nbytes ) ;
	/**
	 * \brief  
	 * \param void *  
	 * \param wxUint32  
	*/

  wxSocketBase& Read(void *  buffer , wxUint32  nbytes ) ;
	/**
	 * \brief  
	 * \param void *  
	 * \param wxUint32  
	*/

  wxSocketBase& ReadMsg(void *  buffer , wxUint32  nbytes ) ;
	/**
	 * \brief  
	 * \param const void *  
	 * \param wxUint32  
	*/

  wxSocketBase& Unread(const void *  buffer , wxUint32  nbytes ) ;
	/**
	 * \brief  
	 * \param long  
	 * \param long  
	*/

  bool Wait(long seconds = -1, long millisecond = 0) ;
	/**
	 * \brief This function waits until the connection is lost. This may happen if
the peer gracefully closes the connection or if the connection breaks. 
	 * \param long  
	 * \param long  
	*/

  bool WaitForLost(long seconds = -1, long millisecond = 0) ;
	/**
	 * \brief  
	 * \param long  
	 * \param long  
	*/

  bool WaitForRead(long seconds = -1, long millisecond = 0) ;
	/**
	 * \brief  
	 * \param long  
	 * \param long  
	*/

  bool WaitForWrite(long seconds = -1, long millisecond = 0) ;
	/**
	 * \brief  
	 * \param const void *  
	 * \param wxUint32  
	*/

  wxSocketBase& Write(const void *  buffer , wxUint32  nbytes ) ;
	/**
	 * \brief  
	 * \param const void *  
	 * \param wxUint32  
	*/

  wxSocketBase& WriteMsg(const void *  buffer , wxUint32  nbytes ) ;
};


#endif
