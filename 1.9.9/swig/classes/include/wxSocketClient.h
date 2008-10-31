// wxSocketClient.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSocketClient_h_)
#define _wxSocketClient_h_
class wxSocketClient : public wxSocketBase
{
public:
	/**
	 * \brief Constructor. 
	 * \param wxSocketFlags  
	*/

   wxSocketClient(wxSocketFlags flags = wxSOCKET_NONE) ;
	/**
	 * \brief Destructor. Please see  . 
	*/

  virtual  ~wxSocketClient() ;
	/**
	 * \brief  
	 * \param wxSockAddress&  
	 * \param bool  
	*/

  bool Connect(wxSockAddress&  address , bool wait = true) ;
	/**
	 * \brief  
	 * \param long  
	 * \param long  
	*/

  bool WaitOnConnect(long seconds = -1, long milliseconds = 0) ;
};


#endif
