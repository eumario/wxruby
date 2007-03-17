// wxFFileInputStream.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFFileInputStream_h_)
#define _wxFFileInputStream_h_
class wxFFileInputStream : public wxInputStream
{
public:
	/**
	 * \brief Opens the specified file using its   name in read-only mode. 
	 * \param const wxString&  
	*/

   wxFFileInputStream(const wxString&  ifileName ) ;
	/**
	 * \brief Initializes a file stream in read-only mode using the file I/O object  . 
	 * \param wxFFile&  
	*/

   wxFFileInputStream(wxFFile&  file ) ;
	/**
	 * \brief Initializes a file stream in read-only mode using the specified file pointer  . 
	 * \param FILE *  
	*/

   wxFFileInputStream(FILE *  fp ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxFFileInputStream() ;
	/**
	 * \brief Returns true if the stream is initialized and ready. 
	*/

  bool Ok() const;
};


#endif
