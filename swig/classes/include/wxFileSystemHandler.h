// wxFileSystemHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileSystemHandler_h_)
#define _wxFileSystemHandler_h_
class wxFileSystemHandler : public wxObject
{
public:
   wxFileSystemHandler() ;
  virtual bool CanOpen(const wxString&  location ) ;
  wxString GetAnchor(const wxString&  location ) const;
  wxString GetLeftLocation(const wxString&  location ) const;
  wxString GetMimeTypeFromExt(const wxString&  location ) ;
  wxString GetProtocol(const wxString&  location ) const;
  wxString GetRightLocation(const wxString&  location ) const;
  virtual wxString FindFirst(const wxString&  wildcard , int  flags = 0) ;
  virtual wxString FindNext() ;
  virtual wxFSFile* OpenFile(wxFileSystem&  fs , const wxString&  location ) ;
};


#endif
