// wxImageHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxImageHandler_h_)
#define _wxImageHandler_h_
class wxImageHandler : public wxObject
{
public:
	/**
	 * \brief Default constructor. In your own default constructor, initialise the members
m_name, m_extension and m_type. 
	*/

   wxImageHandler() ;
	/**
	 * \brief Destroys the wxImageHandler object. 
	*/

  virtual  ~wxImageHandler() ;
	/**
	 * \brief Gets the name of this handler. 
	*/

  wxString GetName() const;
	/**
	 * \brief Gets the file extension associated with this handler. 
	*/

  wxString GetExtension() const;
	/**
	 * \brief If the image file contains more than one image and the image handler is capable 
of retrieving these individually, this function will return the number of
available images. 
	 * \param wxInputStream&  
	*/

  int GetImageCount(wxInputStream&  stream ) ;
	/**
	 * \brief Gets the image type associated with this handler. 
	*/

  long GetType() const;
	/**
	 * \brief Gets the MIME type associated with this handler. 
	*/

  wxString GetMimeType() const;
	/**
	 * \brief  
	 * \param wxImage*   
	 * \param wxInputStream&  
	 * \param bool  
	 * \param int  
	*/

  bool LoadFile(wxImage*  image , wxInputStream&  stream , bool verbose = true, int index = 0) ;
	/**
	 * \brief  
	 * \param wxImage*   
	 * \param wxOutputStream&   
	*/

  bool SaveFile(wxImage*  image , wxOutputStream&  stream ) ;
	/**
	 * \brief Sets the handler name. 
	 * \param const wxString&   
	*/

  void SetName(const wxString&  name ) ;
	/**
	 * \brief Sets the handler extension. 
	 * \param const wxString&   
	*/

  void SetExtension(const wxString&  extension ) ;
	/**
	 * \brief Sets the handler MIME type. 
	 * \param const wxString&   
	*/

  void SetMimeType(const wxString&  mimetype ) ;
	/**
	 * \brief Sets the handler type. 
	 * \param long   
	*/

  void SetType(long  type ) ;
};


#endif
