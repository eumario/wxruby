// wxImage.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxImage_h_)
#define _wxImage_h_
class wxImage : public wxObject
{
public:
   wxImage() ;
   wxImage(const wxImage&  image ) ;
   wxImage(const wxBitmap&  bitmap ) ;
   wxImage(int  width , int  height , bool clear = true) ;
   wxImage(int  width , int  height , unsigned char*  data , bool static_data = false) ;
   wxImage(const wxString&  name , long type = wxBITMAP_TYPE_ANY, int index = -1) ;
   wxImage(const wxString&  name , const wxString&  mimetype , int index = -1) ;
   wxImage(wxInputStream&  stream , long type = wxBITMAP_TYPE_ANY, int index = -1) ;
   wxImage(wxInputStream&  stream , const wxString&  mimetype , int index = -1) ;
  virtual  ~wxImage() ;
  static void AddHandler(wxImageHandler*  handler ) ;
  bool AddHandler(const wxString&  filename ) ;
  static void CleanUpHandlers() ;
  unsigned long ComputeHistogram(wxImageHistogram&  histogram ) const;
  wxBitmap ConvertToBitmap() const;
  wxImage ConvertToMono(unsigned char  r , unsigned char  g , unsigned char  b ) const;
  wxImage Copy() const;
  bool Create(int  width , int  height , bool clear = true) ;
  bool Destroy() ;
  bool FindFirstUnusedColour(unsigned char *  r , unsigned char *  g , unsigned char *  b , unsigned char startR = 1, unsigned char startG = 0, unsigned char startB = 0) ;
  static wxImageHandler* FindHandler(const wxString&  name ) ;
  static wxImageHandler* FindHandler(const wxString&  extension , long  imageType ) ;
  static wxImageHandler* FindHandler(long  imageType ) ;
  static wxImageHandler* FindHandler(const wxString&  mimetype ) ;
  static wxString GetImageExtWildcard() ;
  unsigned char GetAlpha(int  x , int  y ) const;
  unsigned char * GetAlpha() const;
  unsigned char GetBlue(int  x , int  y ) const;
  unsigned char* GetData() const;
  unsigned char GetGreen(int  x , int  y ) const;
  static int GetImageCount(const wxString&  filename , long type = wxBITMAP_TYPE_ANY) ;
  static int GetImageCount(wxInputStream&  stream , long type = wxBITMAP_TYPE_ANY) ;
  static wxList& GetHandlers() ;
  int GetHeight() const;
  unsigned char GetMaskBlue() const;
  unsigned char GetMaskGreen() const;
  unsigned char GetMaskRed() const;
  const wxPalette& GetPalette() const;
  unsigned char GetRed(int  x , int  y ) const;
  wxImage GetSubImage(const wxRect&  rect ) const;
  int GetWidth() const;
  bool HasAlpha() const;
  bool HasMask() const;
  wxString GetOption(const wxString&  name ) const;
  int GetOptionInt(const wxString&  name ) const;
  bool HasOption(const wxString&  name ) const;
  static void InitStandardHandlers() ;
  static void InsertHandler(wxImageHandler*  handler ) ;
  bool LoadFile(const wxString&  name , long type = wxBITMAP_TYPE_ANY, int index = -1) ;
  bool LoadFile(const wxString&  name , const wxString&  mimetype , int index = -1) ;
  bool LoadFile(wxInputStream&  stream , long  type , int index = -1) ;
  bool LoadFile(wxInputStream&  stream , const wxString&  mimetype , int index = -1) ;
  bool Ok() const;
  static bool RemoveHandler(const wxString&  name ) ;
  bool SaveFile(const wxString&  name , int  type ) const;
  bool SaveFile(const wxString&  name , const wxString&  mimetype ) const;
  bool SaveFile(const wxString&  name ) const;
  bool SaveFile(wxOutputStream&  stream , int  type ) const;
  bool SaveFile(wxOutputStream&  stream , const wxString&  mimetype ) const;
  wxImage Mirror(bool horizontally = true) const;
  void Replace(unsigned char  r1 , unsigned char  g1 , unsigned char  b1 , unsigned char  r2 , unsigned char  g2 , unsigned char  b2 ) ;
  wxImage & Rescale(int  width , int  height ) ;
  wxImage Rotate(double  angle , const wxPoint&  rotationCentre , bool interpolating = true, wxPoint* offsetAfterRotation = NULL) ;
  wxImage Rotate90(bool clockwise = true) const;
  wxImage Scale(int  width , int  height ) const;
  void SetAlpha(unsigned char * alpha = NULL) ;
  void SetAlpha(int  x , int  y , unsigned char  alpha ) ;
  void SetData(unsigned char* data ) ;
  void SetMask(bool hasMask = true) ;
  void SetMaskColour(unsigned char  red , unsigned char  green , unsigned char  blue ) ;
  bool SetMaskFromImage(const wxImage&  mask , unsigned char  mr , unsigned char  mg , unsigned char  mb ) ;
  void SetOption(const wxString&  name , const wxString&  value ) ;
  void SetOption(const wxString&  name , int  value ) ;
  void SetPalette(const wxPalette&  palette ) ;
  void SetRGB(int  x , int  y , unsigned char  red , unsigned char  green , unsigned char  blue ) ;
};


#endif
