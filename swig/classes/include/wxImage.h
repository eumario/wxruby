// wxImage.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxImage_h_)
#define _wxImage_h_
class wxImage : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxImage() ;
	/**
	 * \brief Copy constructor. 
	 * \param const wxImage&   
	*/

   wxImage(const wxImage&  image ) ;
	/**
	 * \brief (Deprecated form, use  
instead.) Constructs an image from a platform-dependent bitmap. This preserves
mask information so that bitmaps and images can be converted back
and forth without loss in that respect. 
	 * \param const wxBitmap&  
	*/

  //wxImage(const wxBitmap&  bitmap );
	/**
	 * \brief Creates an image with the given width and height.  If   is true, the new image will be initialized to black.
Otherwise, the image data will be uninitialized. 
	 * \param int  
	 * \param int  
	 * \param bool  
	*/

  wxImage(int  width , int  height);
	/**
	 * \brief Creates an image from given data with the given width and height. If 
  is true, then wxImage will not delete the actual
image data in its destructor, otherwise it will free it by calling
 . 
	 * \param int  
	 * \param int  
	 * \param unsigned char*  
	 * \param bool  
	*/

   wxImage(int  width , int  height , unsigned char*  data , bool static_data = false) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param long  
	 * \param int  
	*/

   wxImage(const wxString&  name , long type = wxBITMAP_TYPE_ANY, int index = -1) ;
	/**
	 * \brief Loads an image from a file. 
	 * \param const wxString&   
	 * \param const wxString&  
	 * \param int  
	*/

   wxImage(const wxString&  name , const wxString&  mimetype , int index = -1) ;
	/**
	 * \brief  
	 * \param wxInputStream&   
	 * \param long  
	 * \param int  
	*/

   wxImage(wxInputStream&  stream , long type = wxBITMAP_TYPE_ANY, int index = -1) ;
	/**
	 * \brief  
	 * \param wxInputStream&   
	 * \param const wxString&  
	 * \param int  
	*/

   wxImage(wxInputStream&  stream , const wxString&  mimetype , int index = -1) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxImage() ;
	/**
	 * \brief Adds a handler to the end of the static list of format handlers. 
	 * \param wxImageHandler*  
	*/

  static void AddHandler(wxImageHandler*  handler ) ;
	/**
	 * \brief returns true if the current image handlers can read this file

\pythonnote{In wxPython this static method is named  .} 
	 * \param const wxString&  
	*/

  bool AddHandler(const wxString&  filename ) ;
	/**
	 * \brief Deletes all image handlers.

This function is called by wxWindows on exit. 
	*/

  static void CleanUpHandlers() ;
	/**
	 * \brief Computes the histogram of the image.   is a reference to 
wxImageHistogram object. wxImageHistogram is a specialization of 
  &quot;template&quot; and is defined as follows: 
	 * \param wxImageHistogram&   
	*/

  unsigned long ComputeHistogram(wxImageHistogram&  histogram ) const;
	/**
	 * \brief Deprecated, use equivalent  
(which takes wxImage and depth as its arguments) instead. 
	*/

  //wxBitmap ConvertToBitmap() const;
	/**
	 * \brief Returns monochromatic version of the image. The returned image has white
colour where the original has   colour and black colour 
everywhere else. 
	 * \param unsigned char  
	 * \param unsigned char  
	 * \param unsigned char  
	*/

  wxImage ConvertToMono(unsigned char  r , unsigned char  g , unsigned char  b ) const;
	/**
	 * \brief Returns an identical copy of the image. 
	*/

  wxImage Copy() const;
	/**
	 * \brief Creates a fresh image.  If   is true, the new image will be initialized to black.
Otherwise, the image data will be uninitialized. 
	 * \param int  
	 * \param int  
	 * \param bool  
	*/

  void Create(int  width , int  height );
	/**
	 * \brief Destroys the image data. 
	*/

  void Destroy();
	/**
	 * \brief Finds the first colour that is never used in the image. The search begins at
given initial colour and continues by increasing R, G and B components (in this
order) by 1 until an unused colour is found or the colour space exhausted. 
	 * \param unsigned char *  
	 * \param unsigned char *  
	 * \param unsigned char *  
	 * \param unsigned char  
	 * \param unsigned char  
	 * \param unsigned char  
	*/

  bool FindFirstUnusedColour(unsigned char *  r , unsigned char *  g , unsigned char *  b , unsigned char startR = 1, unsigned char startG = 0, unsigned char startB = 0) ;
	/**
	 * \brief Finds the handler with the given name. 
	 * \param const wxString&   
	*/

  static wxImageHandler* FindHandler(const wxString&  name ) ;
	/**
	 * \brief Finds the handler associated with the given extension and type. 
	 * \param const wxString&   
	 * \param long  
	*/

  static wxImageHandler* FindHandler(const wxString&  extension , long  imageType ) ;
	/**
	 * \brief Finds the handler associated with the given image type. 
	 * \param long   
	*/

  static wxImageHandler* FindHandler(long  imageType ) ;
	/**
	 * \brief Finds the handler associated with the given MIME type. 
	 * \param const wxString&   
	*/

  static wxImageHandler* FindHandler(const wxString&  mimetype ) ;
	/**
	 * \brief Iterates all registered wxImageHandler objects, and returns a string containing file extension masks
suitable for passing to file open/save dialog boxes. 
	*/

  static wxString GetImageExtWildcard() ;
	/**
	 * \brief Returns the alpha value for the given pixel. This function may only be called
for the images with alpha channel, use   to
check for this.

The returned value is the   of the image, i.e. the value of 0
corresponds to the transparent pixels while the value of 255 -- to the opaque
ones. 
	 * \param int  
	 * \param int  
	*/

  unsigned char GetAlpha(int  x , int  y ) const;
	/**
	 * \brief Returns pointer to the array storing the alpha values for this image. This
pointer is   for the images without the alpha channel. If the image
does have it, this pointer may be used to directly manipulate the alpha values
which are stored as the   ones. 
	*/

  unsigned char * GetAlpha() const;
	/**
	 * \brief Returns the blue intensity at the given coordinate. 
	 * \param int  
	 * \param int  
	*/

  unsigned char GetBlue(int  x , int  y ) const;
	/**
	 * \brief Returns the image data as an array. This is most often used when doing
direct image manipulation. The return value points to an array of
characters in RGBRGBRGB$\ldots$ format in the top-to-bottom, left-to-right
order, that is the first RGB triplet corresponds to the pixel $(0, 0)$, the
second one --- to $(0, 1)$ and so on.

You should not delete the returned pointer nor pass it to
 . 
	*/

  unsigned char* GetData() const;
	/**
	 * \brief Returns the green intensity at the given coordinate. 
	 * \param int  
	 * \param int  
	*/

  unsigned char GetGreen(int  x , int  y ) const;
	/**
	 * \brief  
	 * \param const wxString&  
	 * \param long  
	*/

  static int GetImageCount(const wxString&  filename , long type = wxBITMAP_TYPE_ANY) ;
	/**
	 * \brief If the image file contains more than one image and the image handler is capable 
of retrieving these individually, this function will return the number of
available images. 
	 * \param wxInputStream&  
	 * \param long  
	*/

  static int GetImageCount(wxInputStream&  stream , long type = wxBITMAP_TYPE_ANY) ;
	/**
	 * \brief Returns the static list of image format handlers. 
	*/

  static wxList& GetHandlers() ;
	/**
	 * \brief Gets the height of the image in pixels. 
	*/

  int GetHeight() const;
	/**
	 * \brief Gets the blue value of the mask colour. 
	*/

  unsigned char GetMaskBlue() const;
	/**
	 * \brief Gets the green value of the mask colour. 
	*/

  unsigned char GetMaskGreen() const;
	/**
	 * \brief Gets the red value of the mask colour. 
	*/

  unsigned char GetMaskRed() const;
	/**
	 * \brief Returns the palette associated with the image. Currently the palette is only
used when converting to wxBitmap under Windows.

Eventually wxImage handlers will set the palette if one exists in the image file. 
	*/

  const wxPalette& GetPalette() const;
	/**
	 * \brief Returns the red intensity at the given coordinate. 
	 * \param int  
	 * \param int  
	*/

  unsigned char GetRed(int  x , int  y ) const;
	/**
	 * \brief Returns a sub image of the current one as long as the rect belongs entirely to 
the image. 
	 * \param const wxRect&  
	*/

  wxImage GetSubImage(const wxRect&  rect ) const;
	/**
	 * \brief Gets the width of the image in pixels. 
	*/

  int GetWidth() const;
	/**
	 * \brief  
	*/

  bool HasAlpha() const;
	/**
	 * \brief Returns true if there is a mask active, false otherwise. 
	*/

  bool HasMask() const;
	/**
	 * \brief Gets a user-defined option. The function is case-insensitive to  .

For example, when saving as a JPEG file, the option   is
used, which is a number between 0 and 100 (0 is terrible, 100 is very good). 
	 * \param const wxString&  
	*/

  wxString GetOption(const wxString&  name ) const;
	/**
	 * \brief Gets a user-defined option as an integer. The function is case-insensitive to  . 
	 * \param const wxString&  
	*/

  int GetOptionInt(const wxString&  name ) const;
	/**
	 * \brief Returns true if the given option is present. The function is case-insensitive to  . 
	 * \param const wxString&  
	*/

  bool HasOption(const wxString&  name ) const;
	/**
	 * \brief  
	*/

  static void InitStandardHandlers() ;
	/**
	 * \brief Adds a handler at the start of the static list of format handlers. 
	 * \param wxImageHandler*  
	*/

  static void InsertHandler(wxImageHandler*  handler ) ;
	/**
	 * \brief  
	 * \param const wxString&  
	 * \param long  
	 * \param int  
	*/

  bool LoadFile(const wxString&  name , long type = wxBITMAP_TYPE_ANY, int index = -1) ;
	/**
	 * \brief Loads an image from a file. If no handler type is provided, the library will
try to autodetect the format. 
	 * \param const wxString&  
	 * \param const wxString&  
	 * \param int  
	*/

  bool LoadFile(const wxString&  name , const wxString&  mimetype , int index = -1) ;
	/**
	 * \brief  
	 * \param wxInputStream&  
	 * \param long  
	 * \param int  
	*/

  bool LoadFile(wxInputStream&  stream , long  type , int index = -1) ;
	/**
	 * \brief  
	 * \param wxInputStream&  
	 * \param const wxString&  
	 * \param int  
	*/

  bool LoadFile(wxInputStream&  stream , const wxString&  mimetype , int index = -1) ;
	/**
	 * \brief Returns true if image data is present. 
	*/

  bool Ok() const;
	/**
	 * \brief Finds the handler with the given name, and removes it. The handler
is not deleted. 
	 * \param const wxString&   
	*/

  static bool RemoveHandler(const wxString&  name ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param int  
	*/

  bool SaveFile(const wxString&  name , int  type ) const;
	/**
	 * \brief Saves an image in the named file. 
	 * \param const wxString&   
	 * \param const wxString&  
	*/

  bool SaveFile(const wxString&  name , const wxString&  mimetype ) const;
	/**
	 * \brief Saves an image in the named file. File type is determined from the extension of the
file name. Note that this function may fail if the extension is not recognized! You
can use one of the forms above to save images to files with non-standard extensions. 
	 * \param const wxString&   
	*/

  bool SaveFile(const wxString&  name ) const;
	/**
	 * \brief  
	 * \param wxOutputStream&   
	 * \param int  
	*/

  bool SaveFile(wxOutputStream&  stream , int  type ) const;
	/**
	 * \brief  
	 * \param wxOutputStream&   
	 * \param const wxString&  
	*/

  bool SaveFile(wxOutputStream&  stream , const wxString&  mimetype ) const;
	/**
	 * \brief Returns a mirrored copy of the image. The parameter  
indicates the orientation. 
	 * \param bool  
	*/

  wxImage Mirror(bool horizontally = true) const;
	/**
	 * \brief Replaces the colour specified by   by the colour  . 
	 * \param unsigned char  
	 * \param unsigned char  
	 * \param unsigned char  
	 * \param unsigned char  
	 * \param unsigned char  
	 * \param unsigned char  
	*/

  void Replace(unsigned char  r1 , unsigned char  g1 , unsigned char  b1 , unsigned char  r2 , unsigned char  g2 , unsigned char  b2 ) ;
	/**
	 * \brief Changes the size of the image in-place: after a call to this function, the
image will have the given width and height.

Returns the (modified) image itself. 
	 * \param int  
	 * \param int  
	*/

  wxImage & Rescale(int  width , int  height ) ;
	/**
	 * \brief Rotates the image about the given point, by   radians. Passing true
to   results in better image quality, but is slower. If the
image has a mask, then the mask colour is used for the uncovered pixels in the
rotated image background. Else, black (rgb 0, 0, 0) will be used.

Returns the rotated image, leaving this image intact. 
	 * \param double  
	 * \param const wxPoint&   
	 * \param bool  
	 * \param wxPoint*  
	*/

  wxImage Rotate(double  angle , const wxPoint&  rotationCentre , bool interpolating = true, wxPoint* offsetAfterRotation = NULL) ;
	/**
	 * \brief Returns a copy of the image rotated 90 degrees in the direction
indicated by  . 
	 * \param bool  
	*/

  wxImage Rotate90(bool clockwise = true) const;
	/**
	 * \brief Returns a scaled version of the image. This is also useful for
scaling bitmaps in general as the only other way to scale bitmaps
is to blit a wxMemoryDC into another wxMemoryDC.

It may be mentioned that the GTK port uses this function internally
to scale bitmaps when using mapping modes in wxDC. 

Example: 
	 * \param int  
	 * \param int  
	*/

  wxImage Scale(int  width , int  height ) const;
	/**
	 * \brief This function is similar to   and has similar
restrictions. The pointer passed to it may however be   in which case
the function will allocate the alpha array internally -- this is useful to add
alpha channel data to an image which doesn't have any. If the pointer is not 
 , it must have one byte for each image pixel and be allocated with 
 . wxImage takes ownership of the pointer and will free it. 
	 * \param unsigned char *  
	*/

  void SetAlpha(unsigned char * alpha = NULL) ;
	/**
	 * \brief Sets the alpha value for the given pixel. This function should only be called
if the image has alpha channel data, use   to
check for this. 
	 * \param int   
	 * \param int   
	 * \param unsigned char   
	*/

  void SetAlpha(int  x , int  y , unsigned char  alpha ) ;
	/**
	 * \brief Sets the image data without performing checks. The data given must have
the size (width&#42;height&#42;3) or results will be unexpected. Don't use this
method if you aren't sure you know what you are doing.

The data must have been allocated with  , {\large  } with
 .

After this call the pointer to the data is owned by the wxImage object,
that will be responsible for deleting it.
Do not pass to this function a pointer obtained through
 . 
	 * \param unsigned char*  
	*/

  void SetData(unsigned char* data ) ;
	/**
	 * \brief Specifies whether there is a mask or not. The area of the mask is determined by the current mask colour. 
	 * \param bool  
	*/

  void SetMask(bool hasMask = true) ;
	/**
	 * \brief Sets the mask colour for this image (and tells the image to use the mask). 
	 * \param unsigned char   
	 * \param unsigned char   
	 * \param unsigned char   
	*/

  void SetMaskColour(unsigned char  red , unsigned char  green , unsigned char  blue ) ;
	/**
	 * \brief Sets image's mask so that the pixels that have RGB value of  
in   will be masked in the image. This is done by first finding an
unused colour in the image, setting this colour as the mask colour and then
using this colour to draw all pixels in the image who corresponding pixel 
in   has given RGB value. 
	 * \param const wxImage&  
	 * \param unsigned char  
	 * \param unsigned char  
	 * \param unsigned char  
	*/

  bool SetMaskFromImage(const wxImage&  mask , unsigned char  mr , unsigned char  mg , unsigned char  mb ) ;
	/**
	 * \brief  
	 * \param const wxString&  
	 * \param const wxString&  
	*/

  void SetOption(const wxString&  name , const wxString&  value ) ;
	/**
	 * \brief Sets a user-defined option. The function is case-insensitive to  .

For example, when saving as a JPEG file, the option   is
used, which is a number between 0 and 100 (0 is terrible, 100 is very good). 
	 * \param const wxString&  
	 * \param int  
	*/

  void SetOption(const wxString&  name , int  value ) ;
	/**
	 * \brief Associates a palette with the image. The palette may be used when converting
wxImage to wxBitmap (MSW only at present) or in file save operations (none as yet). 
	 * \param const wxPalette&  
	*/

  void SetPalette(const wxPalette&  palette ) ;
	/**
	 * \brief Sets the pixel at the given coordinate. This routine performs bounds-checks
for the coordinate so it can be considered a safe way to manipulate the
data, but in some cases this might be too slow so that the data will have to
be set directly. In that case you will have to get access to the image data 
using the   method. 
	 * \param int   
	 * \param int   
	 * \param unsigned char   
	 * \param unsigned char   
	 * \param unsigned char   
	*/

  void SetRGB(int  x , int  y , unsigned char  red , unsigned char  green , unsigned char  blue ) ;
};


#endif
