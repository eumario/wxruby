// wxBitmap.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBitmap_h_)
#define _wxBitmap_h_
class wxBitmap : public wxGDIObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxBitmap() ;
	/**
	 * \brief Copy constructor. 
	 * \param const wxBitmap&   
	*/

   wxBitmap(const wxBitmap&  bitmap ) ;
	/**
	 * \brief Creates a bitmap from the given data which is interpreted in platform-dependent
manner. 
	 * \param void*  
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	*/

  ;
	/**
	 * \brief Creates a bitmap from an array of bits.

You should only use this function for monochrome bitmaps (  1) in
portable programs: in this case the   parameter should contain an XBM
image.

For other bit depths, the behaviour is platform dependent: under Windows, the
data is passed without any changes to the underlying   API.
Under other platforms, only monochrome bitmaps may be created using this
constructor and   should be used for creating colour
bitmaps from static data. 
	 * \param const char  
	 * \param int  
	 * \param int  
	 * \param int  
	*/

  //wxBitmap(const char  bits[] , int  width , int  height , int depth = 1);
	/**
	 * \brief Creates a new bitmap. A depth of -1 indicates the depth of the current screen
or visual. Some platforms only support 1 for monochrome and -1 for the current
colour setting. 
	 * \param int  
	 * \param int  
	 * \param int  
	*/

   wxBitmap(int  width , int  height , int depth = -1) ;
	/**
	 * \brief Creates a bitmap from XPM data. 
	 * \param const char**  
	*/

   wxBitmap(const char**  bits ) ;
	/**
	 * \brief Loads a bitmap from a file or resource. 
	 * \param const wxString&   
	 * \param long  
	*/

  wxBitmap(wxString&  name , wxBitmapType  type=wxBITMAP_TYPE_XPM );
	/**
	 * \brief  
	 * \param const wxImage&  
	 * \param int  
	*/

   wxBitmap(const wxImage&  img , int depth = -1) ;
	/**
	 * \brief Destroys the wxBitmap object and possibly the underlying bitmap data.
Because reference counting is used, the bitmap may not actually be
destroyed at this point - only when the reference count is zero will the
data be deleted.

If the application omits to delete the bitmap explicitly, the bitmap will be
destroyed automatically by wxWindows when the application exits.

Do not delete a bitmap that is selected into a memory device context. 
	*/

  virtual  ~wxBitmap() ;
	/**
	 * \brief Adds a handler to the end of the static list of format handlers. 
	 * \param wxBitmapHandler*  
	*/

  static void AddHandler(wxBitmapHandler*  handler ) ;
	/**
	 * \brief Deletes all bitmap handlers.

This function is called by wxWindows on exit. 
	*/

  static void CleanUpHandlers() ;
	/**
	 * \brief Creates an image from a platform-dependent bitmap. This preserves
mask information so that bitmaps and images can be converted back
and forth without loss in that respect. 
	*/

  wxImage ConvertToImage() ;
	/**
	 * \brief Creates the bitmap from an icon. 
	 * \param const wxIcon&  
	*/

  bool CopyFromIcon(const wxIcon&  icon ) ;
	/**
	 * \brief Creates a fresh bitmap. If the final argument is omitted, the display depth of
the screen is used. 
	 * \param int  
	 * \param int  
	 * \param int  
	*/

  virtual bool Create(int  width , int  height , int depth = -1) ;
	/**
	 * \brief Creates a bitmap from the given data, which can be of arbitrary type. 
	 * \param void*  
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	*/

  ;
	/**
	 * \brief Finds the handler with the given name. 
	 * \param const wxString&   
	*/

  static wxBitmapHandler* FindHandler(const wxString&  name ) ;
	/**
	 * \brief Finds the handler associated with the given extension and type. 
	 * \param const wxString&   
	 * \param long  
	*/

  static wxBitmapHandler* FindHandler(const wxString&  extension , long  bitmapType ) ;
	/**
	 * \brief Finds the handler associated with the given bitmap type. 
	 * \param long   
	*/

  static wxBitmapHandler* FindHandler(long  bitmapType ) ;
	/**
	 * \brief Gets the colour depth of the bitmap. A value of 1 indicates a
monochrome bitmap. 
	*/

  int GetDepth() const;
	/**
	 * \brief Returns the static list of bitmap format handlers. 
	*/

  static wxList& GetHandlers() ;
	/**
	 * \brief Gets the height of the bitmap in pixels. 
	*/

  int GetHeight() const;
	/**
	 * \brief Gets the associated palette (if any) which may have been loaded from a file
or set for the bitmap. 
	*/

  wxPalette* GetPalette() const;
	/**
	 * \brief  
	*/

  wxMask* GetMask() const;
	/**
	 * \brief Gets the width of the bitmap in pixels. 
	*/

  int GetWidth() const;
	/**
	 * \brief Returns a sub bitmap of the current one as long as the rect belongs entirely to
the bitmap. This function preserves bit depth and mask information. 
	 * \param const wxRect&  
	*/

  wxBitmap GetSubBitmap(const wxRect& rect ) const;
	/**
	 * \brief Adds the standard bitmap format handlers, which, depending on wxWindows
configuration, can be handlers for Windows bitmap, Windows bitmap resource, and XPM.

This function is called by wxWindows on startup. 
	*/

  static void InitStandardHandlers() ;
	/**
	 * \brief Adds a handler at the start of the static list of format handlers. 
	 * \param wxBitmapHandler*  
	*/

  static void InsertHandler(wxBitmapHandler*  handler ) ;
	/**
	 * \brief Loads a bitmap from a file or resource. 
	 * \param const wxString&  
	 * \param long  
	*/

  bool LoadFile(const wxString&  name , wxBitmapType  type );
	/**
	 * \brief Returns true if bitmap data is present. 
	*/

  bool Ok() const;
	/**
	 * \brief Finds the handler with the given name, and removes it. The handler
is not deleted. 
	 * \param const wxString&   
	*/

  static bool RemoveHandler(const wxString&  name ) ;
	/**
	 * \brief Saves a bitmap in the named file. 
	 * \param const wxString&   
	 * \param int  
	 * \param wxPalette*   
	*/

  bool SaveFile(const wxString&  name , wxBitmapType  type , wxPalette*  palette = NULL);
	/**
	 * \brief Sets the depth member (does not affect the bitmap data). 
	 * \param int   
	*/

  void SetDepth(int  depth ) ;
	/**
	 * \brief Sets the height member (does not affect the bitmap data). 
	 * \param int   
	*/

  void SetHeight(int  height ) ;
	/**
	 * \brief  
	 * \param wxMask*   
	*/

  void SetMask(wxMask*  mask ) ;
	/**
	 * \brief Sets the associated palette. 
	 * \param const wxPalette&   
	*/

  void SetPalette(const wxPalette&  palette ) ;
	/**
	 * \brief Sets the width member (does not affect the bitmap data). 
	 * \param int   
	*/

  void SetWidth(int  width ) ;
};


#endif
