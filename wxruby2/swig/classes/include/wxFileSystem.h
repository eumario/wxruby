// wxFileSystem.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileSystem_h_)
#define _wxFileSystem_h_
class wxFileSystem : public wxObject
{
public:
   wxFileSystem() ;
  static void AddHandler(wxFileSystemHandler  *handler ) ;
  void ChangePathTo(const wxString&  location , bool  is_dir = false) ;
  wxString GetPath() ;
  static wxString FileNameToURL(wxFileName  filename ) ;
  wxString FindFirst(const wxString&  wildcard , int  flags = 0) ;
  wxString FindNext() ;
  wxFSFile* OpenFile(const wxString&  location ) ;
  static wxFileName URLToFileName(const wxString&  url ) ;
};


#endif
