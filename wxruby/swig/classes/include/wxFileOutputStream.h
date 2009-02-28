// wxFileOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileOutputStream_h_)
#define _wxFileOutputStream_h_
class wxFileOutputStream : public wxOutputStream
{
public:
	/**
	 * \brief Creates a new file with   name and initializes the stream in
write-only mode. 
	 * \param const wxString&  
	*/

   wxFileOutputStream(const wxString&  ofileName ) ;
	/**
	 * \brief Initializes a file stream in write-only mode using the file I/O object  . 
	 * \param wxFile&  
	*/

   wxFileOutputStream(wxFile&  file ) ;
	/**
	 * \brief Initializes a file stream in write-only mode using the file descriptor  . 
	 * \param int  
	*/

   wxFileOutputStream(int  fd ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxFileOutputStream() ;
	/**
	 * \brief Returns true if the stream is initialized and ready. 
	*/

  bool Ok() const;
};


#endif
