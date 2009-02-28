// wxHTTP.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHTTP_h_)
#define _wxHTTP_h_
class wxHTTP : public wxProtocol
{
public:
	/**
	 * \brief Creates a new input stream on the the specified path. You can use all except the seek
functionality of wxStream. Seek isn't available on all streams. For example,
http or ftp streams doesn't deal with it. Other functions like Tell and SeekI
for this sort of stream.
You will be notified when the EOF is reached by an error. 
	 * \param const wxString&  
	*/

  wxInputStream * GetInputStream(const wxString&  path ) ;
	/**
	 * \brief It sets data of a field to be sent during the next request to the HTTP server. The field
name is specified by   and the content by  .
This is a low level function and it assumes that you know what you are doing. 
	 * \param const wxString&  
	 * \param const wxString&  
	*/

  void SetHeader(const wxString&  header , const wxString&  h_data ) ;
	/**
	 * \brief Returns the data attached with a field whose name is specified by  .
If the field doesn't exist, it will return an empty string and not a NULL string. 
	 * \param const wxString&  
	*/

  wxString GetHeader(const wxString&  header ) ;
};


#endif
