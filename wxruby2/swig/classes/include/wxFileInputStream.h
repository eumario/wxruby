// wxFileInputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileInputStream_h_)
#define _wxFileInputStream_h_
class wxFileInputStream : public wxInputStream
{
public:
	/**
	 * \brief Opens the specified file using its   name in read-only mode. 
	 * \param const wxString&  
	*/

   wxFileInputStream(const wxString&  ifileName ) ;
	/**
	 * \brief Initializes a file stream in read-only mode using the file I/O object  . 
	 * \param wxFile&  
	*/

   wxFileInputStream(wxFile&  file ) ;
	/**
	 * \brief Initializes a file stream in read-only mode using the specified file descriptor. 
	 * \param int  
	*/

   wxFileInputStream(int  fd ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxFileInputStream() ;
	/**
	 * \brief Returns true if the stream is initialized and ready. 
	*/

  bool Ok() const;
};


#endif
