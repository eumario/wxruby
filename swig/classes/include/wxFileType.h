// wxFileType.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileType_h_)
#define _wxFileType_h_
class wxFileType
{
public:
   wxFileType() ;
  virtual  ~wxFileType() ;
  bool GetMimeType(wxString*  mimeType ) ;
  bool GetMimeTypes(wxArrayString&  mimeTypes ) ;
  bool GetExtensions(wxArrayString&  extensions ) ;
  bool GetIcon(wxIconLocation *  iconLoc ) ;
  bool GetDescription(wxString*  desc ) ;
  bool GetOpenCommand(wxString*  command , MessageParameters&  params ) ;
  wxString GetOpenCommand(const wxString&  filename ) ;
  bool GetPrintCommand(wxString*  command , MessageParameters&  params ) ;
  static wxString ExpandCommand(const wxString&  command , MessageParameters&  params ) ;
};


#endif
