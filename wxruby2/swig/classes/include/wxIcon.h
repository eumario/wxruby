// wxIcon.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxIcon_h_)
#define _wxIcon_h_
class wxIcon : public wxBitmap
{
public:
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  wxIcon(const wxString&  name , long  type = wxBITMAP_TYPE_ANY, int desiredWidth = -1, int desiredHeight = -1);
  ;
  void CopyFromBitmap(const wxBitmap&  bmp ) ;
  virtual  ~wxIcon() ;
  int GetDepth() const;
  int GetHeight() const;
  int GetWidth() const;
  bool LoadFile(const wxString&  name , wxBitmapType  type );
  bool Ok() const;
  bool SaveFile(const wxString&  name , wxBitmapType  type , wxPalette*  palette = NULL);
  void SetDepth(int  depth ) ;
  void SetHeight(int  height ) ;
  void SetOk(int  isOk ) ;
  void SetWidth(int  width ) ;
};


#endif
