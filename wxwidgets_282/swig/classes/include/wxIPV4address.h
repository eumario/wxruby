// wxIPV4address.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxIPV4address_h_)
#define _wxIPV4address_h_
class wxIPV4address : public wxSockAddress
{
public:
	/**
	 * \brief Set the address to  , which can be a host name
or an IP-style address in dot notation (a.b.c.d) 
	 * \param const wxString&  
	*/

  bool Hostname(const wxString&  hostname ) ;
	/**
	 * \brief Returns the hostname which matches the IP address. 
	*/

  wxString Hostname() ;
	/**
	 * \brief Set the port to that corresponding to the specified  . 
	 * \param const wxString&  
	*/

  bool Service(const wxString&  service ) ;
	/**
	 * \brief Set the port to that corresponding to the specified  . 
	 * \param unsigned short  
	*/

  bool Service(unsigned short  service ) ;
	/**
	 * \brief Returns the current service. 
	*/

  unsigned short Service() ;
	/**
	 * \brief Set address to any of the addresses of the current machine. Whenever
possible, use this function instead of  ,
as this correctly handles multi-homed hosts and avoids other small
problems. Internally, this is the same as setting the IP address
to  . 
	*/

  bool AnyAddress() ;
	/**
	 * \brief Set address to localhost (127.0.0.1). Whenever possible, use the 
 ,
function instead of this one, as this will correctly handle multi-homed
hosts and avoid other small problems. 
	*/

  bool LocalHost() ;
};


#endif
