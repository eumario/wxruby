// wxImageHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxImageHandler_h_)
#define _wxImageHandler_h_
class wxImageHandler : public wxObject
{
public:
   wxImageHandler() ;
  virtual  ~wxImageHandler() ;
  wxString GetName() const;
  wxString GetExtension() const;
  int GetImageCount(wxInputStream&  stream ) ;
  long GetType() const;
  wxString GetMimeType() const;
  bool LoadFile(wxImage*  image , wxInputStream&  stream , bool verbose = true, int index = 0) ;
  bool SaveFile(wxImage*  image , wxOutputStream&  stream ) ;
  void SetName(const wxString&  name ) ;
  void SetExtension(const wxString&  extension ) ;
  void SetMimeType(const wxString&  mimetype ) ;
  void SetType(long  type ) ;
};


#endif
