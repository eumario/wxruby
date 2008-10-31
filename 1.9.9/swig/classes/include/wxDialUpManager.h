// wxDialUpManager.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDialUpManager_h_)
#define _wxDialUpManager_h_
class wxDialUpManager
{
public:
	/**
	 * \brief This function should create and return the object of the platform-specific
class derived from wxDialUpManager. You should delete the pointer when you are
done with it. 
	*/

  wxDialUpManager* Create() ;
	/**
	 * \brief Returns   if the dialup manager was initialized correctly. If this
function returns  , no other functions will work neither, so it is a
good idea to call this function and check its result before calling any other
wxDialUpManager methods 
	*/

  bool IsOk() const;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxDialUpManager() ;
	/**
	 * \brief This function is only implemented under Windows.

Fills the array with the names of all possible values for the first
parameter to   on this machine and returns
their number (may be 0). 
	 * \param wxArrayString&   
	*/

  size_t GetISPNames(wxArrayString&  names ) const;
	/**
	 * \brief Dial the given ISP, use   and   to authenticate.

The parameters are only used under Windows currently, for Unix you should use 
  to customize this
functions behaviour.

If no   is given, the function will select the default one
(proposing the user to choose among all connections defined on this machine)
and if no username and/or password are given, the function will try to do
without them, but will ask the user if really needed.

If   parameter is  , the function waits until the end of dialing
and returns   upon successful completion.

If   is  , the function only initiates the connection and
returns immediately - the result is reported via events (an event is sent
anyhow, but if dialing failed it will be a DISCONNECTED one). 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param bool   
	*/

  bool Dial(const wxString&  nameOfISP = wxEmptyString, const wxString&  username = wxEmptyString, const wxString&  password = wxEmptyString, bool  async = true) ;
	/**
	 * \brief Returns true if (async) dialing is in progress. 
	*/

  bool IsDialing() const;
	/**
	 * \brief Cancel dialing the number initiated with   
with async parameter equal to  .

Note that this won't result in DISCONNECTED event being sent. 
	*/

  bool CancelDialing() ;
	/**
	 * \brief Hang up the currently active dial up connection. 
	*/

  bool HangUp() ;
	/**
	 * \brief Returns   if the computer has a permanent network connection (i.e. is
on a LAN) and so there is no need to use Dial() function to go online.

  this functions tries to guess the result and it is not always
guaranteed to be correct, so it is better to ask user for
confirmation or give him a possibility to override it. 
	*/

  bool IsAlwaysOnline() const;
	/**
	 * \brief Returns   if the computer is connected to the network: under Windows,
this just means that a RAS connection exists, under Unix we check that
the &quot;well-known host&quot; (as specified by 
 ) is reachable. 
	*/

  bool IsOnline() const;
	/**
	 * \brief Sometimes the built-in logic for determining the online status may fail,
so, in general, the user should be allowed to override it. This function
allows to forcefully set the online status - whatever our internal
algorithm may think about it. 
	 * \param bool   
	*/

  void SetOnlineStatus(bool  isOnline = true) ;
	/**
	 * \brief Enable automatic checks for the connection status and sending of 
  events. The interval
parameter is only for Unix where we do the check manually and specifies how
often should we repeat the check (each minute by default). Under Windows, the
notification about the change of connection status is sent by the system and so
we don't do any polling and this parameter is ignored.

Returns   if couldn't set up automatic check for online status. 
	 * \param size_t   
	*/

  bool EnableAutoCheckOnlineStatus(size_t  nSeconds = 60) ;
	/**
	 * \brief Disable automatic check for connection status change - notice that the
  events won't be sent any more neither. 
	*/

  void DisableAutoCheckOnlineStatus() ;
	/**
	 * \brief This method is for Unix only.

Under Unix, the value of well-known host is used to check whether we're
connected to the internet. It is unused under Windows, but this function
is always safe to call. The default value is  . 
	 * \param const wxString&   
	 * \param int   
	*/

  void SetWellKnownHost(const wxString&  hostname , int  portno = 80) ;
	/**
	 * \brief This method is for Unix only.

Sets the commands to start up the network and to hang up again. 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

   SetConnectCommand(const wxString&  commandDial = wxT(wxT("/usr/bin/pon")), const wxString&  commandHangup = wxT(wxT("/usr/bin/poff"))) ;
};


#endif
