// wxSocketServer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSocketServer_h_)
#define _wxSocketServer_h_
class wxSocketServer : public wxSocketBase
{
public:
	/**
	 * \brief Constructs a new server and tries to bind to the specified  .
Before trying to accept new connections, test whether it succeeded with 
 . 
	 * \param wxSockAddress&  
	 * \param wxSocketFlags  
	*/

   wxSocketServer(wxSockAddress&  address , wxSocketFlags flags = wxSOCKET_NONE) ;
	/**
	 * \brief Destructor (it doesn't close the accepted connections). 
	*/

  virtual  ~wxSocketServer() ;
	/**
	 * \brief  
	 * \param bool  
	*/

  wxSocketBase * Accept(bool wait = true) ;
	/**
	 * \brief Accept an incoming connection using the specified socket object. 
	 * \param wxSocketBase&  
	 * \param bool  
	*/

  bool AcceptWith(wxSocketBase&  socket , bool wait = true) ;
	/**
	 * \brief  
	 * \param long  
	 * \param long  
	*/

  bool WaitForAccept(long seconds = -1, long millisecond = 0) ;
};


#endif
