// wxIcon.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxIcon_h_)
#define _wxIcon_h_
class wxIcon : public wxBitmap
{
public:

    wxIcon() { }

        // copy
    wxIcon(const wxIcon& icon) : wxGDIImage(icon) { Ref(icon); }

        // from raw data
/* This won't compile under Linux with wx 2.5.3
    wxIcon(const char bits[], int width, int height);
*/

        // from XPM data
    wxIcon(const char **data) { CreateIconFromXpm(data); }

    wxIcon(char **data) { CreateIconFromXpm((const char **)data); }

        // from resource/file
    wxIcon(const wxString& name,
           long type = wxBITMAP_TYPE_ICO_RESOURCE,
           int desiredWidth = -1, int desiredHeight = -1);

    wxIcon(const wxIconLocation& loc);

  ;
	/**
	 * \brief Copies   bitmap to this icon. Under MS Windows the bitmap
must have mask colour set.


 

\perlnote{Constructors supported by wxPerl are:\par
 
} 
	 * \param const wxBitmap&  
	*/

  void CopyFromBitmap(const wxBitmap&  bmp ) ;
	/**
	 * \brief Destroys the wxIcon object and possibly the underlying icon data.
Because reference counting is used, the icon may not actually be
destroyed at this point - only when the reference count is zero will the
data be deleted.

If the application omits to delete the icon explicitly, the icon will be
destroyed automatically by wxWindows when the application exits.

Do not delete an icon that is selected into a memory device context. 
	*/

  virtual  ~wxIcon() ;
	/**
	 * \brief Gets the colour depth of the icon. A value of 1 indicates a
monochrome icon. 
	*/

  int GetDepth() const;
	/**
	 * \brief Gets the height of the icon in pixels. 
	*/

  int GetHeight() const;
	/**
	 * \brief Gets the width of the icon in pixels. 
	*/

  int GetWidth() const;
	/**
	 * \brief Loads an icon from a file or resource. 
	 * \param const wxString&  
	 * \param long  
	*/

  bool LoadFile(const wxString&  name , wxBitmapType  type );
	/**
	 * \brief Returns true if icon data is present.

\begin{comment} 
	*/

  bool Ok() const;
	/**
	 * \brief Saves an icon in the named file. 
	 * \param const wxString&   
	 * \param int  
	 * \param wxPalette*   
	*/

  bool SaveFile(const wxString&  name , wxBitmapType  type , wxPalette*  palette = NULL);
	/**
	 * \brief Sets the depth member (does not affect the icon data). 
	 * \param int   
	*/

  void SetDepth(int  depth ) ;
	/**
	 * \brief Sets the height member (does not affect the icon data). 
	 * \param int   
	*/

  void SetHeight(int  height ) ;
	/**
	 * \brief Sets the validity member (does not affect the icon data). 
	 * \param int   
	*/

  void SetOk(int  isOk ) ;
	/**
	 * \brief Sets the width member (does not affect the icon data). 
	 * \param int   
	*/

  void SetWidth(int  width ) ;
};


#endif
