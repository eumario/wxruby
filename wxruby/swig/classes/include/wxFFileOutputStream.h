// wxFFileOutputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFFileOutputStream_h_)
#define _wxFFileOutputStream_h_
class wxFFileOutputStream : public wxOutputStream
{
public:
	/**
	 * \brief Creates a new file with   name and initializes the stream in
write-only mode. 
	 * \param const wxString&  
	*/

   wxFFileOutputStream(const wxString&  ofileName ) ;
	/**
	 * \brief Initializes a file stream in write-only mode using the file I/O object  . 
	 * \param wxFFile&  
	*/

   wxFFileOutputStream(wxFFile&  file ) ;
	/**
	 * \brief Initializes a file stream in write-only mode using the file descriptor  . 
	 * \param FILE *  
	*/

   wxFFileOutputStream(FILE *  fp ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxFFileOutputStream() ;
	/**
	 * \brief Returns true if the stream is initialized and ready. 
	*/

  bool Ok() const;
};


#endif
