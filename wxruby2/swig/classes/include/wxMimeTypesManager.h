// wxMimeTypesManager.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMimeTypesManager_h_)
#define _wxMimeTypesManager_h_
class wxMimeTypesManager
{
public:
   wxMimeTypesManager() ;
  virtual  ~wxMimeTypesManager() ;
  void AddFallbacks(const wxFileTypeInfo * fallbacks ) ;
  wxFileType* GetFileTypeFromExtension(const wxString&  extension ) ;
  wxFileType* GetFileTypeFromMimeType(const wxString&  mimeType ) ;
  bool IsOfType(const wxString&  mimeType , const wxString&  wildcard ) ;
  bool ReadMailcap(const wxString&  filename , bool fallback = false) ;
  bool ReadMimeTypes(const wxString&  filename ) ;
};


#endif
