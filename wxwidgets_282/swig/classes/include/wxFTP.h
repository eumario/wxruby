// wxFTP.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFTP_h_)
#define _wxFTP_h_
class wxFTP : public wxProtocol
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxFTP() ;
	/**
	 * \brief Destructor will close the connection if connected. 
	*/

  virtual  ~wxFTP() ;
	/**
	 * \brief Aborts the download currently in process, returns   if ok,   
if an error occured. 
	*/

  bool Abort() ;
	/**
	 * \brief Send the specified   to the FTP server.   specifies
the expected result. 
	 * \param const wxString&  
	 * \param char   
	*/

  bool CheckCommand(const wxString&  command , char  ret ) ;
	/**
	 * \brief Send the specified   to the FTP server and return the first
character of the return code. 
	 * \param const wxString&  
	*/

  char SendCommand(const wxString&  command ) ;
	/**
	 * \brief Returns the last command result, i.e. the full server reply for the last
command. 
	*/

  const wxString& GetLastResult() ;
	/**
	 * \brief Change the current FTP working directory.
Returns true if successful. 
	 * \param const wxString&  
	*/

  bool ChDir(const wxString&  dir ) ;
	/**
	 * \brief Create the specified directory in the current FTP working directory.
Returns true if successful. 
	 * \param const wxString&  
	*/

  bool MkDir(const wxString&  dir ) ;
	/**
	 * \brief Remove the specified directory from the current FTP working directory.
Returns true if successful. 
	 * \param const wxString&  
	*/

  bool RmDir(const wxString&  dir ) ;
	/**
	 * \brief Returns the current FTP working directory. 
	*/

  wxString Pwd() ;
	/**
	 * \brief Rename the specified   element to  . Returns true if successful. 
	 * \param const wxString&  
	 * \param const wxString&  
	*/

  bool Rename(const wxString&  src , const wxString&  dst ) ;
	/**
	 * \brief Delete the file specified by  . Returns true if successful. 
	 * \param const wxString&  
	*/

  bool RmFile(const wxString&  path ) ;
	/**
	 * \brief Sets the transfer mode to ASCII. It will be used for the next transfer. 
	*/

  bool SetAscii() ;
	/**
	 * \brief Sets the transfer mode to binary (IMAGE). It will be used for the next transfer. 
	*/

  bool SetBinary() ;
	/**
	 * \brief Sets the transfer mode to the specified one. It will be used for the next
transfer.

If this function is never called, binary transfer mode is used by default. 
	 * \param TransferMode   
	*/

  bool SetTransferMode(TransferMode  mode ) ;
	/**
	 * \brief Sets the user name to be sent to the FTP server to be allowed to log in.

\wxheading{Default value}

The default value of the user name is &quot;anonymous&quot;.

\wxheading{Remark}

This parameter can be included in a URL if you want to use the URL manager.
For example, you can use: &quot;ftp://a_user:a_password@a.host:service/a_directory/a_file&quot;
to specify a user and a password. 
	 * \param const wxString&  
	*/

  void SetUser(const wxString&  user ) ;
	/**
	 * \brief Sets the password to be sent to the FTP server to be allowed to log in.

\wxheading{Default value}

The default value of the user name is your email address. For example, it could
be &quot;username@userhost.domain&quot;. This password is built by getting the current
user name and the host name of the local machine from the system.

\wxheading{Remark}

This parameter can be included in a URL if you want to use the URL manager.
For example, you can use: &quot;ftp://a_user:a_password@a.host:service/a_directory/a_file&quot;
to specify a user and a password. 
	 * \param const wxString&  
	*/

  void SetPassword(const wxString&  passwd ) ;
	/**
	 * \brief Returns   if the given remote file exists,   otherwise. 
	 * \param const wxString&  
	*/

  bool FileExists(const wxString&  filename ) ;
	/**
	 * \brief Returns the file size in bytes or $-1$ if the file doesn't exist or the size
couldn't be determined. Notice that this size can be approximative size only
and shouldn't be used for allocating the buffer in which the remote file is
copied, for example. 
	 * \param const wxString&  
	*/

  int GetFileSize(const wxString&  filename ) ;
	/**
	 * \brief The GetList function is quite low-level. It returns the list of the files in
the current directory. The list can be filtered using the   string.
If   is empty (default), it will return all files in directory.

The form of the list can change from one peer system to another. For example,
for a UNIX peer system, it will look like this:

 

But on Windows system, it will look like this:

 

Return value: true if the file list was successfully retrieved, false
otherwise. 
	 * \param wxArrayString&   
	 * \param const wxString&  
	*/

  bool GetDirList(wxArrayString&  files , const wxString& wildcard = wxT("")) ;
	/**
	 * \brief This function returns the computer-parsable list of the files in the current
directory (optionally only of the files matching the  , all files
by default). This list always has the same format and contains one full
(including the directory path) file name per line.

Return value: true if the file list was successfully retrieved, false
otherwise. 
	 * \param wxArrayString&   
	 * \param const wxString&  
	*/

  bool GetFilesList(wxArrayString&  files , const wxString& wildcard = wxT("")) ;
	/**
	 * \brief Initializes an output stream to the specified  . The returned
stream has all but the seek functionality of wxStreams. When the user finishes
writing data, he has to delete the stream to close it. 
	 * \param const wxString&  
	*/

  wxOutputStream * GetOutputStream(const wxString&  file ) ;
	/**
	 * \brief Creates a new input stream on the the specified path. You can use all but the seek
functionality of wxStream. Seek isn't available on all streams. For example,
http or ftp streams do not deal with it. Other functions like Tell
are not available for this sort of stream, at present.
You will be notified when the EOF is reached by an error. 
	 * \param const wxString&  
	*/

  wxInputStream * GetInputStream(const wxString&  path ) ;
};


#endif
