// wxBitmapHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBitmapHandler_h_)
#define _wxBitmapHandler_h_
class wxBitmapHandler : public wxObject
{
public:
   wxBitmapHandler() ;
  virtual  ~wxBitmapHandler() ;
  virtual bool Create(wxBitmap*  bitmap , void*  data , int  type , int  width , int  height , int depth = -1) ;
  wxString GetName() const;
  wxString GetExtension() const;
  long GetType() const;
  bool LoadFile(wxBitmap*  bitmap , const wxString&  name , long  type ) ;
  bool SaveFile(wxBitmap*  bitmap , const wxString&  name , int  type , wxPalette*  palette = NULL) ;
  void SetName(const wxString&  name ) ;
  void SetExtension(const wxString&  extension ) ;
  void SetType(long  type ) ;
};


#endif
