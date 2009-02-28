// wxBitmapHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBitmapHandler_h_)
#define _wxBitmapHandler_h_
class wxBitmapHandler : public wxObject
{
public:
	/**
	 * \brief Default constructor. In your own default constructor, initialise the members
m_name, m_extension and m_type. 
	*/

   wxBitmapHandler() ;
	/**
	 * \brief Destroys the wxBitmapHandler object. 
	*/

  virtual  ~wxBitmapHandler() ;
	/**
	 * \brief Creates a bitmap from the given data, which can be of arbitrary type. The wxBitmap object   is
manipulated by this function. 
	 * \param wxBitmap*   
	 * \param void*  
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	*/

  virtual bool Create(wxBitmap*  bitmap , void*  data , int  type , int  width , int  height , int depth = -1) ;
	/**
	 * \brief Gets the name of this handler. 
	*/

  wxString GetName() const;
	/**
	 * \brief Gets the file extension associated with this handler. 
	*/

  wxString GetExtension() const;
	/**
	 * \brief Gets the bitmap type associated with this handler. 
	*/

  long GetType() const;
	/**
	 * \brief Loads a bitmap from a file or resource, putting the resulting data into  . 
	 * \param wxBitmap*   
	 * \param const wxString&  
	 * \param long  
	*/

  bool LoadFile(wxBitmap*  bitmap , const wxString&  name , long  type ) ;
	/**
	 * \brief Saves a bitmap in the named file. 
	 * \param wxBitmap*   
	 * \param const wxString&   
	 * \param int  
	 * \param wxPalette*   
	*/

  bool SaveFile(wxBitmap*  bitmap , const wxString&  name , int  type , wxPalette*  palette = NULL) ;
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
	 * \brief Sets the handler type. 
	 * \param long   
	*/

  void SetType(long  type ) ;
};


#endif
