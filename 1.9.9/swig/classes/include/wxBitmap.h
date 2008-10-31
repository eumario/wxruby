// wxBitmap.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBitmap_h_)
#define _wxBitmap_h_
class wxBitmap : public wxGDIObject
{
public:
   wxBitmap() ;
   wxBitmap(const wxBitmap&  bitmap ) ;
   wxBitmap(int  width , int  height , int depth = -1) ;
   wxBitmap(const char**  bits ) ;
   wxBitmap(wxString&  name , wxBitmapType  type=wxBITMAP_TYPE_XPM );
   wxBitmap(const wxImage&  img , int depth = -1) ;
  virtual  ~wxBitmap() ;
  static void AddHandler(wxBitmapHandler*  handler ) ;
  static void CleanUpHandlers() ;
  wxImage ConvertToImage() ;
  bool CopyFromIcon(const wxIcon&  icon ) ;
  virtual bool Create(int  width , int  height , int depth = -1) ;
  static wxBitmapHandler* FindHandler(const wxString&  name ) ;
  static wxBitmapHandler* FindHandler(const wxString&  extension , long  bitmapType ) ;
  static wxBitmapHandler* FindHandler(long  bitmapType ) ;
  int GetDepth() const;
  static wxList& GetHandlers() ;
  int GetHeight() const;
  wxPalette* GetPalette() const;
  wxMask* GetMask() const;
  int GetWidth() const;
  wxBitmap GetSubBitmap(const wxRect& rect ) const;
  static void InitStandardHandlers() ;
  static void InsertHandler(wxBitmapHandler*  handler ) ;
  bool LoadFile(const wxString&  name , wxBitmapType  type );
  bool IsOk() const;
  static bool RemoveHandler(const wxString&  name ) ;
  bool SaveFile(const wxString&  name , wxBitmapType  type , wxPalette*  palette = NULL);
  void SetDepth(int  depth ) ;
  void SetHeight(int  height ) ;
  void SetMask(wxMask*  mask ) ;
  void SetPalette(const wxPalette&  palette ) ;
  void SetWidth(int  width ) ;
};


#endif
