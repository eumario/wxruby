// wxSockAddress.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSockAddress_h_)
#define _wxSockAddress_h_
class wxSockAddress : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxSockAddress() ;
	/**
	 * \brief Default destructor. 
	*/

  virtual  ~wxSockAddress() ;
	/**
	 * \brief Delete all informations about the address. 
	*/

  void Clear() ;
	/**
	 * \brief Returns the length of the socket address. 
	*/

  int SockAddrLen() ;
};


#endif
